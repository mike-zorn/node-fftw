#include <nan.h>
#include <fftw3.h>
#include "complex.h"
#include "fft_worker.h"

using namespace v8;

FftWorker::FftWorker(NanCallback *callback, int size, fftw_complex* in) 
: NanAsyncWorker(callback), size(size), in(in) {
  this->out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * size);
}

FftWorker::~FftWorker() {
  fftw_free(this->in);
  fftw_free(this->out);
}
  
void FftWorker::HandleOKCallback () {
  NanScope();

  Local<Array> result = NanNew<Array>(this->size);

  for(int i = 0; i< size; i++) {
    result->Set(i, Complex::NewInstance(
          NanNew<Number>(out[i][0]),
          NanNew<Number>(out[i][1])
        )
    );
  }
  Handle<Value> arguments [2] = { Null(), result };
  callback->Call(2, arguments);
}
