#pragma once
#include <yazol/hpp//Utilities/Memory/Circlebuffer/CircleBufferType.hpp>

namespace Yazol
{
    namespace Utilities
    {
        namespace Memory
        {
            struct CircleBufferHeader
            {
                CircleBufferHeader() : packageType(CircleBufferTypeEnum::UNKNOWN), packageSize(0) {}
                CircleBufferType packageType;
                int32_t packageSize;
            };
        }
    }
}