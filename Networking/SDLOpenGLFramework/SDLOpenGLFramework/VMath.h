#pragma once
#include <math.h>
#include <stdio.h>

/// This is a library of Vec3 math routines.

#include "Vec3.h"

namespace  Game_Lib {
	class VMath {
	public:
		/// Calculate the dot product between Vec3s a & b
		inline static float VMath::dot(const Vec3 &a, const Vec3 &b) {
			return((a.x * b.x + a.y * b.y + a.z * b.z));
		}
		/// Normalize this vector
		static float Normalize(Vec3 &a);
		/// Calulate the cross product
		inline static const Vec3 VMath::cross(const Vec3 &a, const Vec3 &b) {
			return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
		}

		/// Return a normalized Vec3
		inline static Vec3 VMath::Normalize(const Vec3 &a) {
			float magnitude;
			Vec3 result;
			magnitude = mag(a);
			/// The Vector class watches for divide by zero errors
			result = Vec3(a.x / mag(a), a.y / mag(a), a.z / mag(a));
			return result;
		}

		inline static float VMath::mag(const Vec3 &a) {
			return(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
		}

		////////////////////////////////////////////////////////////////////////
		/// Extra just for fun stuff
		////////////////////////////////////////////////////////////////////////
		/// Reflect a normalized direction Vec3 off a plane
		static Vec3 reflect(const Vec3 v, const Plane3D p);

		/// Reflect a velocity Vec3 off a plane maintaining the original velocity
		static Vec3 reflect2(const Vec3 v, const Plane3D p);

		/// Get the distance between two Vec3s
		static float distance(const Vec3 &a, const Vec3 &b);

		/// Get the distance between a point (Vec3) and a plane
		static float distance(const Vec3 &v, const Plane3D &p);

		/// Get the distance between a sphere and a plane
		static float distance(const Sphere &s, const Plane3D &p);
	};
}