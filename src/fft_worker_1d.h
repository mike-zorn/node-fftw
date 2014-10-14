#ifndef FFT_WORKER_1D
#define FFT_WORKER_1D

#include <nan.h>
#include <fftw3.h>
#include "fft_worker.h"

class FftWorker1d : public FftWorker {
  public:
    FftWorker1d(NanCallback *callback, int size, fftw_complex* in);
    void Execute();
};

#endif
