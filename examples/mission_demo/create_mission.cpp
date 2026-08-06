#include<config.hpp>


int main() {
  // choose the algorithm from the config
  Robot robot(1, std::make_unique<AStarNavigator>());
  // auto robot = RobotFactory::create("lidar");

  std::cout << "Your robot has been created! Please give me some poses!"
            << std::endl;

  // choose the proxy navigation solution:
  Robot2 robot(1, std::make_unique<SafetyNavigationProxy>());
  Logger::Instance().Info("Robot started");
  ConfigManager::Instance().Load("robot.yaml");
  auto speed =
      ConfigManager::Instance().Get<double>("robot.max_speed") std::cout
      << "The max speed of this robot is: " << speed << std::endl;

  robot.navigate();
}