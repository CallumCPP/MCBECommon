#ifndef MATH_HPP
#define MATH_HPP

namespace Common {
    namespace Math {
        template <typename T>
        struct Vec4 {
            T x, y, z, w;

            Vec4() : x(0), y(0), z(0), w(0) {}
            Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
            
            Vec4<T> operator+=(const Vec4<T> other) {
                x += other.x;
                y += other.y;
                z += other.z;
                w += other.w;
                return *this;
            }

            Vec4<T> operator-=(const Vec4<T> other) {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                w -= other.w;
                return *this;
            }

            Vec4<T> operator*=(const Vec4<T> other) {
                x *= other.x;
                y *= other.y;
                z *= other.z;
                w *= other.w;
                return *this;
            }

            Vec4<T> operator/=(const Vec4<T> other) {
                x /= other.x;
                y /= other.y;
                z /= other.z;
                w /= other.w;
                return *this;
            }

            Vec4<T> operator+=(const T other) {
                x += other;
                y += other;
                z += other;
                w += other;
                return *this;
            }

            Vec4<T> operator-=(const T other) {
                x -= other;
                y -= other;
                z -= other;
                w -= other;
                return *this;
            }

            Vec4<T> operator*=(const T other) {
                x *= other;
                y *= other;
                z *= other;
                w *= other;
                return *this;
            }

            Vec4<T> operator/=(const T other) {
                x /= other;
                y /= other;
                z /= other;
                w /= other;
                return *this;
            }

            Vec4<T> operator+(const Vec4<T> other) { return Vec4<T>(x + other.x, y + other.y, z + other.z, w + other.w); }
            Vec4<T> operator-(const Vec4<T> other) { return Vec4<T>(x - other.x, y - other.y, z - other.z, w - other.w); }
            Vec4<T> operator*(const Vec4<T> other) { return Vec4<T>(x * other.x, y * other.y, z * other.z, w * other.w); }
            Vec4<T> operator/(const Vec4<T> other) { return Vec4<T>(x / other.x, y / other.y, z / other.z, w / other.w); }

            Vec4<T> operator+(const T other) { return Vec4<T>(x + other, y + other, z + other, w + other); }
            Vec4<T> operator-(const T other) { return Vec4<T>(x - other, y - other, z - other, w - other); }
            Vec4<T> operator*(const T other) { return Vec4<T>(x * other, y * other, z * other, w * other); }
            Vec4<T> operator/(const T other) { return Vec4<T>(x / other, y / other, z / other, w / other); }

            bool operator==(const Vec4<T> other) { return x == other.x && y == other.y && z == other.z && w == other.w; }
            bool operator!=(const Vec4<T> other) { return !(*this == other); }

            Vec4<T> operator-() { return Vec4<T>(-x, -y, -z, -w); }

            static Vec4<T> Lerp(const Vec4<T> one, const Vec4<T> two, float t) {
                return Vec4<T>(
                    (two.x-one.x)*t,
                    (two.y-one.y)*t,
                    (two.z-one.z)*t,
                    (two.w-one.w)*t
                );
            }
        };

        template <typename T>
        struct Vec3 {
            T x, y, z;

            Vec3() : x(0), y(0), z(0) {}
            Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

            Vec3<T> operator+=(const Vec3<T> other) {
                x += other.x;
                y += other.y;
                z += other.z;
                return *this;
            }

            Vec3<T> operator-=(const Vec3<T> other) {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                return *this;
            }

            Vec3<T> operator*=(const Vec3<T> other) {
                x *= other.x;
                y *= other.y;
                z *= other.z;
                return *this;
            }

            Vec3<T> operator/=(const Vec3<T> other) {
                x /= other.x;
                y /= other.y;
                z /= other.z;
                return *this;
            }

            Vec3<T> operator+=(const T other) {
                x += other;
                y += other;
                z += other;
                return *this;
            }

            Vec3<T> operator-=(const T other) {
                x -= other;
                y -= other;
                z -= other;
                return *this;
            }

            Vec3<T> operator*=(const T other) {
                x *= other;
                y *= other;
                z *= other;
                return *this;
            }

            Vec3<T> operator/=(const T other) {
                x /= other;
                y /= other;
                z /= other;
                return *this;
            }

            Vec3<T> operator+(const Vec3<T> other) { return Vec3<T>(x + other.x, y + other.y, z + other.z); }
            Vec3<T> operator-(const Vec3<T> other) { return Vec3<T>(x - other.x, y - other.y, z - other.z); }
            Vec3<T> operator*(const Vec3<T> other) { return Vec3<T>(x * other.x, y * other.y, z * other.z); }
            Vec3<T> operator/(const Vec3<T> other) { return Vec3<T>(x / other.x, y / other.y, z / other.z); }

            Vec3<T> operator+(const T other) { return Vec3<T>(x + other, y + other, z + other); }
            Vec3<T> operator-(const T other) { return Vec3<T>(x - other, y - other, z - other); }
            Vec3<T> operator*(const T other) { return Vec3<T>(x * other, y * other, z * other); }
            Vec3<T> operator/(const T other) { return Vec3<T>(x / other, y / other, z / other); }

            bool operator==(const Vec3<T> other) { return (x == other.x && y == other.y && z == other.z); }
            bool operator!=(const Vec3<T>& other) { return !(*this == other); }

            Vec3<T> operator-() const { return Vec3<T>(-x, -y, -z); }

            static Vec3<T> Lerp(const Vec3<T> one, const Vec3<T> two, float t) {
                return Vec3<T>(
                    (two.x-one.x)*t,
                    (two.y-one.y)*t,
                    (two.z-one.z)*t
                );
            }
        };

        template <typename T>
        struct Vec2 {
            T x, y;

            Vec2() : x(0), y(0) {}
            Vec2(T x, T y) : x(x), y(y) {}

            void operator+=(const Vec2<T> other) {
                x += other.x;
                y += other.y;
            }

            void operator-=(const Vec2<T> other) {
                x -= other.x;
                y -= other.y;
            }

            void operator*=(const Vec2<T> other) {
                x *= other.x;
                y *= other.y;
            }

            void operator/=(const Vec2<T> other) {
                x /= other.x;
                y /= other.y;
            }

            void operator+=(const T other) {
                x += other;
                y += other;
            }

            void operator-=(const T other) {
                x -= other;
                y -= other;
            }

            void operator*=(const T other) {
                x *= other;
                y *= other;
            }

            void operator/=(const T other) {
                x /= other;
                y /= other;
            }
            
            Vec2<T> operator+(const Vec2<T> other) { return Vec2<T>(x + other.x, y + other.y); }
            Vec2<T> operator-(const Vec2<T> other) { return Vec2<T>(x - other.x, y - other.y); }
            Vec2<T> operator*(const Vec2<T> other) { return Vec2<T>(x * other.x, y * other.y); }
            Vec2<T> operator/(const Vec2<T> other) { return Vec2<T>(x / other.x, y / other.y); }

            Vec2<T> operator+(const T other) { return Vec2<T>(x + other, y + other); }
            Vec2<T> operator-(const T other) { return Vec2<T>(x - other, y - other); }
            Vec2<T> operator*(const T other) { return Vec2<T>(x * other, y * other); }
            Vec2<T> operator/(const T other) { return Vec2<T>(x / other, y / other); }

            bool operator==(const Vec2<T> other) const { return (x == other.x && y == other.y); }
            bool operator!=(const Vec2<T> other) const { return !(*this == other); }

            Vec2<T> operator-() { return Vec2<T>(-x, -y); }

            static Vec2<T> Lerp(const Vec2<T> one, const Vec2<T> two, float t) {
                return Vec2<T>(
                    (two.x-one.x)*t,
                    (two.y-one.y)*t
                );
            }
        };
    }
}

#endif /* MATH_HPP */
