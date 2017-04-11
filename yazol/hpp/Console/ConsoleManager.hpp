#pragma once

#include <yazol/hpp/Utilities/Logging/Console/ConsoleColor.hpp>
#include <yazol/hpp/Utilities/Logging/Include/Console/Console.hpp>
#include <yazol/hpp/Utilities/Logging/LogTag.hpp>
#include <yazol/hpp/Utilities/Logging/LogLevel.hpp>
#include <string>

namespace Yazol
{
    class ConsoleManager
    {
    public:
        /**
            Create a new console with the given parameters, returns an already existing console if one exists with the given name.
        */
        virtual Console& CreateNewConsole(const std::string& p_consoleName = "standard",
                                          const Yazol::Utilities::Logging::LogTag& p_logtag = Yazol::Utilities::Logging::LogTag::NOTAG,
                                          const ConsoleColor& p_textColor = ConsoleColorEnum::WHITE,
                                          const ConsoleColor& p_backgroundColor = ConsoleColorEnum::BLACK) = 0;

        /**
            Returns an already existing console, throws exception if no console exists.
        */
        virtual Console& GetConsole(const std::string& p_consoleName = "standard") = 0;
    };
}