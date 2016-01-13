#pragma once
#include "VMath.h"

namespace  Game_Lib {
	struct Quaternion : public Vec3 {
		float w;

		/// Just a little utility to populate a quaternion
		inline void load(float _w, float _x, float _y, float _z) {
			w = _w; x = _x; y = _y; z = _z;
		}

		/// This is the unit quaterion by definition
		inline Quaternion() {
			load(1.0f, 0.0f, 0.0f, 0.0f);
		}

		inline Quaternion(float _w, float _x, float _y, float _z) {
			load(_w, _x, _y, _z);
		}

		/// This is the  constructor
		/// The w component is  degrees and n is the axis of rotations
		inline Quaternion(float angle, const Vec3& n) {
			angle *= DEGREES_TO_RADIANS; ///
			load(cos(angle / 2.0f), sin(angle / 2.0f)*n.x, sin(angle / 2.0f)*n.y, sin(angle / 2.0f)*n.z);
		}

		/// A copy constructor
		inline Quaternion(const Quaternion& q) {
			load(q.w, q.x, q.y, q.z);
		}
		inline Quaternion(const Vec4& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}
		/// An assignment operator
		inline Quaternion& operator = (const Quaternion& q) {
			load(q.w, q.x, q.y, q.z);
			return *this;
		}

		/// Take the negative of a Quaternion
		inline const Quaternion operator - () const {
			return Quaternion(-w, -x, -y, -z);
		}

		/// Multiply a two quaternions - using the right-hand rule
		inline const Quaternion operator * (const Quaternion& q) const {
			Vec3 ijk(w*q + q.w * (*this) + VMath::cross(*this, q));
			return Quaternion(w * q.w - VMath::dot(*this, q), ijk.x, ijk.y, ijk.z);
		}

		/// Multiply a quaternion by a Vec3
		inline const Quaternion operator * (const Vec4& v) const {
			Vec3 ijk(w*v + v.w * (*this) + VMath::cross(*this, v));
			return Quaternion(w * v.w - VMath::dot(*this, v), ijk.x, ijk.y, ijk.z);
		}

		inline const Quaternion conjugate() const {
			return Quaternion(w, -x, -y, -z);
		}

		inline Vec3 rotate(const Vec3& v) {
			/// This is the standard q*v*q^-1
			///return Vec3( (*this) * v * (*this).conjugate());

			/// I read a paper that shows this way to be faster
			Vec3 v2 = VMath::cross(*this, v);
			return v + v2 * (2.0f*w) + VMath::cross(*this, v2) * 2.0f;
		}

		inline void print() {
			printf("%f %f %f %f\n", w, x, y, z);
		}
	};
}