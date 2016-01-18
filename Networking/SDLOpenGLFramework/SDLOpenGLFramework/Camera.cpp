#include "Camera.h"
using namespace Game_Lib;
Camera* Camera::instance = NULL;

void Camera::getStack() {
	
}
Camera* Camera::getInstance() {
	if (instance == nullptr) {
		instance = new Camera();

	}
	else {
	
		return instance;
	}
}
Camera::Camera():aspectRatio(0.0f),mngr(StackMngr::getInstance()){
}
Camera::~Camera() {
}

Matrix Camera::NormalizedDeviceCoord(int w, int h) {
	Matrix ndc = MMath::viewportNDC(w, h);
	return ndc;
}
Matrix Game_Lib::Camera::ScreenToWorld(Matrix ndc, float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
	Matrix othro = MMath::orthographic(minX, maxX, minY, maxY, minZ, maxZ);
	Matrix projection = othro * ndc;
	return projection;
}

void Game_Lib::Camera::viewPort(int w, int h) {
	glViewport(0, 0, w, h);
	aspectRatio = (float)w / (float)h;
}

void Game_Lib::Camera::push(){
	mngr->pushMatrix();
}

void Game_Lib::Camera::pop()
{
	mngr->popMatrix();
}

void Game_Lib::Camera::scale(float x, float y, float z)
{
	mngr->scale(x, y, z);
}

void Game_Lib::Camera::translate(float x, float y, float z)
{
	mngr->translate(x, y, z);
}

void Game_Lib::Camera::rotate(float radians, float x, float y, float z)
{
	mngr->rotate(radians, x, y, z);
}

void Game_Lib::Camera::loadPerspective(const float fovy, const float aspect, const float zNear, const float zFar)
{
	mngr->matrixMode(PROJECTION);
	mngr->loadIdentity();
	mngr->perspective(fovy, aspect, zNear, zFar);
}

void Game_Lib::Camera::loadLookAt(const Vec3 & eye, const Vec3 & at, const Vec3 & up)
{
	mngr->matrixMode(MODELVIEW);
	mngr->loadIdentity();
	mngr->lookAt(eye, at, up);
}

const float * Game_Lib::Camera::getMatrixfv(StdMatricies whichMatrix)
{
	return mngr->getMatrixfv(whichMatrix);
}

const float * Game_Lib::Camera::getMatrixfv()
{
	return mngr->getMatrixfv();
}

void Game_Lib::Camera::loadMatrix(const Matrix m)
{
	mngr->loadMatrix(m);
}

void Game_Lib::Camera::multMatrix(const Matrix m)
{
	mngr->multMatrix(m);
}

void Game_Lib::Camera::matrixMode(StdMatricies whichMatrix)
{
	mngr->matrixMode(whichMatrix);
}

void Game_Lib::Camera::loadIndentity()
{
	mngr->loadIdentity();
}
