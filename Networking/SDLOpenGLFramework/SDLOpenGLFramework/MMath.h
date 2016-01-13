#pragma once
#include "Matrix.h"
///  A class devoted to graphics related Math - OpenGL style
namespace  Game_Lib {
	class MMath {
	public:
		static Matrix4 rotate4x4(float angle, float x, float y, float z);
		static Matrix3 rotate3x3(float angle, float x, float y, float z);
		static Matrix2 rotate2x2(float angle, float x, float y);

		static Matrix4 translate4x4(float x, float y, float z);
		static Matrix3 translate3x3(float x, float y, float z);
		static Matrix2 translate2x2(float x, float y);

		static Matrix4 scale4x4(float x, float y, float z);
		static Matrix3 scale3x3(float x, float y, float z);
		static Matrix2 scale2x2(float x, float y);

		static Matrix4 inverse4x4(Matrix4 m);
		static Matrix3 inverse3x3(Matrix3 m);
		static Matrix2 inverse2x2(Matrix2 m);

		static Matrix3 Transpose3x3(Matrix3 m);
		static Matrix4 Transpose4x4(Matrix4 m);
		static Matrix2 Transpose2x2(Matrix2 m);
		static Matrix4 viewportNDC(int width, int height);
		static Matrix4 perspective(float fFov, float fAspect, float zMin, float zMax);

		static Matrix4 orthographic(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax);

		static Matrix4 lookAt(float eyeX, float eyeY, float eyeZ, float atX, float atY, float atZ, float upX, float upY, float upZ);
	};
}
