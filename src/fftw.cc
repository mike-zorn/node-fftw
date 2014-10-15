#include <nan.h>
#include <fftw3.h>
#include "complex.h"
#include "fft_worker_1d.h"
#include "ifft_worker_1d.h"

using namespace v8;

fftw_complex* ParseArray(Local<Array> data, int *size) {
  *size = data->Length();
  fftw_complex* input = (fftw_complex*) 
    fftw_malloc(sizeof(fftw_complex) * *size);

  for(int i = 0; i < *size; i++) {
    Local<Value> datum = data->Get(i);
    if(datum->IsNumber()) {
      input[i][0] = datum.As<Number>()->Value();
    }
    else {
      Local<Object> comp = datum.As<Object>();
      input[i][0] = comp->Get(NanNew<String>("real")).As<Number>()->Value();
      input[i][1] = comp->Get(NanNew<String>("imag")).As<Number>()->Value();
    }
  }

  return input;

}

NAN_METHOD(Dft1d) {
  NanScope();

  Local<Array> data = args[0].As<Array>();
  Local<Function> callback = args[1].As<Function>();
  
  NanCallback* nanCallback = new NanCallback(callback);

  int size;
  fftw_complex* input = ParseArray(data, &size);

  FftWorker1d* worker = new FftWorker1d(nanCallback, size, input);
  
  NanAsyncQueueWorker(worker);

  NanReturnUndefined();
}

NAN_METHOD(Idft1d) {
  NanScope();

  Local<Array> data = args[0].As<Array>();
  Local<Function> callback = args[1].As<Function>();
  
  NanCallback* nanCallback = new NanCallback(callback);

  int size;
  fftw_complex* input = ParseArray(data, &size);

  IfftWorker1d* worker = new IfftWorker1d(nanCallback, size, input);
  
  NanAsyncQueueWorker(worker);

  NanReturnUndefined();
}

void Init(Handle<Object> exports) {
  Complex::Init();

  exports->Set(NanNew("dft_1d"), 
      NanNew<FunctionTemplate>(Dft1d)->GetFunction());
  exports->Set(NanNew("idft_1d"), 
      NanNew<FunctionTemplate>(Idft1d)->GetFunction());
}

NODE_MODULE(fftw, Init)
