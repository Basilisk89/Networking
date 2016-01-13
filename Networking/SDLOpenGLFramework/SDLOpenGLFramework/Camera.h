#ifndef Camera_H
#define Camera_H
#include "VMath.h"
#include "MMath.h"
#include "Matrix.h"
namespace Game_Lib {
	class Camera {
	public:
		Camera();
		~Camera();
		Matrix4 NormalizedDeviceCoord(int w, int h);
		Matrix4 ScreenToWorld(Matrix4 ndc, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	private:
	};
}
#endif