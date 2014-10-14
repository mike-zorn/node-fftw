#ifndef IFFT_WORKER_1D
#define IFFT_WORKER_1D

#include <nan.h>
#include <fftw3.h>
#include "fft_worker.h"

class IfftWorker1d : public FftWorker {
  public:
    IfftWorker1d(NanCallback *callback, int size, fftw_complex* in);
    void Execute();
};

#endif
