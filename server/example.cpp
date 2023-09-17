#include "HelloContent.hpp"
#include "HelloContent+json.hpp"
#include "HelloMessage.hpp"
#include "HelloMessage+json.hpp"
#include "HelloWorld.hpp"
#include "HelloCallback.hpp"

#include <iostream>
#include <sstream>
#include <memory>
#include <string>

class HelloWorldImpl : public HelloWorld {
private:
    HelloMessage message_;
    std::shared_ptr<HelloCallback> callback_;

public:
    HelloWorldImpl(const std::string & msg, const std::shared_ptr<HelloCallback> callback)
        : message_()
        , callback_(callback)
    {
        std::ostringstream oss;
        oss << "wwwww Hello <" << msg << "> wwwww";
        std::cout << "[cpp][HelloWorldImpl::HelloWorldImpl] " << oss.str() << std::endl;

        std::cout << "[cpp][HelloWorldImpl::HelloWorldImpl] call invoke" << std::endl;
        message_.id = 1;
        message_.tag = "example";
        message_.contents = {
            HelloContent(1, "one", { "taro" }),
            HelloContent(2, "two", { "jiro" }),
            HelloContent(3, "san", { "saburo", "hanako", "kotaro" }),
            HelloContent(4, oss.str(), { "hanako" })
        };
        message_.data = { 0x01, 0x00, 0x03, 0x02 };
        nlohmann::json json;
        to_json(json, message_);
        std::cout << "[cpp][HelloWorldImpl::HelloWorldImpl] json: " << std::endl;
        std::cout << json;
        std::cout << "----------------------------------------" << std::endl;
        callback->invoke(message_);
    }

    virtual HelloMessage msg() override {
        return message_;
    }
};

std::shared_ptr<HelloWorld> HelloWorld::create(const std::string & msg, const std::shared_ptr<HelloCallback> & callback)
{
    return std::make_shared<HelloWorldImpl>(msg, callback);
}
