#ifndef Sprite_h
#define Sprite_h
#include "Texture.h"
#include "Vector.h"
#include "MMath.h"
#include "GameObject.h"
namespace Game_Lib {
	class Sprite :public Texture {
	public:
		Sprite(Vec4 r, Window* windowPtr, float _angle);
		~Sprite();
		void Load(const std::string & filename);
		void Render(Matrix projection);
		void SetAlpha(const Uint8 A);
		void LeftFlip();
		void RightFlip();
		void OnDestroy();
		SDL_Rect* retangle;
		float angle;
		bool isFlipped;
		Vec4 position;
	private:
		Window* windowInstance;
		SDL_RendererFlip flip;
		
		Vec4 projectedVector;
	protected:
	};
}
#endif