#include "Logger.h"

std::unique_ptr<Logger> Logger::instance = nullptr;
std::mutex Logger::loggerMutex;

Logger::Logger() {
    std::filesystem::create_directories("../logs");  // Ensure the logs directory exists
    logFile.open("../logs/minesweeper.log", std::ios::app);
    if (!logFile) {
        std::cerr << "Failed to open log file!\n";
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

Logger* Logger::getInstance() {
    std::lock_guard<std::mutex> lock(loggerMutex);
    if (!instance) {
        instance.reset(new Logger());
    }
    return instance.get();
}

void Logger::log(const std::string& message, LogLevel level) {
    std::lock_guard<std::mutex> lock(loggerMutex);
    if (!logFile.is_open()) return;

    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string levelStr;
    switch (level) {
        case LogLevel::INFO: levelStr = "[INFO] "; break;
        case LogLevel::WARNING: levelStr = "[WARNING] "; break;
        case LogLevel::ERROR: levelStr = "[ERROR] "; break;
    }

    logFile << std::ctime(&now) << " " << levelStr << message << "\n";
}
