#pragma once

namespace avg::math {
    struct float2 {
        float x, y;

        float2() :
        x(0.0f), y(0.0f) {

        }

        float2(float x, float y) :
        x(x), y(y) {

        }
    };
};