#pragma once
#include <yazol/hpp/Utilities/Logging/LogLevel.hpp>

namespace Yazol
{
    class Console
    {
    public:
    	
        /**
        Sends data to console
        */
        virtual void WriteToConsole(const Yazol::Utilities::Logging::LogLevel& p_vLevel, const char* p_format, ...) = 0;
    };
}
