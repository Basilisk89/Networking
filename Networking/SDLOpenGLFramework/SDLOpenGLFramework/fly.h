#ifndef Fly_h
#define Fly_h
#include "GameObject.h"
#include "Sprite.h"
#include "VMath.h"
namespace Game_Lib {
	class fly :public GameObject {
	public:
		explicit fly(Rectangle r, Window* window, float _angle);
		virtual ~fly();
		fly(const GameObject&) = delete;
		fly(GameObject&&) = delete;
		fly operator=(const GameObject&) = delete;
		fly operator=(GameObject&&) = delete;
		virtual bool OnCreate(std::string filename);
		virtual void OnDestroy();
		virtual void Render(Matrix4 projection);
		virtual void Update(float deltaTime);
		virtual void LeftFlip() const;
		virtual void RightFlip() const;
		virtual bool IsFlipped();
		virtual void Clamp();
		Sprite* flySprite;
	private:
		Window* windowPtr;
		float accuTime;
		bool isAlive;

	protected:
	};
}
#endif
