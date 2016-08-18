#ifndef PROCESS_ONCE_H
#define PROCESS_ONCE_H

#include <v8.h>
#include <nan.h>
#include <pthread.h>

using v8::Local;
using v8::Context;
using v8::MaybeLocal;
using v8::Object;
using v8::Value;
using v8::Function;

static pthread_once_t global_process_once_init = PTHREAD_ONCE_INIT;
static const char *GLOBAL_PROPERTY_NAME = "processOnceInit";

static void process_global_init(void) {
  Nan::EscapableHandleScope scope;
  Local<Context> context = Nan::GetCurrentContext();
  Local<Value> key = Nan::New<v8::String>(GLOBAL_PROPERTY_NAME).ToLocalChecked();
  Local<Value> init = Nan::Get(
    Nan::GetCurrentContext()->Global(), key).ToLocalChecked();
  Local<Function> init_func = Local<Function>::Cast(init);
  Local<Value> argv[0];
  Nan::Call(init_func, context->Global(), 0, argv);
}

NAN_METHOD(ProcessOnce) {
  Nan::HandleScope scope;
  if (info.Length() == 0) {
    Nan::ThrowTypeError("callback must be specified");
  }
  if (!info[0]->IsFunction()) {
    Nan::ThrowTypeError("callback is required to be function");
  } else {
    Nan::Set(Nan::GetCurrentContext()->Global(),
      Nan::New<v8::String>(GLOBAL_PROPERTY_NAME).ToLocalChecked(),
      info[0]);
  }
  pthread_once(&global_process_once_init, process_global_init);
}

void Init(Local<Object> exports, Local<Object> module) {
  Nan::SetMethod(module, "exports", ProcessOnce);
}

NODE_MODULE(processonce, Init)

#endif