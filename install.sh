#!/bin/bash

make lib_static
ar rcs libavg.a *.o

sudo rm -r /usr/include/avg
sudo mkdir /usr/include/avg
sudo mv libavg.a /usr/lib64/

sudo cp ./lib/*.h /usr/include/avg

rm *.o