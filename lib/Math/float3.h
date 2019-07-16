#pragma once

namespace avg::math {
    struct float3 {
        float x, y, z;

        float3() :
        x(0.0f), y(0.0f), z(0.0f) {

        }

        float3(float x, float y, float z) :
        x(x), y(y), z(z) {

        }
    };
};