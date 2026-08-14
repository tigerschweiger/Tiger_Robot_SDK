
#include <mission.hpp>
#include <unique_ptr>

enum class RobotStatus : uint8_t
{
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

// state patterns:
class RobotState
{
public:
  virtual void getState() = 0;
  virtual void charge() = 0;

  virtual ~RobotState() {}
};

class StandbyState : RobotState
{
public:
  void getState() override;
};

class MoveState : RobotState
{
public:
  void getState() override;
};


enum class BatteryStatus : uint8_t
{
  Unknown = 0,
  Charing = 1,
  Discharging = 2,
  Idle = 3
};

class Battery
{
public:
  BatteryStatus getBatteryStatus() { return battery_status_; }

private:
  double percetage_;
  BatteryStatus battery_status_;
};

struct Pose()
{
  double x;
  double y;
  double z;

  double pitch;
  double roll;
  double yaw;
};

class Robot
{
  Robot(RobotStatus status, std::unique<INavigator> navigator)
      : status_(status), navigator_(std::move(navigator)), robotState_(std::make_unique<StandbyState>()) {}
  void connect();
  void disconnect();
  void start();
  void stop();
  RobotStatus status() { return status_; }

  Pose getPose(double time);
  void setPose(double time);
  void resetLocalization();

  void navigate() { navigator_->navigate(); }

  // RobotMemento SaveState();
  // void Restore(const RobotMemento& memento);

  // observer pattern
  using BatteryCallback =
      std::function<void(const Battery &)>; // general function container
  void onBatteryChange(BatteryCallback callback)
  {
    battery_callback_ = std::move(callback);
  }

  // Facade pattern:
  void startRobot()
  {
    locator_->getCurrentPosition();
    std::cout << "Start the localization node!" << std::endl;

    std::cout << "Start the perception node!" << std::endl;

    std::cout << "Start the control node!" << std::endl;

    std::cout << "Start the planning node!" << std::endl;
  }

private:
  RobotStatus status_;
  std::unique_ptr<RobotState> robotState_;
  double longtitude_;
  double latitude_;

  Mission mission_;

  std::unique_ptr<INavigator> navigator_;
  BatteryCallback
      battery_callback_; // TODO: std::vector<BatteryCallback> callbacks_;
  std::unique_ptr<ILocalization> locator_;
};

// class LidarRobot : public Robot{
//   LidarRobot(RobotStatus status) : status_(status) {}
// };

// class CameraRobot : public Robot{
//   CameraRobot(RobotStatus status) : status_(status) {}
// };

// class RobotMomento {
// public:
//   RobotMomento(Pose &currentPose, RobotStatus &status,
//                BatteryStatus &batteryStatus)
//       : currentPose_(currentPose), batteryStatus_(batteryStatus),
//         status_(status) {}

// private:
//   friend class Robot; // TODO: why?
//   Pose currentPose_;
//   RobotStatus status_;
//   BatteryStatus batteryStatus_;
// };
