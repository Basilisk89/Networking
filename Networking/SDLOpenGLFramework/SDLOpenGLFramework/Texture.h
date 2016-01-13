#ifndef TEXTURE_H
#define TEXTURE_H
#include "Debug.h"
#include "ImageLoader.h"
#include "Window.h"
namespace Game_Lib {
	// Texture class to hold a Texuture
	class Texture {
	public:
		//Texture constructor
		Texture();
		//Texture Destructor
		~Texture();
		// Remove the Texture and the image
		void Remove();
	private:
		// The image surface to me loaded
		SDL_Surface* image;
		// The Texture for the image
		SDL_Texture* texture;
		// make Sprite and friend class of Texture
		friend class Sprite;
	};
}
#endif
