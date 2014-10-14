#include <nan.h>
#include <fftw3.h>
#include "complex.h"
#include "fft_worker_1d.h"

using namespace v8;

NAN_METHOD(Dft1d) {
  NanScope();

  Local<Array> data = args[0].As<Array>();
  Local<Function> callback = args[1].As<Function>();
  
  NanCallback* nanCallback = new NanCallback(callback);

  int size = data->Length();
  fftw_complex* input = (fftw_complex*) 
    fftw_malloc(sizeof(fftw_complex) * size);

  for(int i = 0; i < size; i++) {
    input[i][0] = data->Get(i).As<Number>()->Value();
  }

  FftWorker1d* worker = new FftWorker1d(nanCallback, size, input);
  
  NanAsyncQueueWorker(worker);

  NanReturnUndefined();
}

void Init(Handle<Object> exports) {
  Complex::Init();

  exports->Set(NanNew("dft_1d"), NanNew<FunctionTemplate>(Dft1d)->GetFunction());
}

NODE_MODULE(fftw, Init)
