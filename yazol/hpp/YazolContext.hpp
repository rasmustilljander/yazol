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
        TODORT remove this and add ReleaseYazolContext, maybe.
        */
        virtual ~YazolContext() {}

        /**
        TODORT
        */
        virtual Logger& CreateLogger() = 0;
    };
}

extern "C" {
    typedef Yazol::YazolContext* (*CreateAYazolContext)();
    YAZOL_DLL_EXPORT Yazol::YazolContext* CreateAYazolContext();
}