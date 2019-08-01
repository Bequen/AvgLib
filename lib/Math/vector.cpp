#include "vector.h"

#include <cmath>

float avg::vector::length2(avg::math::float3 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

avg::math::float3 avg::vector::normalize(avg::math::float3 vector) {
    float length = std::sqrt(avg::vector::length2(vector));
    return avg::math::float3(vector.x / length, vector.y / length, vector.z / length);
}

float avg::vector::dot(avg::math::float3 vectorA, avg::math::float3 vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}