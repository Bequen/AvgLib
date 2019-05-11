#include <avg/File.h>
#include <cstdint>

// Only for testing purposes
int main() {
    avg::File::FileWatcher file = avg::File::FileWatcher("/home/martin/Projects/avgLib/test.txt");
    return 0;
}