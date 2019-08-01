#include "vector.h"

#include <cmath>

#pragma region FLOAT
float avg::vector::length(avg::math::float2 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
} float avg::vector::length2(avg::math::float2 vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

float avg::vector::length(avg::math::float3 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
} float avg::vector::length2(avg::math::float3 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

float avg::vector::length(avg::math::float4 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
} float avg::vector::length2(avg::math::float4 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

avg::math::float2 avg::vector::normalize(avg::math::float2 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::float2(vector.x / length, vector.y / length);
} avg::math::float3 avg::vector::normalize(avg::math::float3 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::float3(vector.x / length, vector.y / length, vector.z / length);
} avg::math::float4 avg::vector::normalize(avg::math::float4 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::float4(vector.x / length, vector.y / length, vector.z / length);
} 

float avg::vector::dot(avg::math::float2 vectorA, avg::math::float2 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y;
} float avg::vector::dot(avg::math::float3 vectorA, avg::math::float3 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
} float avg::vector::dot(avg::math::float4 vectorA, avg::math::float4 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}
#pragma endregion

#pragma region INT

float avg::vector::length(avg::math::int2 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
} float avg::vector::length2(avg::math::int2 vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

float avg::vector::length(avg::math::int3 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
} float avg::vector::length2(avg::math::int3 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

float avg::vector::length(avg::math::int4 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
} float avg::vector::length2(avg::math::int4 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

avg::math::int2 avg::vector::normalize(avg::math::int2 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::int2(vector.x / length, vector.y / length);
} avg::math::int3 avg::vector::normalize(avg::math::int3 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::int3(vector.x / length, vector.y / length, vector.z / length);
} avg::math::int4 avg::vector::normalize(avg::math::int4 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::int4(vector.x / length, vector.y / length, vector.z / length);
} 

float avg::vector::dot(avg::math::int2 vectorA, avg::math::int2 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y;
} float avg::vector::dot(avg::math::int3 vectorA, avg::math::int3 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
} float avg::vector::dot(avg::math::int4 vectorA, avg::math::int4 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}

#pragma endregion