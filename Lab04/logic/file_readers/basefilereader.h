#ifndef BASEFILEREADER_H
#define BASEFILEREADER_H

#include "logic/scene/scene.h"
#include "logic/normalizationparameters.h"

#include <string>

using Str = std::string;

class BaseFileReader
{
public:
    virtual ~BaseFileReader() = default;

    virtual Scene read(const Str& path) = 0;
    virtual Scene read(const Str& path, const NormalizationParameters& parameters) = 0;
};

#endif // BASEFILEREADER_H
