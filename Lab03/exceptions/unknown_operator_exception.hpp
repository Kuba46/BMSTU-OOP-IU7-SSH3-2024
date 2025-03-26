#ifndef UNKNOWN_OPERATOR_EXCEPTION_HPP
#define UNKNOWN_OPERATOR_EXCEPTION_HPP

#include <exception>
#include <string>

using str = std::string;

class UnknownOperatorException : public std::exception
{
public:
    UnknownOperatorException()
    {
        message = "Unkown Operator!";
    }
    const char* what() const noexcept override
    {
        return message.data();
    }
private:
    str message;
};

#endif // UNKNOWN_OPERATOR_EXCEPTION_HPP
