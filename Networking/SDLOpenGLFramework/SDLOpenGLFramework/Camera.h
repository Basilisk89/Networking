#ifndef Camera_H
#define Camera_H
#include "VMath.h"
#include "MMath.h"
#include "Matrix.h"
#include "StackMngr.h"
#include "Window.h"
namespace Game_Lib {
	class Camera {
	public:
		static Camera* instance;
		static Camera* getInstance();
		Matrix NormalizedDeviceCoord(int w, int h);
		Matrix ScreenToWorld(Matrix ndc, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
		void viewPort(int w,int h);
		void push();
		void pop();
		void loadMatrix(const Matrix m);
		void multMatrix(const Matrix m);
		void matrixMode(StdMatricies whichMatrix);
		void loadIndentity();
		void scale(float x, float y, float z);
		void translate(float x, float y, float z);
		void rotate(float radians, float x, float y, float z);
		void loadPerspective(const float fovy, const float aspect, const float zNear, const float zFar);
		void loadLookAt(const Vec3& eye, const Vec3& at, const Vec3& up);
		static void getStack();
		float aspectRatio;
		/// An inline operator overload to mult a vector by the top of the matrix stack
		/// inline Vec4 operator * ( const Vec4& v ) const { return ((Matrix*)currentMatrixStack) * v;}
		const float* getMatrixfv(StdMatricies whichMatrix);
		/// With no args just return the currently active matrix
		const float* getMatrixfv();
		void print();
		
	private:
		Camera();
		~Camera();	
	    StackMngr* mngr;
	
		
		
	};
}
#endif