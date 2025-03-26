#include <iostream>
#include <string>

using namespace std;

class ILogger {
public:
    virtual void Log(const string& logText) = 0;
    virtual ~ILogger() = default;
};

class FileLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << endl << "Log file: " << endl << logText << endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << endl << "Log database: " << endl << logText << endl;
    }
};

class SmtpMailer {
private:
    ILogger* logger;
public:
    SmtpMailer(ILogger& logger) : logger(&logger) {}

    void SetLogger(ILogger& newlog){
        logger = &newlog;
    }

    ILogger& GetLogger() const {
        return *logger;
    }

    void SendMessage(const string& message) {
        logger->Log("Load massage: " + message);
        cout << "Message sent: " << message << endl;
    }
};

int main() {

    cout << endl <<endl;


    FileLogger fileLogger;
    DatabaseLogger dbLogger;

    SmtpMailer first(fileLogger);
    SmtpMailer second(dbLogger);

    first.SendMessage("Hello, world!");
    second.SendMessage("This is a test message.");


    cout << endl <<endl;

    return 0;
}
