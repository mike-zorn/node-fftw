#ifndef PLAN_H
#define PLAN_H

#include <nan.h>
#include <node.h>
#include <fftw3.h>

using namespace v8;

class Plan : public node::ObjectWrap {
 public:
  static void Init();
  static v8::Handle<v8::Value> NewInstance(
      fftw_complex* in, 
      fftw_complex* out, 
      fftw_plan plan,
      int size);

  Plan();
  ~Plan();

 private:
  static NAN_METHOD(New);
  static NAN_METHOD(Execute);

  void LoadInput(Local<Array> data);
  fftw_plan plan;
  fftw_complex* in;
  fftw_complex* out;
  int size;
  bool executed;
};

#endif
