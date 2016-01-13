#ifndef BOY_H
#define BOY_H
#include "GameObject.h"
#include "Timer.h"
#include "Sprite.h"
namespace Game_Lib {
	class Boy : public GameObject {
	public:
		explicit Boy(const Rectangle r, Window* window, float _angle);
		virtual ~Boy();
		virtual bool OnCreate(std::string filename);
		virtual void OnDestroy();
		virtual void Render(Matrix4 projection);
		virtual void Update(float deltaTime);
		virtual void LeftFlip() const;
		virtual void RightFlip() const;
		virtual bool IsFlipped();
		virtual void Clamp();
		Sprite* boySprite;
	private:
		Window* windowPtr;

		bool isAlive;

	protected:
	};
}
#endif
