

class iNavigator {
public:
  virtual void plan() = 0;
};

class AStarNavigator {//strategy patterns, for open-close principle
public:
  void plan() override { std::cout << "Using AStar algorithm!" << std::endl; }
};

class RRTNavigator {
  void plan() override { std::cout << "Using RRT algorithm!" << std::endl; }
};