#include <iostream>

class Sensor
{
public:
    virtual double getDistance() = 0;
    virtual ~Sensor() = default;
};

class LidarSensor
{
};

class CameraSensor
{
};

class LidarAdapter : public Sensor
{
};