#pragma once
#include <string>
#include "Debug.h"

#ifndef VERY_SMALL
#define VERY_SMALL 1.0e-9
#endif
// Define PI , 3.14
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif
// Define Degrees to Radians
#ifndef DEGREES_TO_RADIANS
#define DEGREES_TO_RADIANS (M_PI / 180.0f)
#endif

namespace  Game_Lib {
	struct Vec2 {
		float  x, y;	///  Structures are default public!
		inline void Vec2::Load(float _x, float _y) {
			x = _x;
			y = _y;
		}
		/// Here's a set of constructors
		inline Vec2(float s = float(0.0)) {
			Load(s, s);
		}
		inline Vec2(float _x, float _y) {
			Load(_x, _y);
		}
		/// In this context "const" means I promise not to modify anything v points to
		inline Vec2(const Vec2& v) {
			Load(v.x, v.y);
		}

		/// Now we can use the Vec3 like an array but we'll need two overloads
		inline const float operator [] (int index) const {  /// This one is for reading the Vec3 as if where an array
			return *(&x + index);
		}
		inline float& operator [] (int index) { /// This one is for writing to the Vec3 as if where an array - check out the term lvalue
			return *(&x + index);
		}

		/// Add two Vec3s
		inline const Vec2 operator + (const Vec2& v) const {
			return Vec2(x + v.x, y + v.y);
		}

		/// Add a Vec3 to itself
		inline Vec2& operator += (const Vec2& v) {
			x += v.x;
			y += v.y;

			return *this;
		}

		/// Take the negative of a Vec3
		inline const Vec2 operator - () const {
			return Vec2(-x, -y);
		}

		/// Subtract two Vec3s
		inline Vec2 operator - (const Vec2& v) const {
			return Vec2(x - v.x, y - v.y);
		}

		/// Subtract a Vec 3 from itself
		inline Vec2& operator -= (const Vec2& v) {
			x -= v.x;
			y -= v.y;

			return *this;
		}

		/// Multiply a Vec3 by a scalar
		inline const Vec2  operator * (const float s) const {
			return Vec2(s*x, s*y);
		}

		/// Multiply a Vec3 by a scalar and assign it to itself
		inline Vec2& operator *= (const float s) {
			x *= s;
			y *= s;

			return *this;
		}

		/// Multiply a scaler by a Vec3  - Ha! It's the scalar first then the Vec3
		/// Overloaded and a friend, ouch! It's the only way to make it work with a scalar first.
		/// Friends are tricky, look them up.
		inline friend Vec2 operator * (const float s, const Vec2& v) {
			return v * s;
		}
		/// Multiply two Vectors
		Vec2  operator *  (const Vec2& v) const {
			return Vec2(x*v.x, y*v.y);
		}

		/// Divide by a scalar - Watch for divide by zero issues
		inline const Vec2 operator / (const float s) const {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				//Debug::Log(EMessageType::WARNING, "Vec2", "operator / ", __FILE__, __LINE__, __TIMESTAMP__, "Divided by 0 or nearly");
				throw errorMsg;
			}
#endif
			float r = 1.0f / s;
			return *this * r;
		}

		inline Vec2& operator /= (const float s) {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
			if (std::fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				//Debug::Log(EMessageType::WARNING, "Vec2", "operator / ", __FILE__, __LINE__, __TIMESTAMP__, "Divided by 0 or nearly");
				throw errorMsg;
			}
#endif // DEBUG
			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void print() {
			printf("%f %f \n", x, y);
		}
	};
	struct Vec3 :public Vec2 {
		float z;	///  Structures are default public!

		/// Just a little utility to populate a vector
		inline void Load(float _x, float _y, float _z) {
			x = _x; y = _y; z = _z;
		}

		/// Here's a set of constructors
		inline Vec3(float s = float(0.0)) {
			Load(s, s, s);
		}
		// Default Contructor
		inline Vec3(float _x, float _y, float _z) {
			Load(_x, _y, _z);
		}

		/// A copy constructor
		inline Vec3(const Vec3& v) {
			Load(v.x, v.y, v.z);
		}

		inline Vec3& operator = (const Vec3& v) {
			Load(v.x, v.y, v.z);
			return *this;
		}

		inline const float operator [] (int index) const {
			return *(&x + index);
		}

		inline float& operator [] (int index) {
			return *(&x + index);
		}

		/// Add two Vec3s
		inline const Vec3 operator + (const Vec3& v) const {
			return Vec3(x + v.x, y + v.y, z + v.z);
		}

		/// Add a Vec3 to itself
		inline Vec3& operator += (const Vec3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		/// Take the negative of a Vec3
		inline const Vec3 operator - () const {
			return Vec3(-x, -y, -z);
		}

		/// Subtract two Vec3s
		inline Vec3 operator - (const Vec3& v) const {
			return Vec3(x - v.x, y - v.y, z - v.z);
		}

		/// Subtract a Vec 3 from itself
		inline Vec3& operator -= (const Vec3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		/// Multiply a Vec3 by a scalar
		inline const Vec3  operator * (const float s) const {
			return Vec3(s*x, s*y, s*z);
		}

		/// Multiply a Vec3 by a scalar and assign it to itself
		inline Vec3& operator *= (const float s) {
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}

		/// Multiply a scaler by a Vec3  - Ha! It's the scalar first then the Vec3
		/// Overloaded and a friend, ouch! It's the only way to make it work with a scalar first.
		/// Friends are tricky, look them up.
		inline friend Vec3 operator * (const float s, const Vec3& v) {
			return v * s;
		}
		/// Multiply two Vectors
		Vec3  operator *  (const Vec3& v) const {
			return Vec3(x*v.x, y*v.y, z*v.z);
		}

		/// Divide by a scalar - Watch for divide by zero issues
		inline const Vec3 operator / (const float s) const {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif
			float r = 1.0f / s;
			return *this * r;
		}

		inline Vec3& operator /= (const float s) {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
			if (std::fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif // DEBUG
			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void print() {
			printf("%f %f %f\n", x, y, z);
		}
	};
	struct Vec4 : public Vec3 {
		///float  x;	///
		///float  y;	///  From Vec3
		///float  z;	///
		float  w;

		/// Here's a set of constructors
		inline Vec4(float s = float(0.0)) { x = s; y = s; z = s; w = s; }
		inline Vec4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }
		inline Vec4(const Vec4& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}
		inline Vec4(const Vec3& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = 1.0f;
		}

		/// An assignment operator
		inline Vec4& operator = (const Vec4& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			return *this;
		}

		/// See Vec3 definition
		inline float& operator [] (int index) {
			return *(&x + index);
		}
		inline const float operator [] (int i) const {
			return *(&x + i);
		}

		/// See Vec3 definition
		inline Vec4 operator + (const Vec4& v) const {
			return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
		}

		/// See Vec3 definition
		inline Vec4& operator += (const Vec4& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}

		//// See Vec3 definition
		inline Vec4 operator - () const {
			return Vec4(-x, -y, -z, -w);
		}

		/// See Vec3 definition
		inline Vec4 operator - (const Vec4& v) const {
			return Vec4(x - v.x, y - v.y, z - v.z, v.w - w);
		}

		/// See Vec3 definition
		inline Vec4& operator -= (const Vec4& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}

		/// See Vec3 definition
		inline Vec4 operator * (const float s) const {
			return Vec4(s*x, s*y, s*z, s*w);
		}

		/// See Vec3 definition
		inline Vec4& operator *= (const float s) {
			x *= s;
			y *= s;
			z *= s;
			w *= s;
			return *this;
		}

		/// See Vec3 definition
		friend Vec4 operator * (const float s, const Vec4& v) {
			return v * s;
		}
		/// Multiply two Vectors
		Vec4  operator *  (const Vec4& v) const {
			return Vec4(x*v.x, y*v.y, z*v.z, w*v.w);
		}

		inline Vec4 operator / (const float s) const {
#ifdef DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
			if (std::fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif
			float r = 1.0f / s;
			return *this * r;
		}

		inline Vec4& operator /= (const float s) {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
			if (std::fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif // DEBUG

			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void print() {
			printf("%f %f %f %f\n", x, y, z, w);
		}

		///
		/// Type conversion operators
		///
		inline operator const float* () const {
			return static_cast<const float*>(&x);
		}
		inline operator float* () {
			return static_cast<float*>(&x);
		}
	};
	struct Sphere : public Vec3 {
		float r;
		Sphere(float s = 0.0f) { x = s; y = s; z = s; r = s; }
		Sphere(float _x, float _y, float _z, float _r) {
			x = _x; y = _y; z = _z; r = _r;
		}
		inline Sphere(const Sphere& s) {
			x = s.x;  y = s.y;  z = s.z; r = s.r;
		}
		inline Sphere(const Vec3& v, float _r) {
			x = v.x;
			y = v.y;
			z = v.z;
			r = _r;
		}
	};
	struct circle :public Vec2 {
		float r;
		circle(float s = 0.0f) {
			x = s,
				y = s,
				r = s;
		}
		circle(float _x, float _y, float _r) {
			x = _x;
			y = _y;
			r = _r;
		}
		circle(const circle& c) {
			x = c.x;
			y = c.y;
			r = c.r;
		}
		circle(const Vec2& v, float _r) {
			x = v.x;
			y = v.y;
			r = _r;
		}
	};
	struct Plane3D : public Vec3 {
		float d;
		/// Here's a set of constructors
		inline Plane3D(float s = 0.0f) {
			x = s;
			y = s;
			z = s;
			d = s;
		}
		inline Plane3D(float _x, float _y, float _z, float _d) {
			x = _x;
			y = _y;
			z = _z;
			d = _d;
		}
		inline Plane3D(const Plane3D& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			d = v.d;
		}
		inline Plane3D(const Vec3& v, float _d) {
			x = v.x;
			y = v.y;
			z = v.z;
			d = _d;
		}
	};
	struct Plane2D :public Vec2 {
		float d;
		Plane2D(float s = 0.0f) {
			x = s;
			y = s;
			d = s;
		}
		Plane2D(float _x, float _y, float _d) {
			x = _x;
			y = _y;
			d = _d;
		}
		Plane2D(const Vec2& v, float _d) {
			x = v.x;
			y = v.y;
			d = _d;
		}
		Plane2D(const Plane2D& p) {
			x = p.x;
			y = p.y;
			d = p.d;
		}
	};

	struct Cube : public Vec3 {
		float d;
		inline Cube(float _x, float _y, float _z, float _d) {
			x = _x;
			y = _y;
			z = _z;
			d = _d;
		}
		inline Cube(float _d = 0.0) {
			x = _d;
			y = _d;
			z = _d;
			d = _d;
		}
		inline Cube(const Vec3& v, float _d) {
			x = v.x;
			y = v.y;
			z = v.z;
			d = _d;
		}
		inline Cube(const Cube& c) {
			x = c.x;
			y = c.y;
			z = c.z;
			d = c.d;
		}
	};
	struct Square : public Vec2 {
		float d;
		inline Square(float _d = 0.0f) {
			x = _d;
			y = _d;
			d = _d;
		}
		inline Square(float _x, float _y, float _d) {
			x = _x;
			y = _y;
			d = _d;
		}
		inline Square(Vec2& v, float _d) {
			x = v.x;
			y = v.y;
			d = _d;
		}
		inline Square(Square& s) {
			x = s.x;
			y = s.y;
			d = s.d;
		}
	};
	struct Rectangle :public Vec2 {
		float h, w;
		inline Rectangle(const float _x, const float _y, const float _h, const float _w) {
			x = _x; y = _y; h = _h; w = _w;
		}
		inline Rectangle(Vec2& v, const float _h, const float _w) {
			x = v.x;
			y = v.y;
			h = _h;
			w = _w;
		}
		inline Rectangle(Rectangle& r) {
			x = r.x;
			y = r.y;
			h = r.w;
			w = r.w;
		}
	};
}
