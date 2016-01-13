#include "AnimatedSprite.h"

using namespace Game_Lib;

AnimatedSprite::AnimatedSprite() :createdTexture(nullptr), Width(0), Height(0), frameCount(0), previousFrame(0) {}

AnimatedSprite::~AnimatedSprite()
{
	Destroy();
}

void Game_Lib::AnimatedSprite::Destroy()
{
	SDL_DestroyTexture(createdTexture);

	createdTexture = nullptr;
	renderer = nullptr;
	delete createdTexture;
	delete renderer;
}

bool Game_Lib::AnimatedSprite::LoadAsset(SDL_Renderer * _renderer, const std::string & fileName)
{
	Destroy();
	renderer = _renderer;
	SDL_Surface* loadedAsset = IMG_Load(fileName.c_str());
	if (!loadedAsset) {
		//	Debug::Log(EMessageType::ERROR, "Failed to load" + fileName + "! SDL Image Error:" + IMG_GetError(), __FILE__, __LINE__);
		return false;
	}
	else {
		createdTexture = SDL_CreateTextureFromSurface(renderer, loadedAsset);
		Width = loadedAsset->w;
		Height = loadedAsset->h;
		if (!createdTexture) {
			//	Debug::Log(EMessageType::ERROR, "Failed to creat texture from " + fileName + ". SDL Error: " + SDL_GetError(), __FILE__, __LINE__);
		}
		else {
			SDL_FreeSurface(loadedAsset);
			loadedAsset = nullptr;
			return true;
		}
	}
}

void Game_Lib::AnimatedSprite::Draw(int x, int y, float scale, SDL_Rect * Clip, double Angle, bool Center, SDL_RendererFlip Flip)
{
	DrawParams Params = DrawParams{ x, y, scale, Clip, Angle, SetOrigin(Center, Clip), Flip };
	Draw(Params);
}

void AnimatedSprite::Draw(const DrawParams & Params) const
{
	SDL_Rect DrawRect = {
		(int)(Params.x + (-Width * (Params.scale - 1.0f) * 0.5f)),
		(int)(Params.y + (-Height * (Params.scale - 1.0f) * 0.5f)),
		(int)(Width * Params.scale),
		(int)(Height * Params.scale) };
	if (Params.Clip) {
		DrawRect.w = Params.Clip->w;
		DrawRect.h = Params.Clip->h;
	}
	SDL_RenderCopyEx(renderer, createdTexture, NULL, &DrawRect, Params.Angle, Params.origin, Params.Flip);
}

void AnimatedSprite::Animate(const DrawParams & Params, int frameCount, Matrix4 projection)
{
	SDL_Rect ClipRect = {
		(Params.x + ((-Width / frameCount) * (Params.scale - 1.0f) * 0.5f)),
		(Params.y + (-Height * (Params.scale - 1.0f) * 0.5f)),
		((Width / frameCount)  * Params.scale) ,
		(Height * Params.scale)
	};

	if (previousFrame + 1 > frameCount)
		previousFrame = 0;

	SDL_Rect DrawRect = { (previousFrame *((Width / frameCount))) ,
		0.0f,
		(Width / frameCount),
		Height };
	previousFrame = previousFrame + 1;
	Vec4 projectedPosition;
	position.x += 20;
	position.y = -300;
	projectedPosition = projection * position;
	ClipRect.x = projectedPosition.x;
	ClipRect.y = projectedPosition.y;
	SDL_RenderCopyEx(renderer, createdTexture, &DrawRect, &ClipRect, Params.Angle, Params.origin, Params.Flip);
}

SDL_Point * AnimatedSprite::SetOrigin(bool center, SDL_Rect * Clip)
{
	return nullptr;
}

void AnimatedSprite::SetBlendMode(const SDL_BlendMode blend)
{
	SDL_SetTextureBlendMode(createdTexture, blend);
}

void AnimatedSprite::SetAlpha(const Uint8 A)
{
	SDL_SetTextureAlphaMod(createdTexture, A);
}

void AnimatedSprite::SetColor(const SDL_Color & SDLColor)
{
	SetColor(SDLColor.r, SDLColor.g, SDLColor.b, SDLColor.a);
}

void AnimatedSprite::SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	SDL_SetTextureColorMod(createdTexture, r, g, b);
	SDL_SetTextureAlphaMod(createdTexture, a);
}

int AnimatedSprite::GetHeight() const
{
	return Height;
}

int AnimatedSprite::GetWidth() const
{
	return Width;
}

void AnimatedSprite::Animate(int x, int y, float scale, SDL_Rect * Clip, double Angle, bool Center, SDL_RendererFlip Flip, int frameCount, Matrix4 projection)
{
	DrawParams Params = DrawParams{ x, y, scale, Clip, Angle, SetOrigin(Center, Clip), Flip };
	AccuFrame++;
	if (AccuFrame % 10 == 1) {
		Animate(Params, frameCount, projection);
	}
	else if (AccuFrame % 10 == 0) {
	}
}