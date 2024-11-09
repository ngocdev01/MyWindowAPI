//
// Created by ericg on 11/7/2024.
//

#ifndef LOGGING_H
#define LOGGING_H
#include <mwindow/mTime.h>

#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"


namespace mwindow::debug
{
    enum LogType { LOG_ERROR, LOG_WARN, LOG_INFO };

    class DebugConsole
    {
    public:
        DebugConsole() = default;
        ~DebugConsole();
        void Initalize();
        void LogError(std::string message);
        void LogWarning(std::string message);
        void LogInfo(std::string message);
        void LogDebug(std::string message);
    private:
        std::string GetLogTime();
    };


}


#endif //LOGGING_H
