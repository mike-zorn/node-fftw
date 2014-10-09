#include "complex.h"
#include <node.h>
#include <nan.h>

static v8::Persistent<v8::FunctionTemplate> complex_constructor;

Complex::Complex(double real, double imag) : 
  real(real), 
  imag(imag) 
{ }

Complex::~Complex() {
}

void Complex::Init() {
  v8::Local<v8::FunctionTemplate> tpl = 
    NanNew<v8::FunctionTemplate>(Complex::New);
  NanAssignPersistent(complex_constructor, tpl);
  tpl->SetClassName(NanNew("Complex"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  NODE_SET_PROTOTYPE_METHOD(tpl, "real", Complex::Real);
  NODE_SET_PROTOTYPE_METHOD(tpl, "imag", Complex::Imag);
}

v8::Handle<v8::Value> Complex::NewInstance(
      v8::Handle<v8::Number> real,
      v8::Handle<v8::Number> imag
  ) {

  NanEscapableScope();

  v8::Local<v8::Object> instance;

  v8::Local<v8::FunctionTemplate> constructorHandle =
      NanNew<v8::FunctionTemplate>(complex_constructor);

  v8::Handle<v8::Value> argv[2] = { real, imag };
  instance = constructorHandle->GetFunction()->NewInstance(2, argv);

  return NanEscapeScope(instance);
}

NAN_METHOD(Complex::New) {
  NanScope();

  Complex* complex = new Complex(
      args[0].As<v8::Number>()->Value(), 
      args[1].As<v8::Number>()->Value()
  );
  complex->Wrap(args.This());

  NanReturnValue(args.This());
}

NAN_METHOD(Complex::Real) {
  NanScope();

  Complex* complex = ObjectWrap::Unwrap<Complex>(args.Holder());

  NanReturnValue(NanNew<v8::Number>(complex->real));
}

NAN_METHOD(Complex::Imag) {
  NanScope();

  Complex* complex = ObjectWrap::Unwrap<Complex>(args.Holder());

  NanReturnValue(NanNew<v8::Number>(complex->imag));
}
