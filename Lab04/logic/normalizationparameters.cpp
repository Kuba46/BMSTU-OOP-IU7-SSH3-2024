#include "normalizationparameters.h"

NormalizationParameters::NormalizationParameters(double min, double max)
{
    _min = min;
    _max = max;
}

double NormalizationParameters::min() const
{
    return _min;
}

double NormalizationParameters::max() const
{
    return _max;
}

void NormalizationParameters::setMin(double min)
{
    _min = min;
}

void NormalizationParameters::setMax(double max)
{
    _max = max;
}

void NormalizationParameters::normilize(std::vector<std::vector<double>>& values) const
{
    double min = values[0][0];
    double max = values[0][0];
    for (std::vector<double>& row : values)
    {
        for (double cell : row)
        {
            if (cell < min)
            {
                min = cell;
            }
            if (cell > max)
            {
                max = cell;
            }
        }
    }
    for (std::vector<double>& row : values)
    {
        for (double& cell : row)
        {
            if (max - min != 0)
            {
                cell = _min + (cell - min)/(max - min) * (_max - _min);
            }
        }
    }
}
