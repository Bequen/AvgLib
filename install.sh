#!/bin/bash

make compile
ar rcs libavg.a *.o

sudo mkdir /usr/include/avg
sudo mv libavg.a /usr/lib64/

sudo cp ./lib/*.h /usr/include/avg