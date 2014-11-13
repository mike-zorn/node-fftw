#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <nan.h>
#include <fftw3.h>

class Executor : public NanAsyncWorker {
  public:
    void HandleOKCallback();
    Executor(
        NanCallback *callback, 
        fftw_complex* in, 
        fftw_complex* out, 
        fftw_plan plan,
        int size);
    ~Executor();  
    void Execute();

  private:
    fftw_plan plan;
    fftw_complex* in;
    fftw_complex* out;
    int size;
};

#endif
