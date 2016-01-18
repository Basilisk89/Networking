#pragma once
#include <glew.h>
#include <gl/gl.h>

#include "Shader.h"
#include "Matrix.h"
#include "MatrixStack.h"
#include "IGameGL.h"

/// This class is used to manage the various matrix stacks in OpenGL programming version 140 and on 

namespace Game_Lib {

	/// An enum for the three needed matricies.  Both projection and ModelView are treated as matrix stacks,
	/// the normal matrix is derived before being returned
	enum StdMatricies {
		PROJECTION, MODELVIEW, NORMAL
	};

	class StackMngr: public IGameGL {
	private:
		static StackMngr* instance; 
		MatrixStack* projection;
		MatrixStack* modelView; 
		MatrixStack* currentMatrixStack; /// Point to the top of whichever stack is currently active
		float normal[9];				/// The normal matrix doesn't need a stack
		StackMngr();
		~StackMngr();

	public:
		static StackMngr* getInstance();
		static void deleteInstance();
		void matrixMode(StdMatricies whichMatrix);

		void loadIdentity() ;
		void loadMatrix(const Matrix m) ;   
		void multMatrix(const Matrix m);
		void pushMatrix();
		void popMatrix();
		void scale(float x, float y, float z);	
		void translate(float x, float y, float z) ;
		void rotate(float radians, float x, float y, float z) ;
		void perspective( const float fovy, const float aspect,const float zNear, const float zFar) ;
		void lookAt( const Vec3& eye, const Vec3& at, const Vec3& up ) ;
		/// An inline operator overload to mult a vector by the top of the matrix stack
		/// inline Vec4 operator * ( const Vec4& v ) const { return ((Matrix*)currentMatrixStack) * v;}
		const float* getMatrixfv(StdMatricies whichMatrix);
		/// With no args just return the currently active matrix
		const float* getMatrixfv();
		void print();
	};

}