#include "Texture.h"
using namespace Game_Lib;
Texture::Texture() {
}
Texture::~Texture() {
	// remove the Texture data members
	Remove();
}
void Texture::Remove() {
	// set image and texture to null

	image = nullptr;
	texture = nullptr;
	delete image;
	delete texture;
	Debug::Log(EMessageType::INFO, "Texture", "Remove", __FILE__, __LINE__, "Deleting");
}