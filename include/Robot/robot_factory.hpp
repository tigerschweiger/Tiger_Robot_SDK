#include <robot.hpp>

class RobotFactory {
public:
  static std::unique_ptr<Robot> create(const std::string &type);
};