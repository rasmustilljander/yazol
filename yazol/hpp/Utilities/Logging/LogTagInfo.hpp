#pragma once
#include <string>

namespace Yazol
{
    namespace Utilities
    {
        namespace Logging
        {
            struct LogTagInfo
            {
                explicit LogTagInfo(const std::string& p_name) : name(p_name) {}
                LogTagInfo() {}
                std::string name;
            };
        }
    }
}