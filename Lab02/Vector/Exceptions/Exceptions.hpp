#pragma once

#include <exception>
#include <string>

using str = std::string;

class BaseError : public std::exception
{
public:
    BaseError(str filename, int line, str info = "Error!")
    {
        message = "\nFile name: " + filename +
            "\nLine: " + std::to_string(line) +
            "Info: " + info;
    }

    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }

    virtual ~BaseError() {};

protected:
    str message;
};

class EmptyVectorError : public BaseError
{
public:
    EmptyVectorError(str filename, int line, str info = "The size of the vector must be greater than 0!\n") :
        BaseError(filename, line, info) {};
};

class IndexVectorError : public BaseError
{
public:
    IndexVectorError(str filename, int line, str info = "Going beyond the vector limit!\n") :
        BaseError(filename, line, info) {};
};

class ZeroDivError : public BaseError
{
public:
    ZeroDivError(str filename, int line, str info = "Division by zero is not allowed!\n") :
        BaseError(filename, line, info) {};
};

class InvalidCopyArrayPointer : public BaseError
{
public:
    InvalidCopyArrayPointer(str filename, int line, str info = "The original array does not exist!\n") :
        BaseError(filename, line, info) {};
};

class DifferentSizeVectors : public BaseError
{
public:
    DifferentSizeVectors(str filename, int line, str info = "The Vectors are different size!\n") :
        BaseError(filename, line, info) {};
};
