#pragma once
/// In interface (abstract class in C++) for all the OpenGL-like calls we have to make from now on
/// The idea is that both the MatrixStack and the StackMngr classes need the same named sunroutines 
/// I used this "interface" in insure all the names are spelled the same and that all the Subroutines are present, 
/// kink of Java like.

#include "Matrix.h" /// Needed for the defs of Matrix and Vec3

namespace  Game_Lib {

class IGameGL {
		///pure virual (abstact) Subroutines 
		virtual void loadIdentity() = 0;
		virtual void loadMatrix(const Matrix m) = 0;   
		virtual void multMatrix(const Matrix m) = 0;
		virtual void pushMatrix() = 0;
		virtual void popMatrix() = 0;
		virtual void scale(float x, float y, float z) = 0;	
		virtual void translate(float x, float y, float z) = 0;
		virtual void rotate(float radians, float x, float y, float z) =0;
		virtual void perspective( const float fovy, const float aspect,const float zNear, const float zFar) = 0;
		virtual void lookAt( const Vec3& eye, const Vec3& at, const Vec3& up ) = 0;

		/// Not really needed for our purposes right now so I'll just leave it as an idea
		//// An inline operator overload to mult a vector by the top of the matrix stack
		/// virtual inline Vec4 operator * ( const Vec4& v ) const = 0;
		
		virtual const float* getMatrixfv() = 0;
		virtual void print() = 0;

};

} /// end of namespace