#ifndef FFT_WORKER
#define FFT_WORKER

#include <nan.h>
#include <fftw3.h>

class FftWorker : public NanAsyncWorker {
  public:
    void HandleOKCallback();

  protected:
    FftWorker(NanCallback *callback, int size, fftw_complex* in);
    ~FftWorker();  
    int size;
    fftw_complex* in;
    fftw_complex* out;
};

#endif
