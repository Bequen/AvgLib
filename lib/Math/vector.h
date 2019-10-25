#pragma once

#include "Math.h"

namespace avg::vector {
    inline float length(avg::math::float2 vector);
    inline float length(avg::math::float3 vector);
    inline float length(avg::math::float4 vector);

    inline float length2(avg::math::float2 vector);
    inline float length2(avg::math::float3 vector);
    inline float length2(avg::math::float4 vector);

    inline float dot(avg::math::float2 a, avg::math::float2 b);
    inline float dot(avg::math::float3 a, avg::math::float3 b);
    inline float dot(avg::math::float4 a, avg::math::float4 b);

    inline avg::math::float2 normalize(avg::math::float2 vector);
    inline avg::math::float3 normalize(avg::math::float3 vector);
    inline avg::math::float4 normalize(avg::math::float4 vector);

    inline float distance(avg::math::float2 a, avg::math::float2 b);
    inline float distance(avg::math::float3 a, avg::math::float3 b);
    inline float distance(avg::math::float4 a, avg::math::float4 b);
}