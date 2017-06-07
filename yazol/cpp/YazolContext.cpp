#include <SubmoduleManagerImpl.hpp>
#include <Logger/LoggerImpl.hpp>
#include <Console/ConsoleManagerImpl.hpp>
#include <LoggingModuleImplementation.hpp>
#include <Logger/LoggerImpl.hpp>

namespace Yazol
{
    YazolContext::YazolContext()
    {
    }

    YazolContext::~YazolContext()
    {
    }

    Logger& YazolContext::CreateLogger()
    {
        return nullptr;
    }
}