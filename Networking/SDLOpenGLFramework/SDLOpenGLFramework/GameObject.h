#ifndef GameObject_H
#define GameObject_H
#include "Vec3.h"
#include "Quaternion.h"
#include "ImageLoader.h"
#include "Window.h"
#include "MMath.h"
namespace Game_Lib {
	class GameObject
	{
	public:
		explicit GameObject(Vec4 v, float _angle);
		virtual ~GameObject();
		GameObject(const GameObject&) = delete;
		GameObject(GameObject&&) = delete;
		virtual bool OnCreate(std::string filename) = 0;
		virtual void OnDestroy() = 0;
		virtual void Render(Matrix4 projection) = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void LeftFlip() const = 0;
		virtual void RightFlip() const = 0;
		virtual bool IsFlipped() = 0;
		virtual void Clamp() = 0;
		Vec4 position, velocity, acceleration, projectedPosition;
		float radius, mass, angle;
	protected:
	private:
	};
}
#endif