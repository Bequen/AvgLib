#pragma once

#include "float4.h"
#include "float3.h"
#include "float2.h"

#include "int4.h"
#include "int3.h"
#include "int2.h"

namespace avg {
    namespace vector {
        #pragma region FLOAT
        float length(avg::math::float2 vector);
        float length2(avg::math::float2 vector);

        float length(avg::math::float3 vector);
        float length2(avg::math::float3 vector);

        float length(avg::math::float4 vector);
        float length2(avg::math::float4 vector);

        avg::math::float2 normalize(avg::math::float2 vector);
        avg::math::float3 normalize(avg::math::float3 vector);
        avg::math::float4 normalize(avg::math::float4 vector);

        float dot(avg::math::float2 vectorA, avg::math::float2 vectorB);
        float dot(avg::math::float3 vectorA, avg::math::float3 vectorB);
        float dot(avg::math::float4 vectorA, avg::math::float4 vectorB);
        #pragma endregion


        #pragma region INT
        float length(avg::math::int2 vector);
        float length2(avg::math::int2 vector);

        float length(avg::math::int3 vector);
        float length2(avg::math::int3 vector);

        float length(avg::math::int4 vector);
        float length2(avg::math::int4 vector);

        avg::math::int2 normalize(avg::math::int2 vector);
        avg::math::int3 normalize(avg::math::int3 vector);
        avg::math::int4 normalize(avg::math::int4 vector);

        float dot(avg::math::int2 vectorA, avg::math::int2 vectorB);
        float dot(avg::math::int3 vectorA, avg::math::int3 vectorB);
        float dot(avg::math::int4 vectorA, avg::math::int4 vectorB);
        #pragma endregion
    };
};