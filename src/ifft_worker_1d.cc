#include <nan.h>
#include <fftw3.h>
#include "ifft_worker_1d.h"

IfftWorker1d::IfftWorker1d(NanCallback *callback, int size, fftw_complex* in)
  : FftWorker(callback, size, in) { }

void IfftWorker1d::Execute() {
  fftw_plan plan = fftw_plan_dft_1d(
      this->size, 
      this->in, 
      this->out, 
      FFTW_BACKWARD, 
      FFTW_ESTIMATE);

  fftw_execute(plan);
  fftw_destroy_plan(plan);
}
