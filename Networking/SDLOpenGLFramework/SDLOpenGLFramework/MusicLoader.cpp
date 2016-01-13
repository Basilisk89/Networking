#include "MusicLoader.h"
using namespace Game_Lib;
// loads music into a Mix_music object note.
//some mp3s work , ogg is a better route
// heres a link to a converter
//http://audio.online-convert.com/convert-to-ogg
//You're going to need it
Mix_Music* MusicLoader::LoadMusic(const std::string& filename) {
	// load the filepath into a Mix_Music object
	Mix_Music* music = Mix_LoadMUS(filename.c_str());
	// if music cant be found
	if (music == nullptr) {
		// log it
		Debug::Log(EMessageType::ERROR, "MusicLoader", "MusicLoader", __FILE__, __LINE__, std::string(Mix_GetError()));
	}
	// if there is music
	if (music != nullptr) {
		// return the mix_music obj
		Debug::Log(EMessageType::INFO, "MusicLoader", "MusicLoader", __FILE__, __LINE__, "Loading " + filename);
		return music;
		// log it
	}
};