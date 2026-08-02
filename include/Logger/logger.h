
class Logger {
public:
  static void
  Info(const std::string &message); // static: no need to initialize an instance

  static void Warning(const std::string &message);

  static void Error(const std::string &message);

  static void Debug(const std::string &message);
};