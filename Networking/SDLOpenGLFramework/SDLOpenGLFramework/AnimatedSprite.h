#ifndef AnimatedSprite_h
#define AnimatedSprite_h
#include <string>
#include "SDL.h"
#include <SDL_image.h>
#include "Matrix.h"
namespace Game_Lib {
	class AnimatedSprite
	{
		struct DrawParams {
			int x;
			int y;
			float scale;
			SDL_Rect* Clip;
			double Angle;
			SDL_Point* origin;
			SDL_RendererFlip Flip;
			SDL_Renderer* renderer;
			SDL_Surface* surface;
		};
	public:
		AnimatedSprite();
		AnimatedSprite(const AnimatedSprite&) = delete;
		AnimatedSprite(AnimatedSprite&&) = delete;
		AnimatedSprite& operator = (const AnimatedSprite&) = delete;
		AnimatedSprite& operator=(AnimatedSprite&&) = delete;
		~AnimatedSprite();
		void Destroy();
		bool LoadAsset(SDL_Renderer* _renderer, const std::string& fileName);
		void Draw(
			int x,
			int y,
			float scale,
			SDL_Rect* Clip,
			double Angle,
			bool Center,
			SDL_RendererFlip Flip);
		void SetBlendMode(const SDL_BlendMode blend);
		void SetAlpha(const Uint8 A);
		void SetColor(const SDL_Color& SDLColor);
		void SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
		int GetHeight() const;
		int GetWidth() const;
		void Animate(int x, int y, float scale, SDL_Rect* Clip, double Angle, bool Center, SDL_RendererFlip Flip, int frameCount, Matrix4 projection);
		Vec4 position;
	private:
		void Draw(const DrawParams& Params) const;
		void Animate(const DrawParams& Params, int frameCount, Matrix4 projection);
		SDL_Rect DrawRect;
		SDL_Point* SetOrigin(bool center, SDL_Rect* Clip);
		SDL_Texture* createdTexture;
		SDL_Renderer* renderer;
		int Width, Height;
		int frameCount;
		int previousFrame;
		int AccuFrame;
	};
}
#endif