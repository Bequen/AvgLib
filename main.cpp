#include "avg/Terminal/Terminal.h"
#include <termios.h>
#include "avg/Path.h"
#include <string.h>

// Only for testing purposes
int main() {
    char* path = new char[256];
    memcpy(path, "ahoj/jak/to/jde/kamo.exe", sizeof("ahoj/jak/to/jde/kamo.exe"));
    char* file = avg::Path::get_path(path);

    std::cout << file << std::endl;
    return 0;
}