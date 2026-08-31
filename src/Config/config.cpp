#include <config.hpp>
#include <iostream>

void ConfigManager::Load(const std::string &message) {
  std::cout << "Loading messages..." << std::endl;
  std::cout << "Messages: " << message << std::endl;
}

// template <typename T> T ConfigManager::Get(const std::string &message) {
//   T tmp;
//   return tmp;
// }