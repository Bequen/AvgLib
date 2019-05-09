#include "String.h"

#include <iostream>

char** String::split(const char* str, const char splitter, uint32_t* splitCount) {
    uint32_t length = 0;
    for( ; str[length] != '\0'; length++) {
        if(str[length] == splitter && (str[length - 1] != splitter)) {
            *splitCount += 1;
        }
    }

    *splitCount += 1;

    char* resultStr = new char[length + 1];
    memcpy(resultStr, str, length);
    resultStr[length] = '\0';

    char** splits = new char*[*splitCount];
    uint32_t index = 1;

    splits[0] = &resultStr[0];
    for(uint32_t i = 0; i < length; i++) {
        if(str[i] == splitter) {
            resultStr[i] = '\0';
            splits[index] = &resultStr[i + 1];
            if(resultStr[i - 1] == '\0') {
                splits[index - 1]++;
            } else {
                index++;
            }
        }
    }

    return splits;
}

char** String::split(char* str, const char* splitters, uint32_t splitterCount, uint32_t* splitCount) {
    for(uint32_t i = 0; str[i] != '\0'; i++) {
        for(uint32_t x = 0; x < splitterCount; x++) {
            if(str[i] == splitters[x])
                str[i] = splitters[0];
        }
    }
    
    uint32_t length = 0;
    for( ; str[length] != '\0'; length++) {
        if(str[length] == splitters[0] && (str[length - 1] != splitters[0])) {
            *splitCount += 1;
        }
    }

    *splitCount += 1;

    char* resultStr = new char[length + 1];
    memcpy(resultStr, str, length);
    resultStr[length] = '\0';

    char** splits = new char*[*splitCount];
    uint32_t index = 1;

    splits[0] = &resultStr[0];
    for(uint32_t i = 0; i < length; i++) {
        if(str[i] == splitters[0]) {
            resultStr[i] = '\0';
            splits[index] = &resultStr[i + 1];
            if(resultStr[i - 1] == '\0') {
                splits[index - 1]++;
            } else {
                index++;
            }
        }
    }

    return splits;
}

char* String::concat(const char* str1, const char* str2) {
    uint32_t length1, length2;
    
    for(length1 = 0; str1[length1] != '\0'; length1++) {
        
    }
}

bool String::equals(const char* str1, const char* str2) {
    uint32_t i = 0;

    for(; str1[i] == str2[i]; i++) {
        if(str1[i] == '\0') {
            return true;
        }
    }

    return false;
}

uint32_t String::length(char* str) {
    uint32_t i = 0;
    for(; str[i] != '\0'; i++) { }

    return i;
}