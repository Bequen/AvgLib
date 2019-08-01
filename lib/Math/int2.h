#pragma once

#include <cstdint>

namespace avg::math {
    struct int2 {
        int32_t x, y;

        int2() :
        x(0), y(0) {

        }

        int2(int32_t x, int32_t y) :
        x(x), y(y) {

        }
    };
};