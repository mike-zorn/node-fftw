#include <nan.h>
#include <fftw3.h>
#include "fft_worker_1d.h"

FftWorker1d::FftWorker1d(NanCallback *callback, int size, fftw_complex* in)
  : FftWorker(callback, size, in) { }

void FftWorker1d::Execute() {
  fftw_plan plan = fftw_plan_dft_1d(
      this->size, 
      this->in, 
      this->out, 
      FFTW_FORWARD, 
      FFTW_ESTIMATE);

  fftw_execute(plan);
  fftw_destroy_plan(plan);
}
