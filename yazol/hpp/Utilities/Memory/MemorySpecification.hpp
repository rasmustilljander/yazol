#pragma once
#include <cstdint>

namespace Yazol
{
    namespace Utilities
    {
        namespace Memory
        {
            struct MemorySpecification
            {
                std::size_t free;
                std::size_t total;
                std::size_t occupied;
                MemorySpecification(const std::size_t& p_free, const std::size_t& p_total, const std::size_t& p_occupied)
                    : free(p_free), total(p_total), occupied(p_occupied)
                {
                }
            };
        }
    }
}