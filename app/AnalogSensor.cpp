#include <AnalogSensor.hpp>
#include <numeric>
#include <memory>
#include <vector>

AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples)
{
}

AnalogSensor::~AnalogSensor()
{
}

int AnalogSensor::Read()
{
    // change from vector pointer to shared pointer to automatically clear memory when finished
    auto readings = std::make_shared<std::vector<int>> (mSamples, 10);

    double result = std::accumulate( readings->begin(), readings->end(), 0.0 ) / readings->size();
    return result;
}


