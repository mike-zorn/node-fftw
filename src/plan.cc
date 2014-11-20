#include "complex.h"
#include "plan.h"
#include "executor.h"
#include <node.h>
#include <nan.h>

using namespace v8;

static Persistent<FunctionTemplate> plan_constructor;

Plan::Plan() : 
  executed(false)
{ }

Plan::~Plan() {
  if(!executed) {
    fftw_destroy_plan(this->plan);
    fftw_free(this->in);
    fftw_free(this->out);
  }
}

void Plan::Init() {
  Local<FunctionTemplate> tpl = 
    NanNew<FunctionTemplate>(Plan::New);
  NanAssignPersistent(plan_constructor, tpl);
  tpl->SetClassName(NanNew("Plan"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  NODE_SET_PROTOTYPE_METHOD(tpl, "execute", Plan::Execute);

}

void Plan::LoadInput(Local<Array> data) {
  fftw_complex* input = this->in;

  for(int i = 0; i < this->size; i++) {
    Local<Value> datum = data->Get(i);
    if(datum->IsNumber()) {
      input[i][0] = datum.As<Number>()->Value();
      input[i][1] = 0;
    }
    else {
      Local<Object> comp = datum.As<Object>();
      input[i][0] = comp->Get(NanNew<String>("real")).As<Number>()->Value();
      input[i][1] = comp->Get(NanNew<String>("imag")).As<Number>()->Value();
    }
  }
}

Handle<Value> Plan::NewInstance(
    fftw_complex* in, 
    fftw_complex* out, 
    fftw_plan plan,
    int size
  ) {

  NanEscapableScope();

  Local<FunctionTemplate> constructorHandle =
      NanNew<FunctionTemplate>(plan_constructor);

  Handle<Value> argv[0] = { };
  Local<Object> instance = 
      constructorHandle->GetFunction()->NewInstance(0, argv);
  
  Plan* unwrapped = ObjectWrap::Unwrap<Plan>(instance);
  unwrapped->in = in;
  unwrapped->out = out;
  unwrapped->plan = plan;
  unwrapped->size = size;

  return NanEscapeScope(instance);
}

NAN_METHOD(Plan::New) {
  NanScope();

  Plan* plan = new Plan();
  plan->Wrap(args.This());

  NanReturnValue(args.This());
}

NAN_METHOD(Plan::Execute) {
  NanScope();

  Plan* plan = ObjectWrap::Unwrap<Plan>(args.Holder());

  if(!plan->executed) {
    plan->executed = true;

    Local<Array> input = args[0].As<Array>();
    Local<Function> callback = args[1].As<Function>();
    NanCallback* nanCallback = new NanCallback(callback);

    plan->LoadInput(input);
    Executor* executor = new Executor(
        nanCallback, 
        plan->in, 
        plan->out, 
        plan->plan, 
        plan->size);
    NanAsyncQueueWorker(executor);

    NanReturnUndefined();
  }
  else {
    NanThrowError("plan may only be executed once");
  }
}
