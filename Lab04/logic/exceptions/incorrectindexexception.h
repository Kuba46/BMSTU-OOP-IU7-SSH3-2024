#ifndef INCORRECTINDEXEXCEPTION_H
#define INCORRECTINDEXEXCEPTION_H

#include "base_app_exception.h"

class IncorrectIndex : public BaseAppException
{
public:
    IncorrectIndex(const Str info = "Incorrect index!") : BaseAppException(info) {};
};

#endif // INCORRECTINDEXEXCEPTION_H
