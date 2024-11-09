//
// Created by ericg on 11/7/2024.
//

#include <iostream>
#include <mwindow/logging.h>

#include "mwindow/mwindow.h"


namespace mwindow::debug
{
    DebugConsole::~DebugConsole()
    {
        FreeConsole();
    }

    void DebugConsole::Initalize()
    {

        FreeConsole();
        AllocConsole();
        AttachConsole(GetCurrentProcessId());
        FILE* file;
        freopen_s(&file, "CONOUT$", "w", stdout);
        freopen_s(&file, "CONOUT$", "w", stderr);
    }

    void DebugConsole::LogError(std::string message)
    {
        message.insert(0,GetLogTime() + ": ");
        std::cerr << message << std::endl;
    }

    void DebugConsole::LogWarning(std::string message)
    {

        message.insert(0,GetLogTime() + ": ");
        std::cout << message << std::endl;
    }

    void DebugConsole::LogInfo(std::string message)
    {
        message.insert(0,GetLogTime() + ": ");
        std::cout << message << std::endl;
    }

    void DebugConsole::LogDebug(std::string message)
    {
        message.insert(0,GetLogTime() + ": ");
        std::cout << message << std::endl;
    }
    std::string DebugConsole::GetLogTime()
    {
        auto now  = std::chrono::system_clock::to_time_t( mTime::now());
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now), "%Y-%m-%d %X");
        return ss.str();
    }

}
