#include <YazolContext.hpp>

namespace Yazol
{
    YazolContextImplementation::YazolContextImplementation()
    {
    }

    YazolContextImplementation::~YazolContextImplementation()
    {
    }

    Logger* YazolContextImplementation::CreateLogger()
    {
        return nullptr;
    }
}

/*
Yazol::YazolContext* CreateAYazolContext()
{
    Yazol::YazolContext* context = new Yazol::YazolContext();
    return context;
}
*/