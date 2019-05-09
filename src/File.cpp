#include "File.h"

#include <unistd.h>

File::FileWatcher::FileWatcher(char* path) :
path(path) {

}

bool File::FileWatcher::check() {
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