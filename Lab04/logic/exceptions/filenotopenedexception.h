#ifndef FILENOTOPENEDEXCEPTION_H
#define FILENOTOPENEDEXCEPTION_H

#include "base_app_exception.h"

class FileNotOpenedException : public BaseAppException
{
public:
    FileNotOpenedException(const Str info = "File is not opened!") : BaseAppException(info) {};
};

#endif // FILENOTOPENEDEXCEPTION_H
