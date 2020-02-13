#!/bin/bash
#Builds and compiles the C++/Qt code with qmake
mkdir build/
cd build/
qmake ..
make
