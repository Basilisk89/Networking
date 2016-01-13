#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include"Debug.h"
#include<SDL.h>
#include<SDL_image.h>
#include<string>
namespace Game_Lib {
	class ImageLoader {
	public:
		// kill the constructor do not need it
		ImageLoader::ImageLoader() = delete;
		// kill the default copy constructor of the reference of a const obj
		ImageLoader(const ImageLoader&) = delete;
		// kill the default copy constructor of the reference of the reference
		ImageLoader(ImageLoader&&) = delete;
		// kill the = assignment operator
		Game_Lib::ImageLoader& operator=(const Game_Lib::ImageLoader) = delete;
		// kill the = assignment operator
		ImageLoader& operator=(const ImageLoader&&) = delete;
		//Loads any other image file to be read for conversion
		static SDL_Surface* const ImgLoader(const std::string filename, SDL_Window* window);
		// Loads a Bitmap SDL can read
		static SDL_Surface* const BitMapLoader(const std::string filename);
		// loads any image or bitmap from a surface into an SDL TEXTURE
		static SDL_Texture* const TextureLoader(SDL_Surface* _image, SDL_Renderer* windowRenderer);
	protected:
	private:
	};
}
#endif 