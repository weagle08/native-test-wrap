#include <napi.h>

#include "./MathWrap.hpp"
#include <MathObj.hpp>
#include <cstdlib>

MathWrap::MathWrap(const Napi::CallbackInfo &info) : ObjectWrap(info)
{
    Napi::Env env = info.Env();

    this->_wrappedObj = new MathObj();

    std::srand(time(0));
    this->_id = std::rand() % 100;
}

MathWrap::~MathWrap()
{
    delete this->_wrappedObj;
}

Napi::Value MathWrap::Add(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    int a = info[0].ToNumber();
    int b = info[1].ToNumber();

    int result = this->_wrappedObj->add(a, b);

    return Napi::Number::New(env, result);
}

Napi::Value MathWrap::Subtract(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    int a = info[0].ToNumber();
    int b = info[1].ToNumber();

    int result = this->_wrappedObj->subtract(a, b);

    return Napi::Number::New(env, result);
}

Napi::Value MathWrap::GetId(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), this->_id);
}

Napi::Function MathWrap::GetClass(Napi::Env env)
{
    return DefineClass(
        env,
        "MathWrap",
        {MathWrap::InstanceMethod("add", &MathWrap::Add),
         MathWrap::InstanceMethod("subtract", &MathWrap::Subtract),
         MathWrap::InstanceMethod("getId", &MathWrap::GetId)});
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "MathWrap"), MathWrap::GetClass(env));
    return exports;
}

NODE_API_MODULE(MathWrap, Init);
