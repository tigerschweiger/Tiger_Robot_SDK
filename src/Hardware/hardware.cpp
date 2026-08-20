#include <hardware.hpp>

// simple factory pattern:
std::unique_ptr<Sensor> createSensor(SensorType type) {
  switch (type) {
  case SensorType::Lidar: // normal enum could use Lidar
    return std::make_unique<LidarAdapter>();
  case SensorType::Camera:
    return std::make_unique<CameraAdapter>();
  }
}