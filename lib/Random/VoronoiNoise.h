#pragma once

#include <cstdint>
#include <Math/float2.h>

class VoronoiNoise {
    public:
        uint32_t size;
        avg::math::float2* cells;
        unsigned permutationTable[256 * 2];

        void init(uint32_t seed, uint32_t size);

        avg::math::float2 normalize(avg::math::float2 vec);
        float eval(avg::math::float2 position);
};