#include "MusicPlayer.h"
using namespace Game_Lib;
MusicPlayer::MusicPlayer() :Music() {
	Debug::Log(EMessageType::INFO, "MusicPlayer", "MusicPlayer", __FILE__, __LINE__, std::string(Mix_GetError()));
}
MusicPlayer::~MusicPlayer() {
	DestroyPlayer();
	Debug::Log(EMessageType::INFO, "MusicPlayer", "~MusicPlayer", __FILE__, __LINE__, std::string(Mix_GetError()));
}
bool MusicPlayer::Load(const std::string& filename, const int& index) {
	songs[index] = new Music();
	songs[index]->music = MusicLoader::LoadMusic(filename.c_str());
	Debug::Log(EMessageType::INFO, "MusicPlayer", "Load", __FILE__, __LINE__, " " + filename);
	return true;
}
bool MusicPlayer::Play(const int& index, const int& loop) const {
	MusicPlayer::Stop();
	if (songs[index] && Mix_PlayingMusic() >= 0) {
		Mix_PlayMusic(songs[index]->music, loop);
		Debug::Log(EMessageType::INFO, "MusicPlayer", "Play", __FILE__, __LINE__, "Playing Music");
	}
	return true;
}
bool MusicPlayer::Stop() const {
	if (Mix_PlayingMusic() >= 0)
		Mix_HaltMusic();
	Debug::Log(EMessageType::INFO, "MusicPlayer", "Stop", __FILE__, __LINE__, "Music Stopped");
	return true;
}
bool MusicPlayer::Pause() const {
	Mix_PauseMusic();
	Debug::Log(EMessageType::INFO, "MusicPlayer", "Pause", __FILE__, __LINE__, "Music Paused");
	return true;
}
bool MusicPlayer::Resume() const {
	Mix_ResumeMusic();
	Debug::Log(EMessageType::INFO, "MusicPlayer", "Resume", __FILE__, __LINE__, "Resuming Music");
	return true;
}
void MusicPlayer::Volume(int volume) const {
	if (Mix_PausedMusic < 0 && Mix_PlayingMusic() >= 0) {
		Mix_VolumeMusic(volume);
	}
}
bool MusicPlayer::RemoveMusic(const int& index) {
	songs[index]->Remove();

	Debug::Log(EMessageType::INFO, "MusicPlayer", "RemoveMusic", __FILE__, __LINE__, "Removing Music");
	return true;
}
bool MusicPlayer::RewindToBeginning(const int& index) const {
	if (Mix_PlayingMusic() <= 0)
		Mix_RewindMusic();
	return true;
}
void Game_Lib::MusicPlayer::DestroyPlayer()
{
	for (int i = 0; i < SONGLIST; i++) {
		delete songs[i];
		songs[i] = nullptr;
	}
	Stop();
	CloseAudio();
}
bool MusicPlayer::OpenAudio() const {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		Debug::Log(EMessageType::FATAL_ERROR, "MusicPlayer", "Open Audio", __FILE__, __LINE__, "Tercon locked " + std::string(Mix_GetError()));
		throw std::runtime_error("Failed to open audio");
		return false;
	}
	Debug::Log(EMessageType::INFO, "MusicPlayer", "OpenAudio", __FILE__, __LINE__, "Openning Channel");
	return true;
}
bool MusicPlayer::CloseAudio() const {
	Mix_CloseAudio();
	return true;
}