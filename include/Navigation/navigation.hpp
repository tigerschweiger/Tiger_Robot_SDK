#include <iostream>

class INavigator {
public:
  virtual void plan() = 0;
  virtual void navigate();
};

class AStarNavigator
    : public INavigator { // strategy patterns, for open-close principle
public:
  void plan() override { std::cout << "Using AStar algorithm!" << std::endl; }
};

class RRTNavigator : public INavigator {
  void plan() override { std::cout << "Using RRT algorithm!" << std::endl; }
};

class Navigation : public INavigator {
  void navigate() override {}
};

// navigation works for batttery check, which should not be, but for satety
class SafetyNavigationProxy : public INavigator {
  void navigate() override {
    std::cout << "Checking battery:" << std::endl;
    // if()...
  }
};
