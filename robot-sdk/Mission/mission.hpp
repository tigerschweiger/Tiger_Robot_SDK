

class Mission {
private:
  bool isCanceled_;
  bool isRunning_;

public:
  bool isMissionCanceled() { return isCanceled_; }
  bool isMissionRunning() { return isRunning_; }
  void cancel();
  void setGoal();
};