#ifndef INCORRECTFILEEXCEPTION_H
#define INCORRECTFILEEXCEPTION_H

#include "base_app_exception.h"

class IncorrectFile : public BaseAppException
{
public:
    IncorrectFile(const Str info = "Incorrect File!") : BaseAppException(info) {};
};

#endif // INCORRECTFILEEXCEPTION_H
