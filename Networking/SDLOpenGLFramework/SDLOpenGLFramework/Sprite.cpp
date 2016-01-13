#include "Sprite.h"
using namespace Game_Lib;
Game_Lib::Sprite::Sprite(Rectangle & r, Window* windowptr, float _angle) :Texture(), retangle(new SDL_Rect()), windowInstance(windowptr), flip(), angle(_angle) {
	position = Vec4(r.x, r.y, 0, 0);
	retangle->x = position.x;
	retangle->y = position.y;
	retangle->h = r.h;
	retangle->w = r.w;
	Debug::Log(EMessageType::INFO, "Sprite", "Sprite", __FILE__, __LINE__, "Sprite Created");
}
Sprite::~Sprite() {
	OnDestroy();
}
void Sprite::Load(const std::string& filename) {
	// Load the Texture from the image in the sprite
	image = ImageLoader::ImgLoader(filename.c_str(), windowInstance->getWindow());
	SDL_SetSurfaceBlendMode(image, SDL_BLENDMODE_ADD);
	texture = ImageLoader::TextureLoader(image, windowInstance->GetRenderer());
	Debug::Log(EMessageType::INFO, "Sprite", "Load", __FILE__, __LINE__, "Sprite Loaded");
}

void Sprite::Render(Matrix4 projection) {
	try {
		if (projection != NULL) {
			 projectedVector = projection * position;
			if (projectedVector != NULL) {
				retangle->x = projectedVector.x;
				retangle->y = projectedVector.y;
				SDL_RenderCopyEx(windowInstance->GetRenderer(), texture, NULL, retangle, angle, NULL, flip);
			}
			else {}
		}
		else { throw std::runtime_error("Vector shit on me"); }
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}
void Sprite::SetAlpha(const Uint8 A) {
	SDL_SetTextureAlphaMod(texture, A);
}
void Sprite::LeftFlip() {
	flip = SDL_FLIP_HORIZONTAL;
	isFlipped = true;
}
void Sprite::RightFlip() {
	flip = SDL_FLIP_NONE;
	isFlipped = false;
}

void Game_Lib::Sprite::OnDestroy() {
	Remove();
	delete retangle;

	retangle = nullptr;

	Debug::Log(EMessageType::INFO, "Sprite", "~Sprite", __FILE__, __LINE__, "Sprite Killed");
}