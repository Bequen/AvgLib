#pragma once

#include <cstring>
#include <cstdint>

namespace String {
    char** split(const char* str, const char splitter, uint32_t* count);
    char** split(char* str, const char* splitters, uint32_t splitterCount, uint32_t* splitCount);

    char* concat(const char* str1, const char* str2);

    bool equals(const char* str1, const char* str2);
    bool startWith(const char* str, const char* startWith);
    bool endWith(const char* str, const char* endWith);

    uint32_t length(char* str);
}