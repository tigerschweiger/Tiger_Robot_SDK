#include <hardware.hpp>

// simple factory pattern:
std::unique_ptr<Sensor> createSensor(SensorType type)
{
    switch (type)
    {
    case Lidar:
        return std::make_unique<LidarAdapter>();
    case Camera:
        return std::make_unique<CameraAdapter>();
    }
}