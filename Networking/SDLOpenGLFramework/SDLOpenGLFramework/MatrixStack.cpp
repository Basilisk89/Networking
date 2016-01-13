#include "MatrixStack.h"
#include <string>

using namespace Game_Lib;

MatrixStack::MatrixStack(int _stackDepth) {
	stackDepth = _stackDepth;
	stack = new Matrix4[stackDepth];
	stackPointer = 0;
	stack[0].loadIdentity();
}

MatrixStack::~MatrixStack(void) {
	if (stack)delete [] stack;
}

void MatrixStack::pushMatrix() { 
	if(stackPointer < stackDepth) {
		stackPointer++;
		stack[stackPointer] = stack[stackPointer-1];
	}else{
		std::string errorMsg("Stack Overflow");
		throw errorMsg;
	}
}

		
void MatrixStack::popMatrix() {
	if(stackPointer > 0){
		stackPointer--;
	}else{
		std::string errorMsg("Stack Underflow");
		throw errorMsg;
	}
}


void MatrixStack::loadIdentity() { 
	stack[stackPointer].loadIdentity();
}
		
void MatrixStack::loadMatrix(const Matrix4 m) { 
	stack[stackPointer] = m;
}   
            
void MatrixStack::multMatrix(const Matrix4 m) {
	stack[stackPointer] = m * stack[stackPointer];
}
                 				
	

			
		
void MatrixStack::scale(float x, float y, float z) {
	stack[stackPointer] *= MMath::scale4x4(x,y,z);
}
			
			
void MatrixStack::translate(float x, float y, float z) {
	stack[stackPointer] *= MMath::translate4x4(x,y,z);
}
			
		
void MatrixStack::rotate(float angle, float x, float y, float z) {
	stack[stackPointer] *= MMath::rotate4x4(angle,x,y,z);
}

void MatrixStack::perspective( const float fovy, const float aspect,const float zNear, const float zFar) {
	stack[stackPointer] *= MMath::perspective(fovy,aspect,zNear,zFar);
}

void MatrixStack::lookAt( const Vec3& eye, const Vec3& at, const Vec3& up ) {
	stack[stackPointer] *= MMath::lookAt(eye.x,eye.y,eye.z, at.x,at.y,at.z ,up.x,up.y,up.z);
}

	
const float* MatrixStack::getMatrixfv() { return stack[stackPointer]; }


void MatrixStack::print(){
		stack[stackPointer].print();
}