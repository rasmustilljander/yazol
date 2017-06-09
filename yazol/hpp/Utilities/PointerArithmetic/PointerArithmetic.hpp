#pragma once

#include <cstdint>

namespace Yazol
{
    namespace Utilities
    {
        namespace PointerArithmetic
        {
            // TODORT
            // Not sure how this works if one attempts to use "real types" instead of pointers.
            template <typename T> T Addition(T const p_src, const std::size_t& p_value)
            {
                // TODORT Check for overflow / underflow ?
                return reinterpret_cast<T>(reinterpret_cast<std::size_t>(p_src) + p_value);
            }

            // TODORT
            // Not sure how this works if one attempts to use "real types" instead of pointers.
            template <typename T> intmax_t Difference(T const p_low, T const p_high)
            {
                return (reinterpret_cast<intmax_t >(p_high) - reinterpret_cast<intmax_t >(p_low));
            }

/*
            template <typename T> std::size_t Difference(const T& p_low, const T& p_high)
            {
                std::size_t a = reinterpret_cast<std::size_t>(p_low);
                std::size_t b = reinterpret_cast<std::size_t>(p_high);
                return a > b ? a - b : b - a;
            }
            */

            static bool AssertAdresstInside(void* const p_adressToAssert, void* const p_low, void* const p_high)
            {
                if(p_adressToAssert >= p_low && p_adressToAssert < p_high)
                {
                    return true; // Inside
                }
                return false; // Outside
            }
        }
    }
}