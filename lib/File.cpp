#include "File.h"

#include <unistd.h>

avg::File::FileWatcher::FileWatcher(char* path) :
path(path) {
    lastCheck = 0;
}

bool avg::File::FileWatcher::check() {
    struct stat result;
    if(stat(path, &result)==0) {
        if(result.st_mtime > lastCheck) {
            lastCheck = result.st_mtime;
            return true;
        } else {
            return false;
        }
    } return false;
}