#include "complex.h"
#include <node.h>
#include <nan.h>

static v8::Persistent<v8::FunctionTemplate> plan_constructor;

Plan::Plan(fftw_complex* in, fftw_complex* out, fftw_plan* plan) : 
  executed(false);
{ }

Plan::~Plan() {
  if(!executed) {
    //TODO destroy plan and free memory
  }
}

void Complex::Init() {
  v8::Local<v8::FunctionTemplate> tpl = 
    NanNew<v8::FunctionTemplate>(Plan::New);
  NanAssignPersistent(plan_constructor, tpl);
  tpl->SetClassName(NanNew("Plan"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  NODE_SET_PROTOTYPE_METHOD(tpl, "execute", Plan::Execute);

}

v8::Handle<v8::Value> Plan::NewInstance(
    fftw_complex* in, 
    fftw_complex* out, 
    fftw_plan* plan
  ) {

  NanEscapableScope();

  v8::Local<v8::FunctionTemplate> constructorHandle =
      NanNew<v8::FunctionTemplate>(complex_constructor);

  //FIXME
  v8::Handle<v8::Value> argv[2] = { real, imag };
  v8::Local<v8::Object> instance = 
      constructorHandle->GetFunction()->NewInstance(2, argv);
  //potentially make this work by modifying the created plan.

  return NanEscapeScope(instance);
}

NAN_METHOD(Plan::New) {
  NanScope();

  Plan* plan = new plan(
      //FIXME
      //args[0].As<v8::Number>()->Value(), 
      //args[1].As<v8::Number>()->Value()
  );
  complex->Wrap(args.This());

  NanReturnValue(args.This());
}

NAN_METHOD(Plan::Execute) {
  NanScope();

  if(!this->executed) {
    this->executed = true;

    Local<Function> callback = args[1].As<Function>();
    NanCallback* nanCallback = new NanCallback(callback);

    Executor* executor(
        nanCallback, 
        this->in, 
        this->out, 
        this->plan, 
        this->size);
  }
  else {
    //TODO throw something
  }
}
