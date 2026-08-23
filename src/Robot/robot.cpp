#include <robot.hpp>

void Robot::navigate() { navigator_->navigate(); }

void Robot::startRobot() {
  locator_->getCurrentLocalization();
  std::cout << "Start the localization node!" << std::endl;

  std::cout << "Start the perception node!" << std::endl;

  std::cout << "Start the control node!" << std::endl;

  std::cout << "Start the planning node!" << std::endl;
}
