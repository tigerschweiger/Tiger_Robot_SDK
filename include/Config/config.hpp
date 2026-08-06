#include <cstdint>
#include <string>

namespace config {
constexpr double batteryLowThreshold = 20.0;

constexpr double maxSpeed = 1.5;
constexpr double safetyDistance = 0.3;

constexpr auto logFolder = "logs/";
constexpr auto configFile = "config/config.yaml";

constexpr auto robotIP = "192.188.10.2";

constexpr auto lidarTopic = "/lidar/points";

} // namespace config

class ConfigManager {
public:
  static ConfigManager &Instance() {
    static ConfigManager instance;
    return instance;
  }

  static void Load(const std::string &message);
  //TODO
  static template typename Get<typename>(std::string &message);
};