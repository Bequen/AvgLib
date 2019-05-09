#include "lib/File.h"

#include <iostream>

int main() {
    avg::File::FileWatcher watcher = avg::File::FileWatcher("/home/martin/Projects/AvgLib/testFile.p");

    while(true) {
        if(watcher.check()) {
            std::cout << "test" << std::endl;
        }
    }
    
    return 0;
}