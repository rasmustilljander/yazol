#pragma once
#include <string>

namespace Yazol
{
    namespace Utilities
    {
        namespace Logging
        {
            struct LogLevelInfo
            {
                explicit LogLevelInfo(const std::string& p_name) : name(p_name) {}
                LogLevelInfo() {}
                std::string name;
            };
        }
    }
}