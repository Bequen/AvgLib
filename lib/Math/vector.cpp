#include "vector.h"

#include <cmath>

float avg::vector::length(avg::math::float2 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
} float avg::vector::length(avg::math::float3 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
} float avg::vector::length(avg::math::float4 vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float avg::vector::length2(avg::math::float2 vector) {
    return vector.x * vector.x + vector.y * vector.y;
} float avg::vector::length2(avg::math::float3 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
} float avg::vector::length2(avg::math::float4 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

inline float dot(avg::math::float2 a, avg::math::float2 b) {
    return a.x * b.x + a.y * b.y;
} inline float dot(avg::math::float3 a, avg::math::float3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
} inline float dot(avg::math::float4 a, avg::math::float4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline avg::math::float2 normalize(avg::math::float2 vector) {
    float magnitude = avg::vector::length(vector);
    return avg::math::float2(vector.x / magnitude, vector.y / magnitude);
} inline avg::math::float3 normalize(avg::math::float3 vector) {
    float magnitude = avg::vector::length(vector);
    return avg::math::float3(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude);
} inline avg::math::float4 normalize(avg::math::float4 vector) {
    float magnitude = avg::vector::length(vector);
    return avg::math::float4(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude);
}