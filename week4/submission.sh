#!/bin/bash

cd hw4/src

if [ -e tags ]; then
    zip ../../HW4_$1.zip main.cc ppm.h ppm.cc Makefile tags
else
    echo "No ctag file"
fi

cd ../..
