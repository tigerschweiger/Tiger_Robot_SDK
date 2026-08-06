
class Logger {
public:
  // Singleton patterns:
  static Logger &Instance() {
    static Logger instance;
    return instance;
  }

  static void
  Info(const std::string &message); // static: no need to initialize an instance

  static void Warning(const std::string &message);

  static void Error(const std::string &message);

  static void Debug(const std::string &message);

private:
  // why private and deleted?
  Logger() {}
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
};