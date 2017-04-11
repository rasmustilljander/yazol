#include <SubmoduleManagerImpl.hpp>
#include <Logger/LoggerImpl.hpp>
#include <Console/ConsoleManagerImpl.hpp>
#include <LoggingModuleImplementation.hpp>
#include <Logger/LoggerImpl.hpp>

namespace Yazol
{
    SubmoduleManagerImpl::SubmoduleManagerImpl() : m_logger(nullptr), m_consoleManager(nullptr), m_loggingModule(nullptr)
    {
        m_consoleManager = new ConsoleManagerImpl();
    }

    SubmoduleManagerImpl::~SubmoduleManagerImpl()
    {
        if(m_logger != nullptr)
        {
            delete m_logger;
        }

        if(m_consoleManager != nullptr)
        {
            delete m_consoleManager;
        }
    }

    void SubmoduleManagerImpl::Initialize(LoggingModuleImplementation& p_loggingModule)
    {
        m_loggingModule = &p_loggingModule;
        m_logger = new LoggerImpl();
    }

    Logger& SubmoduleManagerImpl::GetLogger() const { return *m_logger; }

    ConsoleManager& SubmoduleManagerImpl::GetConsoleManager() const { return *m_consoleManager; }
}