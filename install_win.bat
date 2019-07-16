@echo off
mingw32-make lib_static

move *.o  C:/MinGW/lib/
mkdir C:\MinGW\include\avg
mkdir C:\MinGW\include\avg\Math
copy .\lib\*.h C:\MinGW\include\avg\
copy .\lib\Math\*.h C:\MinGW\include\avg\Math\