#include <robot.hpp>

Robot::navigate() { navigator_->plan(); }

Robot::startRobot() {
  locator_->getCurrentLocalization();
  std::cout << "Start the localization node!" << std::endl;

  std::cout << "Start the perception node!" << std::endl;

  std::cout << "Start the control node!" << std::endl;

  std::cout << "Start the planning node!" << std::endl;
}
