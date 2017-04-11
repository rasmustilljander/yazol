#! /bin/bash
find . -name "*.cpp" -o -name "*.hpp" | xargs clang-format-3.8 -i
