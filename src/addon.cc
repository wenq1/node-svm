#include <node.h>
#include "../node_modules/nan/nan.h"
#include "hello.h"
#include "helloAsync.h"
#include "node-svm.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  exports->Set(NanSymbol("hello"),
    FunctionTemplate::New(Hello)->GetFunction());
  exports->Set(NanSymbol("helloAsync"),
    FunctionTemplate::New(HelloAsync)->GetFunction());
  exports->Set(NanSymbol("svmTrain"),
    FunctionTemplate::New(svmTrain)->GetFunction());
}
#ifdef NODE_MODULE
NODE_MODULE(addon, InitAll)
#endif