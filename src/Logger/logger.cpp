#include <iostream>
#include <logger.h>

void Logger::Info(const std::string &message) {
  std::cout << "Messages: " << message << std::endl;
}