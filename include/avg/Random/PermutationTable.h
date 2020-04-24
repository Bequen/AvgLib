#pragma once

#include <cstdint>

/**
 * @brief  Permutation table for usage in noise algorithms
 * @note   Permutation table is array of shuffled values from 0 to 256. It can be used for hashing so noise textures are truly random at much higher range
 * @retval None
 */
struct PermutationTable {
    uint32_t size;
    uint32_t sizeMask;
    uint32_t* permutationTable;

    void init(uint32_t seed);

    uint32_t& operator[](int32_t index);
};