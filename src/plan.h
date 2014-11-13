#ifndef PLAN_H
#define PLAN_H

#include <nan.h>
#include <node.h>

class Plan : public node::ObjectWrap {
 public:
  static void Init();
  static v8::Handle<v8::Value> NewInstance(
      fftw_complex* in, 
      fftw_complex* out, 
      fftw_plan* plan);

  Plan(
      fftw_complex* in, 
      fftw_complex* out, 
      fftw_plan* plan);
  ~Plan();

 private:
  static NAN_METHOD(Execute);

  fftw_plan* plan;
  fftw_complex* in;
  fftw_complex* out;
  bool executed;
};

#endif
