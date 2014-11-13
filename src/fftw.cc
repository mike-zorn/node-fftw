#include <nan.h>
#include <fftw3.h>
#include "complex.h"
#include "plan.h"
#include "planner_dft_1d.h"

using namespace v8;


NAN_METHOD(PlanDft1d) {
  NanScope();

  Local<Object> opts = args[0].As<Object>();
  Local<Function> callback = args[1].As<Function>();
  
  NanCallback* nanCallback = new NanCallback(callback);

  int size = opts->Get(NanNew<String>("size")).As<Number>()->Value();

  PlannerDft1d* planner = new PlannerDft1d(nanCallback, 
      size, 
      //TODO don't hard code these
      FFTW_FORWARD, 
      FFTW_ESTIMATE);
  
  NanAsyncQueueWorker(planner);

  NanReturnUndefined();
}

void Init(Handle<Object> exports) {
  Complex::Init();
  Plan::Init();

  exports->Set(NanNew("plan_dft_1d"), 
      NanNew<FunctionTemplate>(PlanDft1d)->GetFunction());
}

NODE_MODULE(fftw, Init)
