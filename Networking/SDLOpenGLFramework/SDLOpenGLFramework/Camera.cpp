#include "Camera.h"
using namespace Game_Lib;
Camera::Camera() {
}
Camera::~Camera() {
}
Matrix4 Camera::NormalizedDeviceCoord(int w, int h) {
	Matrix4 ndc = MMath::viewportNDC(w, h);
	return ndc;
}
Matrix4 Game_Lib::Camera::ScreenToWorld(Matrix4 ndc, float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
	Matrix4 othro = MMath::orthographic(minX, maxX, minY, maxY, minZ, maxZ);
	Matrix4 projection = othro * ndc;
	return projection;
}