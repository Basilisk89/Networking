/// A simple subdivided cube - SSF
/// The idea is to start with a cube then subdivide it's edges to make a cude of high resolution but still looks the same.
/// If I push the square verts a radius away from the center of the cube, the thing will look like a ball, easy. 
#include "VMath.h"
#include <glew.h>
#include <glut.h>

using namespace GAME_Lib;

class QuadSphere {
private:
	int numVertices;
	int index;
	Vec4 *vertex;
	Vec4 *normals;
	Vec2 *texCoords;
public:
	QuadSphere(int numSubDivisions);
	~QuadSphere();
	void loadFace(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d);
	void divideFace(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d, int count);
	void sphericalNormals();
	void render();
};



