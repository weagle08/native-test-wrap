#include "./addon.hpp"
#include "./MathWrap.hpp"

Napi::Value GetMathWrap(const Napi::CallbackInfo& info) {
	return MathWrap::New(info.Env()).New({});
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
	exports.Set(Napi::String::New(env, "MathWrap"), MathWrap::New(env));
	exports.Set(Napi::String::New(env, "getMathWrap"), Napi::Function::New(env, GetMathWrap));
	return exports;
}

NODE_API_MODULE(MathWrap, Init);