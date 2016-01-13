#include "VMath.h"
#include "MMath.h"
using namespace Game_Lib;
///Tested Feb 2 2013 SSF
Matrix4 MMath::rotate4x4(float angle, float x, float y, float z) {
	float cosang, sinang, cosm;
	Matrix4 m;
	Vec3 rotAxis(x, y, z);
	rotAxis = VMath::Normalize(rotAxis);

	angle *= float(DEGREES_TO_RADIANS);
	cosang = cos(angle);
	sinang = sin(angle);
	cosm = (1.0f - cosang);

	m[0] = (rotAxis.x * rotAxis.x * cosm) + cosang;
	m[1] = (rotAxis.x * rotAxis.y * cosm) + (rotAxis.z * sinang);
	m[2] = (rotAxis.x * rotAxis.z * cosm) - (rotAxis.y * sinang);
	m[3] = 0.0;
	m[4] = (rotAxis.x * rotAxis.y * cosm) - (rotAxis.z * sinang);
	m[5] = (rotAxis.y * rotAxis.y * cosm) + cosang;
	m[6] = (rotAxis.y * rotAxis.z * cosm) + (rotAxis.x * sinang);
	m[7] = 0.0;
	m[8] = (rotAxis.x * rotAxis.z * cosm) + (rotAxis.y * sinang);
	m[9] = (rotAxis.y * rotAxis.z * cosm) - (rotAxis.x * sinang);
	m[10] = (rotAxis.z * rotAxis.z * cosm) + cosang;
	m[11] = 0.0;
	m[12] = 0.0;
	m[13] = 0.0;
	m[14] = 0.0;
	m[15] = 1.0;
	return m;
}
Matrix3 MMath::rotate3x3(float angle, float x, float y, float z)
{
	float cosang, sinang, cosm;
	Matrix3 m;
	Vec3 rotAxis(x, y, z);
	angle *= float(DEGREES_TO_RADIANS);
	cosang = cos(angle);
	sinang = sin(angle);
	cosm = (1.0f - cosang);

	m[0] = (rotAxis.x * rotAxis.x * cosm) + cosang;
	m[1] = (rotAxis.x * rotAxis.y * cosm) + (rotAxis.z * sinang);
	m[2] = (rotAxis.x * rotAxis.z * cosm) - (rotAxis.y * sinang);
	m[3] = 0.0;
	m[4] = (rotAxis.x * rotAxis.y * cosm) - (rotAxis.z * sinang);
	m[5] = (rotAxis.y * rotAxis.y * cosm) + cosang;
	m[6] = (rotAxis.y * rotAxis.z * cosm) + (rotAxis.x * sinang);
	m[7] = 0.0;
	m[8] = (rotAxis.x * rotAxis.z * cosm) + (rotAxis.y * sinang);
	m[9] = (rotAxis.y * rotAxis.z * cosm) - (rotAxis.x * sinang);
	return m;
}
Matrix2 MMath::rotate2x2(float angle, float x, float y)
{
	float cosang, sinang, cosm;
	Matrix2 m;
	Vec2 rotAxis(x, y);
	angle *= float(DEGREES_TO_RADIANS);
	cosang = cos(angle);
	sinang = sin(angle);
	cosm = (1.0f - cosang);

	m[0] = rotAxis.x * rotAxis.x *cosm + cosang;
	m[1] = rotAxis.x * rotAxis.y *cosm + cosang;
	m[2] = rotAxis.y * rotAxis.x * cosm - sinang;
	m[3] = rotAxis.y * rotAxis.y * cosm + sinang;
	return m;
}

Matrix4 MMath::translate4x4(float x, float y, float z) {
	return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x, y, z, 1.0f);
}
Matrix3 MMath::translate3x3(float x, float y, float z) {
	return Matrix3(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		x, y, z);
}
Matrix2 MMath::translate2x2(float x, float y) {
	return Matrix2(1.0f, x, y, 1.0f);
}
Matrix4 MMath::scale4x4(float x, float y, float z) {
	return Matrix4(x, 0.0f, 0.0f, 0.0f,
		0.0f, y, 0.0f, 0.0f,
		0.0f, 0.0f, z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}
Matrix3 MMath::scale3x3(float x, float y, float z) {
	return Matrix3(x, 0.0f, 0.0f,
		0.0f, y, 0.0f,
		0.0f, 0.0f, z);
}
Matrix2 MMath::scale2x2(float x, float y) {
	return Matrix2(x, 0.0f,
		0.0f, y);
}
/// Take the transpose of a matrix 2x2, swap row with columns
Matrix2 MMath::Transpose2x2(const Matrix2 m) {
	return(m[0 * 2], m[0 * 2 + 1],
		m[1 * 2], m[1 * 2 + 1]);
}
/// Take the transpose of a matrix 3x3, swap row with columns
Matrix3 MMath::Transpose3x3(const Matrix3 m) {
	return Matrix3(m[0 * 3], m[0 * 3 + 1], m[0 * 3 + 2],
		m[1 * 3], m[1 * 3 + 1], m[1 * 3 + 2],
		m[2 * 3], m[2 * 3 + 1], m[2 * 3 + 2]);
}
/// Take the transpose of a matrix 4x4, swap row with columns
Matrix4 MMath::Transpose4x4(const Matrix4 m) {
	return Matrix4(m[0 * 4], m[0 * 4 + 1], m[0 * 4 + 2], m[0 * 4 + 3],
		m[1 * 4], m[1 * 4 + 1], m[1 * 4 + 2], m[1 * 4 + 3],
		m[2 * 4], m[2 * 4 + 1], m[2 * 4 + 2], m[2 * 4 + 3],
		m[3 * 4], m[3 * 4 + 1], m[3 * 4 + 2], m[3 * 4 + 3]);
}
Matrix2 MMath::inverse2x2(const Matrix2 m) {
	float det;
	Matrix2 temp, n;
	temp[0] = m[0] * m[3];
	temp[1] = m[1] * m[2];
	det = 1.0f / (temp[0] - temp[1]);
	temp[0] = m[3] / det;
	temp[1] = m[2] / det;
	temp[2] = m[1] / det;
	temp[3] = m[0] / det;
	n = temp;
	return n;
}
Matrix3 MMath::inverse3x3(const Matrix3 m) {
	float determinant, invDeterminant;
	Matrix3 n, tmp;

	tmp[0] = m[4] * m[8] - m[5] * m[7];
	tmp[1] = m[2] * m[7] - m[1] * m[8];
	tmp[2] = m[1] * m[5] - m[2] * m[4];
	tmp[3] = m[5] * m[6] - m[3] * m[8];
	tmp[4] = m[0] * m[8] - m[2] * m[6];
	tmp[5] = m[2] * m[3] - m[0] * m[5];
	tmp[6] = m[3] * m[7] - m[4] * m[6];
	tmp[7] = m[1] * m[6] - m[0] * m[7];
	tmp[8] = m[0] * m[4] - m[1] * m[3];

	// check determinant if it is 0
	determinant = m[0] * tmp[0] + m[1] * tmp[3] + m[2] * tmp[6];

	// divide by the determinant
	invDeterminant = 1.0f / determinant;
	n[0] = invDeterminant * tmp[0];
	n[1] = invDeterminant * tmp[1];
	n[2] = invDeterminant * tmp[2];
	n[3] = invDeterminant * tmp[3];
	n[4] = invDeterminant * tmp[4];
	n[5] = invDeterminant * tmp[5];
	n[6] = invDeterminant * tmp[6];
	n[7] = invDeterminant * tmp[7];
	n[8] = invDeterminant * tmp[8];
	return n;
}
Matrix4 MMath::inverse4x4(const Matrix4 m) {
	Matrix4 inverseM;
	float det;

	inverseM[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
	inverseM[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
	inverseM[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
	inverseM[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
	inverseM[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
	inverseM[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
	inverseM[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
	inverseM[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
	inverseM[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
	inverseM[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
	inverseM[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
	inverseM[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
	inverseM[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
	inverseM[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
	inverseM[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
	inverseM[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

	det = m[0] * inverseM[0] + m[1] * inverseM[4] + m[2] * inverseM[8] + m[3] * inverseM[12];
	det = 1.0f / det;
	for (int i = 0; i < 16; i++) {
		inverseM[i] *= det;
	}
	return inverseM;
}
///Tested Feb 1 2013 SSF
Matrix4 MMath::lookAt(float eyeX, float eyeY, float eyeZ,
	float atX, float atY, float atZ,
	float upX, float upY, float upZ) {
	Vec3 at(atX, atY, atZ);
	Vec3 up(upX, upY, upZ);
	Vec3 eye(eyeX, eyeY, eyeZ);

	Matrix4 result;

	Vec3 forward = VMath::Normalize(at - eye);
	up = VMath::Normalize(up);
	Vec3 side = VMath::Normalize(VMath::cross(forward, up));
	up = VMath::cross(side, forward);

	result[0] = side.x;
	result[1] = side.y;
	result[2] = side.z;
	result[3] = 0.0;

	result[4] = up.x;
	result[5] = up.y;
	result[6] = up.z;
	result[7] = 0.0;

	result[8] = -forward.x;
	result[9] = -forward.y;
	result[10] = -forward.z;
	result[11] = 0.0;

	result[12] = -VMath::dot(side, eye);
	result[13] = -VMath::dot(up, eye);
	result[14] = VMath::dot(forward, eye);
	result[15] = 1.0;

	return result;
}

/// This creates a transform from Normalized Device Coordinates (NDC) to
/// screen coordinates. OpenGL uses NDC as			 ------------- (1.0, 1.0)
///													|   /		  |
///													|  /          |  /
///													| /           | /
///													|/            |/
///										(-1.0, -1.0) -------------
Matrix4 MMath::viewportNDC(int width, int height) {
	/*float minZ = 0.0f;
	float maxZ = 1.0f;
	Matrix4 m1 = scale(1.0f, -1.0f, 1.0f);
	Matrix4 m2 = scale(float(width)/2.0f, float(height)/2.0f, maxZ - minZ);
	Matrix4 m3 = translate(-1.0f + float(width)/2.0f, -1.0f + float(height)/2.0f, minZ);*/
	Matrix4 m;
	m[0] = float(width) / 2.0f;
	m[5] = -float(height) / 2.0f;
	m[10] = 0.0f;
	m[12] = float(width) / 2.0f;
	m[13] = float(height) / 2.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
	return m;
}
///Tested Feb 1 2013 SSF
Matrix4 MMath::perspective(float fFov, float fAspect, float zMin, float zMax) {
	Matrix4 m;
	m.loadIdentity();
	float yMax = zMin * tanf(fFov * 0.5f * float(DEGREES_TO_RADIANS));
	float yMin = -yMax;
	float xMin = yMin * fAspect;
	float xMax = -xMin;

	m[0] = (2.0f * zMin) / (xMax - xMin);
	m[5] = (2.0f * zMin) / (yMax - yMin);
	m[8] = (xMax + xMin) / (xMax - xMin);
	m[9] = (yMax + yMin) / (yMax - yMin);
	m[10] = -((zMax + zMin) / (zMax - zMin));
	m[11] = -1.0f;
	m[14] = -((2.0f * (zMax*zMin)) / (zMax - zMin));
	m[15] = 0.0f;
	return m;
}
/// Not tested but I'll bet I'm right
Matrix4 MMath::orthographic(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax) {
	Matrix4 m;
	m[0] = 2.0f / (xMax - xMin);
	m[5] = 2.0f / (yMax - yMin);
	m[10] = -2.0f / (zMax - zMin);
	m[12] = -((xMax + xMin) / (xMax - xMin));
	m[13] = -((yMax + yMin) / (yMax - yMin));
	m[14] = -((zMax + zMin) / (zMax - zMin));
	m[15] = 1.0f;
	return m;
}