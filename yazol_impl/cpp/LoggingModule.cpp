#include <LoggingModuleImplementation.hpp>
#include <SubmoduleManagerImpl.hpp>

namespace Yazol
{
    LoggingModuleImplementation::LoggingModuleImplementation()
        : m_submoduleManager(nullptr)
    {
    }

    LoggingModuleImplementation::~LoggingModuleImplementation()
    {
    }

    void LoggingModuleImplementation::Startup()
    {
#ifdef NO_LOGGER
        printf("Logger system haas been disabled by preprocessor entry 'NO_LOGGER'\n");
#else
        printf("Logger system is now online, all other logging will be directed to the logfile.\n");
#endif
        m_submoduleManager = new SubmoduleManagerImpl();
        static_cast<SubmoduleManagerImpl*>(m_submoduleManager)->Initialize(*this);
    }

    void LoggingModuleImplementation::Shutdown() {}

    SubmoduleManager& LoggingModuleImplementation::GetSubModuleManager() const { return *m_submoduleManager; }
}

Yazol::LoggingModule* CreateAYazolContext()
{
    Yazol::LoggingModule* yazolContext = new Yazol::LoggingModuleImplementation();
    return logger;
}