#include <node.h>

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void Multiply(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, 
        "You need to pass 2 arguments or more")));

    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, 
        "Wrong arguments")));

    return;
  }

  float multiply = 1;

  for (int i = 0; i < args.Length(); i++) {
    multiply *= args[i].As<Number>()->Value();
  }

  Local<Number> result = Number::New(isolate, multiply);

  args.GetReturnValue().Set(result);
}