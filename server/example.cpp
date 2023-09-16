#include "hello_world.hpp"
#include "hello_callback.hpp"

#include <iostream>
#include <sstream>
#include <memory>
#include <string>

class HelloWorldImpl : public HelloWorld {
private:
    std::string msg_;
    std::shared_ptr<HelloCallback> callback_;

public:
    HelloWorldImpl(const std::string & msg, const std::shared_ptr<HelloCallback> callback)
        : msg_(msg)
        , callback_(callback)
    {
        std::ostringstream oss;
        oss << "wwwww Hello <" << msg << "> wwwww";
        std::cout << "[cpp][HelloWorldImpl::HelloWorldImpl] " << oss.str() << std::endl;

        std::cout << "[cpp][HelloWorldImpl::HelloWorldImpl] call invoke" << std::endl;
        callback->invoke(oss.str());
    }

    virtual std::string msg() override {
        return msg_;
    }
};

std::shared_ptr<HelloWorld> HelloWorld::create(const std::string & msg, const std::shared_ptr<HelloCallback> & callback)
{
    return std::make_shared<HelloWorldImpl>(msg, callback);
}
