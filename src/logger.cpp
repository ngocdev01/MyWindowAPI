//
// Created by ericg on 11/7/2024.
//

#include <iostream>
#include <mwindow/logger.h>
#include <mwindow/mwindow.h>


namespace mwindow::debug
{
    void Logger::UnInitialize()
    {
        FreeConsole();
    }

    void Logger::Initialize()
    {
        FreeConsole();
        AllocConsole();
        AttachConsole(GetCurrentProcessId());
        FILE* file;
        freopen_s(&file, "CONOUT$", "w", stdout);
        freopen_s(&file, "CONOUT$", "w", stderr);
    }

    void Logger::LogError(std::string message)
    {
        message.insert(0,GetLogTime() + " ERROR: ");
        std::cerr << message << std::endl;
    }

    void Logger::LogWarning(std::string message)
    {

        message.insert(0,GetLogTime() + " WARNING: ");
        std::cout << message << std::endl;
    }

    void Logger::LogInfo(std::string message)
    {
        message.insert(0,GetLogTime() + " INFOR: ");
        std::cout << message << std::endl;
    }

    void Logger::LogDebug(std::string message)
    {
        message.insert(0,GetLogTime() + " DEBUG: ");
        std::cout << message << std::endl;
    }

    std::string Logger::GetLogTime()
    {
        auto now  = std::chrono::system_clock::to_time_t( mTime::now());
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now), "%Y-%m-%d %X");
        return ss.str();
    }

}
