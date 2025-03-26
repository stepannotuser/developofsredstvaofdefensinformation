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

    void SendMessage(const string& message, int flag) {
        if(flag){                                    // таким способом добавлен флаг, определяющий необходимость логгирования
            logger->Log("Load massage: " + message);
        }
        cout << "Message sent: " << message << endl; // в любом случае пользователь получит сообщение
    }
};

int main() {

    cout << endl <<endl;


    //FileLogger fileLogger;
    //DatabaseLogger dbLogger;

    //SmtpMailer first(fileLogger);
    //SmtpMailer second(dbLogger);

    //first.SendMessage("Hello, world!");
    //second.SendMessage("This is a test message.");

    ILogger* temp = new FileLogger();       // выделяю память в куче
    SmtpMailer first(*temp);
    first.SendMessage("Hello, world!", 1);  // путем флага устанавливаю необходимость логгирования, вне зависимости от получения сообщения
    delete temp;                            // обязательно очищаю память


    cout << endl <<endl;

    return 0;
}
