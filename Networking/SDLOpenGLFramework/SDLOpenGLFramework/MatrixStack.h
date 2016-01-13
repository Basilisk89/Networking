#pragma once 
#include "MMath.h"
#include "IGameGL.h"

namespace  Game_Lib {

/// Typical stack pattern. I use IGameGL like an interface so MatrixStack and StackMngr will have all same Subroutines 
class MatrixStack: public IGameGL {
		
	protected:
		int	stackDepth;  /// Default is 32
		int	stackPointer;
			Matrix4 *stack;
	public:
		MatrixStack(int _stackDepth = 32);
		~MatrixStack() ;
		void loadIdentity() ;
		void loadMatrix(const Matrix4 m) ;   
		void multMatrix(const Matrix4 m);
		void pushMatrix();
		void popMatrix() ;
		void scale(float x, float y, float z);	
		void translate(float x, float y, float z) ;
		void rotate(float angle, float x, float y, float z) ;
		void perspective( const float fovy, const float aspect,const float zNear, const float zFar) ;
		void lookAt( const Vec3& eye, const Vec3& at, const Vec3& up );

		//// An inline operator overload to mult a vector by the top of the matrix stack
		inline Vec4 operator * ( const Vec4& v ) const { return stack[stackPointer] * v;}
		
		const float* getMatrixfv() ;
		void print();
	

	};

	
}