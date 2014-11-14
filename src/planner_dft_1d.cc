#include <nan.h>
#include <fftw3.h>
#include "planner_dft_1d.h"
#include "plan.h"

using namespace v8;

PlannerDft1d::PlannerDft1d(
    NanCallback *callback, 
    int size, 
    int sign, 
    unsigned flags) 
: NanAsyncWorker(callback), size(size), sign(sign), flags(flags) {
}

PlannerDft1d::~PlannerDft1d() {
}

void PlannerDft1d::Execute() {
  this->in = fftw_alloc_complex(size);
  this->out = fftw_alloc_complex(size);

  this->plan = fftw_plan_dft_1d(size, in, out, sign, flags);
}
  
void PlannerDft1d::HandleOKCallback () {
  NanScope();

  Handle<Value> arguments [2] = { Null(), Plan::NewInstance(
      this->in, 
      this->out, 
      this->plan,
      this->size) };
  callback->Call(2, arguments);
}


//TODO HandleNotOKCallback ?
