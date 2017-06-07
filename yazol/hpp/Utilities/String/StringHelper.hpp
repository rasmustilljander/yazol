#pragma once

#include <string>
#include <cstdint>

namespace Yazol
{
    namespace Utilities
    {
        namespace String
        {
            /**
            Builds a string from a integer value and returns at least two digits.
            Ex. Input 0 Output 00
            Ex. Input 1 Output 01
            Ex. Input 9 Output 09
            Ex. Input 10 Output 10
            */
            inline std::string intToStringAtleastTwoDigits(const uint32_t& value)
            {
                using namespace std;
                if(value < 10)
                {
                    return string("0" + std::to_string(value));
                }

                return to_string(value);
            }
        }
    }
}