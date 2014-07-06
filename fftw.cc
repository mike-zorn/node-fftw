#include <nan.h>
#include <fftw3.h>

using namespace v8;

class Dft1dWorker : public NanAsyncWorker {
 public:
  Dft1dWorker(NanCallback *callback, int size, fftw_complex* in)
    : NanAsyncWorker(callback), size(size), in(in) {
    this->out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * size);
  }
  ~Dft1dWorker() {
    fftw_free(this->in);
    fftw_free(this->out);
  }

  void Execute () {
    fftw_plan plan = fftw_plan_dft_1d(
        this->size, 
        this->in, 
        this->out, 
        FFTW_FORWARD, 
        FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
  }

  void HandleOKCallback () {
    NanScope();

    Local<Array> result = NanNew<Array>(this->size);

    for(int i = 0; i< size; i++) {
      result->Set(i, NanNew<Number>(out[i][0]));
    }
    Handle<Value> arguments [2] = { Null(), result };
    callback->Call(2, arguments);
  }

 private:
  int size;
  fftw_complex* in;
  fftw_complex* out;
};

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

  Dft1dWorker* worker = new Dft1dWorker(nanCallback, size, input);
  
  NanAsyncQueueWorker(worker);

  NanReturnUndefined();
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew("dft_1d"), NanNew<FunctionTemplate>(Dft1d)->GetFunction());
}

NODE_MODULE(fftw, Init)
