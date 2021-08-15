#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "iostream"

void write_color(std::ostream &out, color pixel_color, int samplesPerPixels) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // 色の合計をサンプルの数で割り、gamma=2.0のガンマ補正を行う
    auto scale = 1.0 / samplesPerPixels;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    // 各成分を[0,255]に変換して出力
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif
