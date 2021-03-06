#ifndef PORT_STATUS_H
#define PORT_STATUS_H

#include <node.h>
#include <node_object_wrap.h>

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Persistent;
using v8::PropertyCallbackInfo;
using v8::String;
using v8::Value;

class PortStatus : public node::ObjectWrap {
 public:
  static void Init(Local<Object> exports);
  static void NewInstance(const PropertyCallbackInfo<Value>& args, int handle);

 private:
  explicit PortStatus(int handle);
  ~PortStatus();

  int GetStatus();

  static void New(const FunctionCallbackInfo<Value>& args);

  static void GetAck(Local<String> property, const PropertyCallbackInfo<Value>& info);
  static void GetBusy(Local<String> property, const PropertyCallbackInfo<Value>& info);
  static void GetError(Local<String> property, const PropertyCallbackInfo<Value>& info);
  static void GetSelect(Local<String> property, const PropertyCallbackInfo<Value>& info);
  static void GetPaperOut(Local<String> property, const PropertyCallbackInfo<Value>& info);
  
  static void SetStatus(Local<String> property, Local<Value> value, const PropertyCallbackInfo<void>& info);

  static Persistent<Function> constructor;

  int handle_;
};

#endif
