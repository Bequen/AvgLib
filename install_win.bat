@echo off
mingw32-make lib_static
ar rcs libavg.a *.o

mkdir C:\MinGW\include\avg
mkdir C:\MinGW\include\avg\Math
move libavg.a C:\MinGW\lib\
copy .\lib\*.h C:\MinGW\include\avg\
copy .\lib\Math\*.h C:\MinGW\include\avg\Math\

del *.o