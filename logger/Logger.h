#pragma once
#include <iostream>
#include <fstream>
#include <mutex>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>
#include <filesystem>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    static std::unique_ptr<Logger> instance;
    static std::mutex loggerMutex;
    std::ofstream logFile;
protected:
    Logger();  

public:
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance();
    void log(const std::string& message, LogLevel level = LogLevel::INFO);
};