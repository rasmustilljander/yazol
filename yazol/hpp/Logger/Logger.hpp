#pragma once
#include <yazol/hpp/Utilities/Logging/LogTag.hpp>
#include <yazol/hpp/Utilities/Logging/LogLevel.hpp>
#include <string>

namespace Yazol
{
    class Logger
    {
    public:
        /**
            The actual method called when calling DebugLog.
            This method is called indirectly via the #define hack below
            An example how to call this correct via indirection is:
            "Logger.LogText(LogTag::Level, LogLevel::Level, "formatstring %d %d", 1, 2);"

            If this metod is called directly the call should looke something like:
            Logger.LogTextReal(__FUNCTION__, __LINE__, LogTag::Level, LogLevel::Level, "formatstring %d %d", 1, 2);"
        */
        virtual void LogTextReal(const std::string& p_function, const uint16_t& p_line, const Yazol::Utilities::Logging::LogTag& p_logTag,
                                 const Yazol::Utilities::Logging::LogLevel& p_logLevel, const char* p_format, ...) = 0;
    };
}

#ifndef LogText
/*
A bit of a hack.
The hack makes it slightly harder to log things, probably introduces non-portable code and maybe adds a small overhead. However,

TODORT Add possibility to turn hack off, then this method should reference another method

*/
#define LogText(...) LogTextReal(__FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif