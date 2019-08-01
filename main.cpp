
#include "lib/Debug.h"


#include <iostream>

// Only for testing purposes
int main() {
    debug_init();

    ERROR("error");
    MESSAGE("message");
    SUCCESS("success");
    WARNING("warning");

    std::cout << "test" << std::endl;

    return 0;
}