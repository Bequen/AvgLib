#pragma once

#include <glm/glm.hpp>
#include <cstdint>

namespace avg {
    class PerlinNoise {
        public:
            uint32_t seed;
            uint32_t size;
            uint32_t sizeMask;
            uint32_t* permutationTable;

            glm::vec3* gradients;

            PerlinNoise();

            float eval(float x, float y, float z);
            float smoothstep(float a);
            int32_t hash(int32_t x, int32_t y, int32_t z);
            float lerp(float a, float b, float t);
    };
};