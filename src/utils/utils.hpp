#pragma once

#include <functional>

namespace BlockyVulkan {

    // stolen from: https://stackoverflow.com/a/57595105
    template <typename T, typename... Rest>
    void HashCombine(std::size_t &seed, const T &v, const Rest &...rest) {
        seed ^= std::hash<T>{}(v) + 0x9e3779b9 /* Wtf is this idk... */ + (seed << 6) + (seed >> 2);
        (HashCombine(seed, rest), ...);
    }
}