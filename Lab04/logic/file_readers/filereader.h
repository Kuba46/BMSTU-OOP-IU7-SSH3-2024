#ifndef FILEREADER_H
#define FILEREADER_H

#include "logic/file_readers/basefilereader.h"
#include "logic/scene/scene.h"
#include "logic/normalizationparameters.h"

#include <vector>

class FileReader : public BaseFileReader
{
private:
    std::vector<double> parse(const Str& line);
    std::vector<std::vector<double>> open(const std::string& path);
public:
    Scene read(const Str& path) override;
    Scene read(const Str& path, const NormalizationParameters& parameters) override;
};

#endif // FILEREADER_H
