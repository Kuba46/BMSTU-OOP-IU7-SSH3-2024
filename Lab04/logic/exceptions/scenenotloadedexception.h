#ifndef SCENENOTLOADEDEXCEPTION_H
#define SCENENOTLOADEDEXCEPTION_H

#include "base_app_exception.h"

class SceneNotLoaded : public BaseAppException
{
public:
    SceneNotLoaded(const Str info = "Scene is not loaded!") : BaseAppException(info) {};
};

#endif // SCENENOTLOADEDEXCEPTION_H
