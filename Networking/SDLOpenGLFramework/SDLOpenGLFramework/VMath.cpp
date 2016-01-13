#include "VMath.h"
using namespace Game_Lib;
Vec3 VMath::reflect(Vec3 v, Plane3D p) {
	Vec3 result;
	float scalar = 2.0f * dot(v, p);
	Vec3 temp = p * scalar;
	result = v - temp;
	return result;
}
Vec3 VMath::reflect2(Vec3 v, Plane3D p) {
	Vec3 result;
	float length = mag(v);
	v = Normalize(v);
	float scalar = 2.0f * dot(v, p);
	Vec3 temp = p * scalar;
	result = v - temp;
	result = result *  length;
	return result;
}
float VMath::Normalize(Vec3 &a) {
	float magnitude;
	magnitude = mag(a);
#ifdef DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!!
	if (fabs(magnitude) < VERY_SMALL) {
		std::string errorMsg("Divide by nearly zero! ");
		throw errorMsg;
	}
#endif
	a.x = a.x / magnitude;
	a.y = a.y / magnitude;
	a.z = a.z / magnitude;
	return magnitude;
}
float VMath::distance(const Vec3 &a, const Vec3 &b) {
	Vec3 r = a - b;
	return(mag(r));
}
float VMath::distance(const Vec3 &v, const Plane3D &p) {
	return (abs(v.x*p.x + v.y*p.y + v.z*p.z - p.d) / (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z)));
}
float VMath::distance(const Sphere &s, const Plane3D &p) {
	return distance((Vec3)s, p) - s.r;
}