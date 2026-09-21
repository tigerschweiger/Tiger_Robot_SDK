#include <robot.hpp>

RobotState::~RobotState() {} // non-implementable?

StandbyState::~StandbyState() {}

void RobotState::normal_charge() {}

void RobotState::non_key_function() {}

void Robot::navigate() { navigator_->navigate(); }

void StandbyState::getState() {}

void Robot::startRobot() {
  locator_->getCurrentLocalization();
  std::cout << "Start the localization node!" << std::endl;

  std::cout << "Start the perception node!" << std::endl;

  std::cout << "Start the control node!" << std::endl;

  std::cout << "Start the planning node!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, BatteryStatus status) {
  switch (status) {
  case BatteryStatus::Unknown:
    os << "Unknown";
  case BatteryStatus::Charging:
    os << "Charging";
  case BatteryStatus::Discharging:
    os << "Discharging";
  case BatteryStatus::Idle:
    os << "Idle";
  }
  return os;
}