#include <stdlib.h>
#include "StackMngr.h"

using namespace Game_Lib;

StackMngr* StackMngr::instance=NULL;

StackMngr* StackMngr::getInstance(){
	if(instance == NULL){
			instance = new StackMngr();
	}
	return instance;
}

void StackMngr::deleteInstance(){
	if(instance) delete instance;
}

StackMngr::StackMngr(){	
	projection = new MatrixStack();
	modelView = new MatrixStack();
	currentMatrixStack = projection;/// Default starting condition of the Manager is projection
}

StackMngr::~StackMngr(){
	if(projection) delete projection;
	if(modelView) delete modelView;

	currentMatrixStack = NULL;
}

void StackMngr::matrixMode( StdMatricies whichMatrix){
	if(whichMatrix == PROJECTION){ 
		currentMatrixStack = projection;
	}else if(whichMatrix == MODELVIEW){
		currentMatrixStack = modelView;
	}else return;
}

void StackMngr::loadIdentity() {
	currentMatrixStack->loadIdentity();
}
	
void StackMngr::loadMatrix(const Matrix m) {
	currentMatrixStack->loadMatrix(m);
}

void StackMngr::multMatrix(const Matrix m){
	currentMatrixStack->multMatrix(m);
}

void StackMngr::pushMatrix(){
	currentMatrixStack->pushMatrix();
}

void StackMngr::popMatrix() {
	currentMatrixStack->popMatrix();
}

void StackMngr::scale(float x, float y, float z) {
	currentMatrixStack->scale(x,y,z);
}

void StackMngr::translate(float x, float y, float z) {
	currentMatrixStack->translate(x,y,z);
}

void StackMngr::rotate(float radians, float x, float y, float z) {
	currentMatrixStack->rotate(radians,x,y,z);
}

void StackMngr::perspective( const float fovy, const float aspect,const float zNear, const float zFar){
	currentMatrixStack->perspective(fovy,aspect,zNear,zFar);
}

void StackMngr::lookAt( const Vec3& eye, const Vec3& at, const Vec3& up ){
	currentMatrixStack->lookAt(eye,at,up);
}

const float* StackMngr::getMatrixfv(){
	return currentMatrixStack->getMatrixfv();
}

const float* StackMngr::getMatrixfv(StdMatricies whichMatrix){
	switch(whichMatrix){
	case PROJECTION:
		return projection->getMatrixfv();
		break;
	case MODELVIEW:
		return modelView->getMatrixfv();
		break;
	case NORMAL:
		/// Extract the 3x3 rotation matrix from a 4x4 matrix modelView matrix
		/// This is OK as long as there are no asymetic scales happening - I think... Please tell me I'm right or not
		normal[0] = modelView->getMatrixfv()[0]; normal[3] = modelView->getMatrixfv()[4]; normal[6] = modelView->getMatrixfv()[8];
		normal[1] = modelView->getMatrixfv()[1]; normal[4] = modelView->getMatrixfv()[5]; normal[7] = modelView->getMatrixfv()[9];
		normal[2] = modelView->getMatrixfv()[2]; normal[5] = modelView->getMatrixfv()[6]; normal[8] = modelView->getMatrixfv()[10];
		return normal;
	}	
	return NULL;
}

void StackMngr::print(){
	currentMatrixStack->print();
}

