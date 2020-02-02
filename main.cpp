#include "avg/Terminal/Terminal.h"
#include <termios.h>
#include "avg/Path.h"
#include "avg/Debug.h"
#include <string.h>

#include "avg/Random/PerlinNoise.h"

// Only for testing purposes
int main() {
    PermutationTable permTable;
    permTable.init(3530);
    avg::PerlinNoise perlinNoise = avg::PerlinNoise(permTable);

    for(uint32_t x = 0; x < 1024; x++) {
        for(uint32_t y = y; y < 1024; y++) {
            std::cout << perlinNoise.eval(x * (1.0f / 128.0f), y * (1.0f / 128.0f), 1.0f) << std::endl;
        }
    }

    return 0;
}