#ifndef INCORRECTSIZE_H
#define INCORRECTSIZE_H

#include "base_app_exception.h"

class IncorrectSize : public BaseAppException
{
public:
    IncorrectSize(const Str info = "Incorrect size!") : BaseAppException(info) {};
};

#endif // INCORRECTSIZE_H
