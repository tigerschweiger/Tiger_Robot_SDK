
#include <mission.hpp>

enum class RobotStatus : uint8_t {
  Unknown = 0,
  Idle = 1,
  Moving = 2,
  Remotecontrol = 3,
  Teleop = 4,
  Charing = 5,
  Docking = 6,
  Shutdown = 7,
  Emergencystop = 8
};

enum class BatteryStatus : uint8_t {
  Unknown = 0,
  Charing = 1,
  Discharging = 2,
  Idle = 3
};

class Battery {
public:
  BatteryStatus getBatteryStatus() { return battery_status_; }

private:
  double percetage_;
  BatteryStatus battery_status_;
};

struct Pose() {
  double x;
  double y;
  double z;

  double pitch;
  double roll;
  double yaw;
};

class Robot {
  Robot(RobotStatus status) : status_(status) {}
  void connect();
  void disconnect();
  void start();
  void stop();
  RobotStatus status() { return status_; }

  Pose getPose(double time);
  void setPose(double time);
  void resetLocalization();

private:
  RobotStatus status_;
  double longtitude_;
  double latitude_;

  Mission mission_;
};