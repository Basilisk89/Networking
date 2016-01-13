#include "ImageLoader.h"
#include <assert.h>
using namespace Game_Lib;
//returns the .bmp image as an SDL_SURFACE
SDL_Surface* const ImageLoader::BitMapLoader(const std::string filename) {
	//start the image SDL_SURFACE and load the image
	SDL_Surface* image = SDL_LoadBMP(filename.c_str());;
	// if splash is null

	if (image == nullptr) {
		//then return a nullptr
		return nullptr;
		// log it as an error
		Debug::Log(EMessageType::ERROR, "ImageLoader", "BitMapLoader", __FILE__, __LINE__, std::string(SDL_GetError()));
	}

	// return the image surface
	return image;

	// log it is loaded
	Debug::Log(EMessageType::INFO, "ImageLoader", "BitMapLoader", __FILE__, __LINE__, "Loading " + filename);
}
// converts and returns any image into a .bmp image SDL2 can use
SDL_Surface* const ImageLoader::ImgLoader(const std::string filename, SDL_Window* _window) {
	try {
		// start 3 SDL Surfaces 1 for loading image
		SDL_Surface *image;
		//2nd to get the window and place it on the surface
		SDL_Surface *window = SDL_GetWindowSurface(_window);
		//3rd to place the final image
		SDL_Surface *finalImage;
		image = IMG_Load(filename.c_str());
		if (image == nullptr) {
			//then return a nullptr
			Debug::Log(EMessageType::ERROR, "ImageLoader", "ImgLoader", __FILE__, __LINE__, std::string(IMG_GetError()));
			std::string error("failed to load image");
			throw error;
			// log it didnt load
		}
		if (image) {
			finalImage = SDL_ConvertSurface(image, window->format, NULL);
			Debug::Log(EMessageType::INFO, "ImageLoader", "ImgLoader", __FILE__, __LINE__, "Loading " + filename);

			if (!finalImage) {
				Debug::Log(EMessageType::ERROR, "ImageLoader", "ImgLoader", __FILE__, __LINE__, std::string(SDL_GetError()));
				std::string error("failed to load Texture");
				throw error;
			}
			return  finalImage;
		}
	}
	// catch any std::strings i throw
	catch (std::string  e) {
		std::cout << e.c_str() << std::endl;
	}
	return nullptr;
}
SDL_Texture * const ImageLoader::TextureLoader(SDL_Surface* _image, SDL_Renderer * windowRenderer)
{
	SDL_Texture *finalImage = SDL_CreateTextureFromSurface(windowRenderer, _image);
	// if image = null
	if (!_image) {
		//then return a nullptr
		return finalImage = nullptr;
		// log it didnt load
		Debug::Log(EMessageType::ERROR, "ImageLoader", "TextureLoader", __FILE__, __LINE__, std::string(IMG_GetError()));
	}
	// if window = null
	if (!windowRenderer) {
		//then return a nullptr
		return finalImage = nullptr;
		//log it
		Debug::Log(EMessageType::ERROR, "ImageLoader", "TextureLoader", __FILE__, __LINE__, std::string(SDL_GetError()));
	}
	// if final image = null
	if (!finalImage) {
		//then return a nullptr
		return finalImage = nullptr;
		//log it
		Debug::Log(EMessageType::ERROR, "ImageLoader", "TextureLoader", __FILE__, __LINE__, std::string(SDL_GetError()));
	}
	// if image != null and window != null and finalimage != null
	if (_image && windowRenderer && finalImage) {
		// log it
		Debug::Log(EMessageType::INFO, "ImageLoader", "BitMapLoader", __FILE__, __LINE__, "Texture Loaded");
	}
	//return the finalimage
	return finalImage;
}