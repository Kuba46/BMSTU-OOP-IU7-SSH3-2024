#ifndef INVALID_EXPRESSION_EXCEPTION_HPP
#define INVALID_EXPRESSION_EXCEPTION_HPP

#include <exception>
#include <string>

using str = std::string;

class InvalidExpressionException : public std::exception
{
public:
    InvalidExpressionException()
    {
        message = "Invalid expression";
    }
    const char* what() const noexcept override
    {
        return message.data();
    }

private:
    str message;
};

#endif // INVALID_EXPRESSION_EXCEPTION_HPP
