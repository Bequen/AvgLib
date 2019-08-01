#pragma once

#include <cstdint>

namespace avg::math {
    struct int4 {
        int32_t x, y, z, w;

        int4() :
        x(0), y(0), z(0), w(1) {

        }

        int4(int32_t x, int32_t y, int32_t z) :
        x(x), y(y), z(z), w(1) {

        }

        int4(int32_t x, int32_t y, int32_t z, int32_t w) :
        x(x), y(y), z(z), w(w) {

        }
    };
};