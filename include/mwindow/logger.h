//
// Created by ericg on 11/7/2024.
//

#ifndef LOGGING_H
#define LOGGING_H
#include <mwindow/mTime.h>


namespace mwindow::debug
{
    class Logger
    {
    public:
        static void Initialize();
        static void LogError(std::string message);
        static void LogWarning(std::string message);
        static void LogInfo(std::string message);
        static void LogDebug(std::string message);
        static void UnInitialize();
    private:
        static std::string GetLogTime();
    };


}

#ifdef USE_LOGGER
#define LOG_ERROR(message) mwindow::debug::Logger::LogError(message)
#define LOG_WARNING(message) mwindow::debug::Logger::LogWarning(message)
#define LOG_INFO(message) mwindow::debug::Logger::LogInfo(message)
#define LOG_DEBUG(message) mwindow::debug::Logger::LogDebug(message)
#else
#define LOG_ERROR(message)
#define LOG_WARNING(message)
#define LOG_INFO(message)
#define LOG_DEBUG(message)
#endif


#endif //LOGGING_H
