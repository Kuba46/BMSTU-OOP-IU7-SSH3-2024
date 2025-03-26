#ifndef BASE_APP_EXCEPTION_H
#define BASE_APP_EXCEPTION_H

#include <exception>
#include <string>

using Str = std::string;

class BaseAppException : public std::exception
{
public:
    BaseAppException(const Str info = "Error!")
    {
        message = info;
    }

    virtual const char* what() const noexcept override
    {
        return message.data();
    }
protected:
    Str message;
};

#endif // BASE_APP_EXCEPTION_H
