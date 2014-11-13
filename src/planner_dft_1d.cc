#include <nan.h>
#include <fftw3.h>
#include "planner_dft_1d.h"

using namespace v8;

PlannerDft1d::PlannerDft1d(NanCallback *callback, int size, int sign unsigned flags) 
: NanAsyncWorker(callback), size(size), size(size), flags(flags) {
}

PlannerDft1d::~PlannerDft1d() {
}

void Execute() {
  this->in = fftw_malloc(sizeof(fftw_complex) * size);
  this->out = fftw_malloc(sizeof(fftw_complex) * size);

  this->plan = fftw_plan_dft_1d(size, in, out, sign, flags);
}
  
void PlannerDft1d::HandleOKCallback () {
  NanScope();

  Handle<Value> arguments [2] = { Null(), NanNew<Plan>(
      this->in, 
      this->out, 
      this->plan) };
  callback->Call(2, arguments);
}


//TODO HandleNotOKCallback ?
