#pragma once
#include <cmath>

namespace vec2 {
    template <typename T>
    struct Vector2 {
        T x;
        T y;
        
        Vector2(T _x = T(0), T _y = T(0)) : x(_x), y(_y) {}

        // CONVERSION
        template <typename U>
        Vector2(const Vector2<U>& other) : x((T)other.x), y((T)other.y) {}

        // STATIC
        static Vector2<T> zero() { return Vector2<T>(T(0), T(0)); }
        static Vector2<T> xAxis() { return Vector2<T>(T(1), T(0)); }
        static Vector2<T> yAxis() { return Vector2<T>(T(0), T(1)); }
        static Vector2<T> one() { return Vector2<T>(T(1), T(1)); }

        Vector2<T> operator+(const Vector2<T>& other) const {
            return { x + other.x, y + other.y };
        }
        Vector2<T> operator-(const Vector2<T>& other) const {
            return { x - other.x, y - other.y };
        }
        Vector2<T> operator*(const Vector2<T>& other) const {
            return { x * other.x, y * other.y };
        }
        Vector2<T> operator/(const Vector2<T>& other) const {
            return { x / other.x, y / other.y };
        }
        Vector2<T> operator-() const {
            return { -x, -y };
        }

        Vector2<T> operator*(const T& scalar) const {
            return { x * scalar, y * scalar };
        }
        friend Vector2<T> operator*(const T& scalar, const Vector2<T>& v) {
            return { v.x * scalar, v.y * scalar };
        }

        Vector2<T> operator/(const T& scalar) const {
            return { x / scalar, y / scalar };
        }
        friend Vector2<T> operator/(const T& scalar, const Vector2<T>& v) {
            return { v.x / scalar, v.y / scalar };
        }

        T magnitudeSquare() const {
            return x * x + y * y;
        }
        T magnitude() const {
            return std::sqrt(x * x + y * y);
        }
        
        Vector2<T> unit() const {
            T mag = magnitude();
            if (mag < T(1e-10)) return { T(0), T(0) };
            return { x / mag, y / mag };
        }

        T dot(const Vector2<T>& other) const {
            return x * other.x + y * other.y;
        }

        T angle(const Vector2<T>& other) const {
            T m = magnitude() * other.magnitude();
            if (m < T(1e-10)) return T(1.57079632679);
            return std::acos(dot(other) / m);
        }
    };

    using Vector2f = Vector2<float>;
    using Vector2d = Vector2<double>;
}