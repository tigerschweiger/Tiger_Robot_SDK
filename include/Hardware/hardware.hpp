#include <iostream>
#include <memory>

enum class SensorType : uint8_t
{
    Lidar = 0,
    Camera = 1
};

// Adapter patterns, make new requirements compatible, will not change the Sensor class, open-close rules
// Proxy means adding new features
class Sensor
{
public:
    virtual double getDistance() = 0;
    virtual ~Sensor() = default;
};

class LidarSensor
{
public:
    double getLidarDistance();
};

class CameraSensor
{
public:
    double getCameraDistance();
};

class LidarAdapter : public Sensor
{
private:
    LidarSensor lidar_;

public:
    double getDistance() override { return lidar_.getLidarDistance(); }
};

class CameraAdapter : public Sensor
{
private:
    CameraSensor camera_;

public:
    double getDistance() override { return camera_.getCameraDistance(); }
};

std::unique_ptr<Sensor> createSensor(SensorType type);