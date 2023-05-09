#!/bin/bash

cmake  ../../CMakeLists.txt
cmake --build .
makepkg

rm grille-crypt-qt
rm grille-crypt -r
rm grille-crypt-qt_autogen -r
rm pkg -r
rm src/grille-crypt-qt
rm Makefile
rm CMa* -r
rm cmake_install.cmake
rm .qt -r
