#pragma once

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)) && defined(_WINDLL)
#define YAZOL_DLL_EXPORT __declspec(dllexport)
#elseif (defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
#define YAZOL_DLL_EXPORT __declspec(dllimport)
#endif

namespace Yazol
{
    class Logger;

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
        virtual Logger* CreateLogger() = 0;
    };

    // TODO breka this into it's own file maybe
    class YazolContextImplementation : public YazolContext
    {
    public:

        /**
        TODORT
        */
        YazolContextImplementation();

        /**
        TODORT remove this and add ReleaseYazolContext, maybe.
        */
        virtual ~YazolContextImplementation();

        /**
        TODORT
        */
        virtual Logger* CreateLogger() override;
    };
}

extern "C" {
    typedef Yazol::YazolContext* (*CreateAYazolContext)();
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    YAZOL_DLL_EXPORT Yazol::YazolContext* CreateAYazolContext();
#else
 //   Yazol::YazolContext* CreateAYazolContext();
#endif
}