#pragma once

#include <cstdint>

namespace avg::math {
    struct int3 {
        int32_t x, y, z;

        int3() :
        x(0), y(0), z(0) {

        }

        int3(int32_t x, int32_t y, int32_t z) :
        x(x), y(y), z(z) {

        }
    };
};