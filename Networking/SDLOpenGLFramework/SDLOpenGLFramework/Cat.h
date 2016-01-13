#ifndef Cat_H
#define Cat_H
#include "GameObject.h"
#include "Timer.h"
#include "Sprite.h"
namespace Game_Lib {
	class Cat :public GameObject {
	public:
		explicit Cat(const Rectangle r, Window* window, float _angle);
		virtual ~Cat();
		Cat(GameObject&) = delete;
		Cat operator=(const GameObject&) = delete;
		Cat operator=(GameObject&&) = delete;
		virtual bool OnCreate(std::string filename);
		virtual void OnDestroy();
		virtual void Render(Matrix4 projection);
		virtual void Update(float deltaTime);
		virtual void LeftFlip() const;
		virtual void RightFlip() const;
		virtual bool IsFlipped();
		virtual void Clamp();
		Sprite* catSprite;
	private:
		Window* windowPtr;

		bool isAlive;
		float accuTime;
	};
}
#endif