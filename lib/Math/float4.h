#pragma once

namespace avg::math {
    struct float4 {
        float x, y, z, w;

        float4() :
        x(0.0f), y(0.0f), z(0.0f), w(1.0f) {

        }

        float4(float x, float y, float z) :
        x(x), y(y), z(z), w(1.0f) {

        }

        float4(float x, float y, float z, float w) :
        x(x), y(y), z(z), w(w) {

        }
    };
};