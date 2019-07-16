#include "ContentPipeline.h"

#include <iostream>
#include <fstream>

char* avg::ContentPipeline::loadText(const char* path) {
    std::ifstream stream = std::ifstream(path, std::ios::ate);

    #if DEBUG
    if(!stream.is_open())
        std::cout << "Couldn't open file." << std::endl;
    #endif

    uint32_t size = stream.tellg();

    stream.seekg(0);
    char* buffer = new char[size + 1];

    stream.read(buffer, size); 
    buffer[size] = '\0';

    stream.close();
    return buffer;
}