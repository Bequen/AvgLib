#pragma once

#include "float3.h"

namespace avg {
    namespace vector {
        float length2(avg::math::float3 vector);
        avg::math::float3 normalize(avg::math::float3 vector);
        float dot(avg::math::float3 vectorA, avg::math::float3 vectorB);
    };
};