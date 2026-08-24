#include <config.hpp>
#include <hardware.hpp>
#include <logger.h>
#include <robot.hpp>

int main() {
  // choose the algorithm from the config
  Robot robot(RobotStatus::Idle, std::make_unique<AStarNavigator>());
  // auto robot = RobotFactory::create("lidar");

  std::cout << "Your robot has been created! Please give me some poses!"
            << std::endl;

  // choose the proxy navigation solution:
  Robot robot2(RobotStatus::Idle, std::make_unique<SafetyNavigationProxy>());
  Logger::Instance().Info("Robot started");
  ConfigManager::Instance().Load("robot.yaml");
  auto speed =
      ConfigManager::Instance().Get<double>("robot.max_speed") std::cout
      << "The max speed of this robot is: " << speed << std::endl;

  robot.navigate();

  // Anyone wants the change of battery, call this function
  // pseudo code:
  // robot.updateBattery();
  robot.onBatteryChange([](const Battery &battery) {
    std::cout << "Battery: " << battery.percentage << std::endl;
  });

  auto lidar = createSensor(Lidar);
  auto camera = createSensor(Camera);
  std::cout << "Distance using Lidar: " << lidar->getDistance() << std::endl;
  std::cout << "Distance using Camera: " << camera->getDistance() << std::endl;
}