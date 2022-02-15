#!/bin/sh

echo "Removing CMakeFiles"
rm -rf ./CMakeFiles
echo "Removing cmake_install.cmake"
rm -rf ./cmake_install.cmake
echo "Removing CMakeCache.txt"
rm -rf ./CMakeCache.txt
echo "Removing build files"
rm -rf ./build
echo "Removing CPack files"
rm -rf CPack*

echo "Removing build system files"
#Ninja
rm -rf *.ninja .ninja*

#Make
rm -rf Makefile

echo "Clean CMake built files"
