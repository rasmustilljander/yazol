#pragma once

#if defined(_WINDLL)
#define YAZOL_DLL_EXPORT __declspec(dllexport)
#else
#define YAZOL_DLL_EXPORT __declspec(dllimport)
#endif

namespace Yazol
{
    class YazolContext
    {
    public:
        /**
        TODORT
        */
        virtual SubmoduleManager& GetSubModuleManager() const = 0;

        /**
        TODORT remove this and add ReleaseYazolContext, maybe
        */
        virtual ~YazolContext() {}
    };
}

extern "C" {
    typedef Yazol::LoggingModule* (*CreateAYazolContext)();
    YAZOL_DLL_EXPORT Yazol::LoggingModule* CreateAYazolContext();
}