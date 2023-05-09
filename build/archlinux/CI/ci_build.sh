#!/bin/bash

docker build -t build .
chmod 777 ../
docker run -v "$PWD/../../../:/grille-crypt-qt" --user build -w "/grille-crypt-qt/build/archlinux/" build ./build.sh

