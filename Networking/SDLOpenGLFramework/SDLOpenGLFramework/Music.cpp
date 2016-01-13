#include "Music.h"
using namespace Game_Lib;
//Music class constructor
Music::Music() :music(nullptr) {
	Debug::Log(EMessageType::INFO, "Music", "Music", __FILE__, __LINE__, "Music Constructor");
}
//Music class Destructor
Music::~Music() {
	//Remove the music
	Remove();
	// log it happened
	Debug::Log(EMessageType::INFO, "Music", "~Music", __FILE__, __LINE__, "Music Detructor");
}
// removes the current music object
bool Music::Remove() {
	//Halt the music
	Mix_HaltMusic();
	//Free the Music obj

	music = nullptr;
	delete music;
	Debug::Log(EMessageType::INFO, "Music", "Remove", __FILE__, __LINE__, "Music Removed");
	return true;
}