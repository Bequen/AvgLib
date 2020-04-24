#include "avg/File.h"

#include <unistd.h>
#include <sys/sysinfo.h>

avg::FileWatcher::FileWatcher() {
    path = nullptr;
    lastCheck = 0;
}

avg::FileWatcher::FileWatcher(char* path) :
path(path) {
    lastCheck = 0;
}

bool avg::FileWatcher::check() {
    if(path != nullptr) {
        struct stat result;
        if(stat(path, &result)==0) {
            if(result.st_mtime > lastCheck) {
                lastCheck = result.st_mtime;
                return true;
            } else {
                return false;
            }
        } return false;
    } return false;
}

void avg::FileWatcher::assign(char* path) {
    this->path = path;
}