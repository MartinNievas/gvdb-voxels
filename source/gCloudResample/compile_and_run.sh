#!/bin/bash

rm -r build
mkdir build
cd build
cmake ..
make -j16
DISPLAY=:1 ./gCloudResample
