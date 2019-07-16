#include "PerlinNoise.h"

#include <random>
#include <functional>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <glm/gtx/norm.hpp>

avg::PerlinNoise::PerlinNoise() : 
seed(2016), gradients(new glm::vec3[256]), size(256), sizeMask(255), permutationTable(new uint32_t[256 * 3]){
    std::mt19937 generator(2016);
    std::uniform_real_distribution distribution;
    auto dice = std::bind(distribution, generator);
    float gradientLen2;
    for (unsigned i = 0; i < size; ++i) {
        do {
            gradients[i] = glm::vec3(2 * dice() - 1, 2 * dice() - 1, 2 * dice() - 1);
            gradientLen2 = glm::length2(gradients[i]);
        } while (gradientLen2 > 1);
        gradients[i] = glm::normalize(gradients[i]); // normalize gradient
        permutationTable[i] = i;
    }

    std::uniform_int_distribution distributionInt;
    auto diceInt = std::bind(distributionInt, generator);
    // create permutation table
    for (unsigned i = 0; i < size; ++i)
        std::swap(permutationTable[i], permutationTable[diceInt() & sizeMask]);
    // extend the permutation table in the index range [256:512]
    for (unsigned i = 0; i < size; ++i) {
        permutationTable[size + i] = permutationTable[i];
    }
}

PerlinNoise::PerlinNoise(uint32_t seed) :
seed(seed), gradients(new glm::vec3[256]), size(256), sizeMask(255), permutationTable(new uint32_t[256 * 3]) {
    std::mt19937 generator(seed);
    std::uniform_real_distribution distribution;
    auto dice = std::bind(distribution, generator);
    float gradientLen2;
    for (unsigned i = 0; i < size; ++i) {
        do {
            gradients[i] = glm::vec3(2 * dice() - 1, 2 * dice() - 1, 2 * dice() - 1);
            gradientLen2 = glm::length2(gradients[i]);
        } while (gradientLen2 > 1);
        gradients[i] = glm::normalize(gradients[i]); // normalize gradient
        permutationTable[i] = i;
    }

    std::uniform_int_distribution distributionInt;
    auto diceInt = std::bind(distributionInt, generator);
    // create permutation table
    for (unsigned i = 0; i < size; ++i)
        std::swap(permutationTable[i], permutationTable[diceInt() & sizeMask]);
    // extend the permutation table in the index range [256:512]
    for (unsigned i = 0; i < size; ++i) {
        permutationTable[size + i] = permutationTable[i];
    }
}

int32_t avg::PerlinNoise::hash(int32_t x, int32_t y, int32_t z) {
    return permutationTable[permutationTable[permutationTable[x] + y] + z];
}

float avg::PerlinNoise::smoothstep(float t) {
    //return a * a * (3 - 2 * a);
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float avg::PerlinNoise::lerp(float a, float b, float t) {
    return a * (1 - t) + b * t;
}

float avg::PerlinNoise::eval(float x, float y, float z) {
        int xi0 = ((int)std::floor(x)) & sizeMask; 
        int yi0 = ((int)std::floor(y)) & sizeMask; 
        int zi0 = ((int)std::floor(z)) & sizeMask; 
 
        int xi1 = (xi0 + 1) & sizeMask; 
        int yi1 = (yi0 + 1) & sizeMask; 
        int zi1 = (zi0 + 1) & sizeMask; 
 
        float tx = x - ((int)std::floor(x)); 
        float ty = y - ((int)std::floor(y)); 
        float tz = z - ((int)std::floor(z)); 
 
        float u = smoothstep(tx); 
        float v = smoothstep(ty); 
        float w = smoothstep(tz); 
 
        // gradients at the corner of the cell
        const glm::vec3 &c000 = gradients[hash(xi0, yi0, zi0)]; 
        const glm::vec3 &c100 = gradients[hash(xi1, yi0, zi0)]; 
        const glm::vec3 &c010 = gradients[hash(xi0, yi1, zi0)]; 
        const glm::vec3 &c110 = gradients[hash(xi1, yi1, zi0)]; 
 
        const glm::vec3 &c001 = gradients[hash(xi0, yi0, zi1)]; 
        const glm::vec3 &c101 = gradients[hash(xi1, yi0, zi1)]; 
        const glm::vec3 &c011 = gradients[hash(xi0, yi1, zi1)]; 
        const glm::vec3 &c111 = gradients[hash(xi1, yi1, zi1)]; 
 
        // generate vectors going from the grid points to p
        float x0 = tx, x1 = tx - 1; 
        float y0 = ty, y1 = ty - 1; 
        float z0 = tz, z1 = tz - 1; 
 
        glm::vec3 p000 = glm::vec3(x0, y0, z0); 
        glm::vec3 p100 = glm::vec3(x1, y0, z0); 
        glm::vec3 p010 = glm::vec3(x0, y1, z0); 
        glm::vec3 p110 = glm::vec3(x1, y1, z0); 
 
        glm::vec3 p001 = glm::vec3(x0, y0, z1); 
        glm::vec3 p101 = glm::vec3(x1, y0, z1); 
        glm::vec3 p011 = glm::vec3(x0, y1, z1); 
        glm::vec3 p111 = glm::vec3(x1, y1, z1); 
 
        // linear interpolation
        float a = lerp(dot(c000, p000), dot(c100, p100), u); 
        float b = lerp(dot(c010, p010), dot(c110, p110), u); 
        float c = lerp(dot(c001, p001), dot(c101, p101), u); 
        float d = lerp(dot(c011, p011), dot(c111, p111), u); 
 
        float e = lerp(a, b, v); 
        float f = lerp(c, d, v); 
 
        return lerp(e, f, w) + 0.5f; // g 
}