## AvgLib

AvgLib, stands for average library, is simple C++ library with feathures like Perlin Noise, File Watcher and Strings. My main focus is performance whilst delivering easy interface.

### Feathures
- [x] Perlin Noise
- [x] String management interface
- [x] File Watcher
- [x] Simple Content Pipeline
- [x] More noise functions!
- [ ] Noise Fractals

## How to Use?

This is a CMake library, this means you need to download the source code and put it to your project files. It is designed that way. Source files already contains CMakeLists.txt to compile successfully, so then, add `add_subdirectory("dirToThisLib")` to your main CMakeLists.txt.

Now, to actually use the library, add `target_link_library(YourTarget avg)`.

Meaning, the final CMakeFile would possibly look like this:

```
project(MyProject)

file(GLOB CPP_FILES
    ./*.cpp
) file (GLOB H_FILES 
    ./*.h
)

add_executable(${PROJECT_NAME} CPP_FILES H_FILES)

target_link_library(${PROJECT_NAME} avg)
```