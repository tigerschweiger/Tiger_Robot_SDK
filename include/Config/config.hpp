#include<string>
#include<cstdint>


namespace config{
    constexpr double batteryLowThreshold = 20.0;

    constexpr double maxSpeed = 1.5;
    constexpr double safetyDistance = 0.3;

    constexpr auto logFolder = "logs/";
    constexpr auto configFile = "config/config.yaml";

    constexpr auto robotIP= "192.188.10.2";

    constexpr auto lidarTopic = "/lidar/points";

}