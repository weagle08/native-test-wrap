#include <napi.h>
#include <MathObj.hpp>

class MathWrap : public Napi::ObjectWrap<MathWrap>
{
public:
    MathWrap(const Napi::CallbackInfo &info);
    ~MathWrap();

    Napi::Value Add(const Napi::CallbackInfo &info);
    Napi::Value Subtract(const Napi::CallbackInfo &info);
    Napi::Value GetId(const Napi::CallbackInfo &info);

    static Napi::Function GetClass(Napi::Env env);

private:
    MathObj *_wrappedObj;
    int _id;
};