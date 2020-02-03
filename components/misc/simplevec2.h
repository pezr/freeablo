#pragma once
#include <cstdint>

template <typename T> class Vec2
{
public:
    Vec2() : x(0), y(0) {}
    Vec2(T x, T y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& other) { return Vec2(x + other.x, y + other.y); }
    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    // this trick lets us refer to the vector by x/y, or u/v, etc while still being the same underneath
    union
    {
        T x;
        T u;
        T start;
        T min;
    };

    union
    {
        T y;
        T v;
        T end;
        T max;
    };
};

using Vec2i = Vec2<int32_t>;
using IntRange = Vec2<int32_t>;
