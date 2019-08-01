@echo off
mingw32-make lib_static >nul
ar rcs libavg.a *.o

echo Installing the AvgLib

echo Creating directories
mkdir C:\MinGW\include\avg 2>nul
mkdir C:\MinGW\include\avg\Math 2>nul
move libavg.a C:\MinGW\lib\ >nul

echo Removing previous version
del C:\MinGW\include\avg\Math\* /Q >nul
del C:\MinGW\include\avg\* /Q >nul

echo Installing new version
copy .\lib\*.h C:\MinGW\include\avg\ >nul
copy .\lib\Math\*.h C:\MinGW\include\avg\Math\ >nul


for /R "C:\MinGW\include\avg" %%f in (*.h) do (
    rename %%f %%~nf 
)

del *.o
echo Installation was successfull