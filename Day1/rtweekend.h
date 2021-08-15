#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include "cmath"
#include "cstdlib"
#include "limits"
#include "memory"
#include "random"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180;
}

inline std::mt19937 initialize_seed() {
    std::random_device randomDevice;
    std::vector<uint32_t> randomSeedVector(10);
    std::generate(randomSeedVector.begin(), randomSeedVector.end(), std::ref(randomDevice));
    std::seed_seq randomSeed(randomSeedVector.begin(), randomSeedVector.end());
    std::mt19937 generator(randomSeed);
    return generator;
}

inline double random_double() {
    // [0,1)の実数乱数を返す
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator = initialize_seed();
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // [min,max)の実数乱数を返す
    return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max){
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#include "ray.h"
#include "vec3.h"

#endif