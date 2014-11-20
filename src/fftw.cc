#include <nan.h>
#include <fftw3.h>
#include <string>
#include "complex.h"
#include "plan.h"
#include "planner_dft_1d.h"

using namespace v8;

int GetSign(Local<Object> opts) {
  std::string sign(*String::Utf8Value(opts->Get
        (NanNew<String>("sign"))));

  if(sign == "backward") {
    return FFTW_BACKWARD;
  }
  else if(sign == "forward") {
    return FFTW_FORWARD;
  }
  else if(sign == "") {
    return FFTW_FORWARD;
  }
  else {
    NanThrowRangeError("sign must be one of backward or forward");
  }
}

unsigned GetRigor(Local<Object> opts) {
  std::string rigor(*String::Utf8Value(opts->Get
        (NanNew<String>("rigor"))));

  if(rigor == "estimate") {
    return FFTW_ESTIMATE;
  }
  else if(rigor == "measure") {
    return FFTW_MEASURE;
  }
  else if(rigor == "patient") {
    return FFTW_PATIENT;
  }
  else if(rigor == "exhaustive") {
    return FFTW_EXHAUSTIVE;
  }
  else if(rigor == "") {
    return FFTW_MEASURE;
  }
  else {
    //TODO throw something
  }
}


NAN_METHOD(PlanDft1d) {
  NanScope();

  Local<Object> opts = args[0].As<Object>();
  Local<Function> callback = args[1].As<Function>();
  
  NanCallback* nanCallback = new NanCallback(callback);

  int size = opts->Get(NanNew<String>("size")).As<Number>()->Value();
  int sign = GetSign(opts);
  unsigned flags = GetRigor(opts);

  PlannerDft1d* planner = new PlannerDft1d(nanCallback, 
      size, 
      sign, 
      flags);
  
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
