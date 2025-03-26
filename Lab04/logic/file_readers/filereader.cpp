#include "logic/file_readers/filereader.h"
#include "logic/scene/builder/graphbuilder.h"
#include "logic/exceptions/incorrectfileexception.h"
#include "logic/exceptions/filenotopenedexception.h"

#include <fstream>

std::vector<std::vector<double>> FileReader::open(const Str& path)
{
    std::ifstream in(path, std::ios_base::in);
    if (!in.good())
    {
        throw FileNotOpenedException();
    }
    std::vector<std::vector<double>> rows;
    while (!in.eof())
    {
        Str line;
        in >> line;
        std::vector<double> row = parse(line);
        if (row.size() > 0 && (rows.size() == 0 || (rows.size() > 0 && rows[0].size() == row.size())))
        {
            rows.push_back(row);
        }
    }
    in.close();
    if (rows.size() == 0)
    {
        throw IncorrectFile();
    }
    return rows;
}

Scene FileReader::read(const Str& path)
{
    std::vector<std::vector<double>> values = open(path);
    Scene scene;
    scene.add(GraphBuilder(values).build());
    return scene;
}

Scene FileReader::read(const Str& path, const NormalizationParameters& parameters)
{
    std::vector<std::vector<double>> values = open(path);
    parameters.normilize(values);
    Scene scene;
    scene.add(GraphBuilder(values).build());
    return scene;
}

std::vector<double> FileReader::parse(const Str& originalLine)
{
    Str line = originalLine.substr(0, originalLine.find_first_of("\r\n"));
    size_t index = 0;
    size_t end = 0;
    std::vector<double> values;
    while (end < line.length() && (end = line.find(",", index) != Str::npos ? line.find(",", index) : line.length()))
    {
        Str cell = line.substr(index, (end - index));
        index = end + 1;
        try
        {
            values.push_back(std::stoi(cell));
        }
        catch (std::invalid_argument &e)
        {
            continue;
        }
    }
    return values;
}
