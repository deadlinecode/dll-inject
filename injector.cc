#include "functions.h"

using v8::FunctionTemplate;
using namespace Nan;

NAN_MODULE_INIT(InitAll) {
	Set(target, New("inject").ToLocalChecked(), GetFunction(New<FunctionTemplate>(inject)).ToLocalChecked());
	Set(target, New("injectPID").ToLocalChecked(), GetFunction(New<FunctionTemplate>(injectPID)).ToLocalChecked());
	Set(target, New("isProcessRunning").ToLocalChecked(), GetFunction(New<FunctionTemplate>(isProcessRunning)).ToLocalChecked());
	Set(target, New("isProcessRunningPID").ToLocalChecked(), GetFunction(New<FunctionTemplate>(isProcessRunningPID)).ToLocalChecked());
}

NODE_MODULE(injector, InitAll)