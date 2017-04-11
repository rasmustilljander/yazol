#! /bin/bash
mkdir -p build
if [ $? -ne 0 ]; then exit 1; fi
cd build
if [ $? -ne 0 ]; then exit 1; fi
cmake ..
if [ $? -ne 0 ]; then exit 1; fi
make -j 4
