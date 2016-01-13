#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include "Music.h"
namespace Game_Lib {
	// The Music player class , think of this as a tape deck , you put in the music.
	// then you walk down the street with a new pair a sneaks.
	class MusicPlayer :Music {
		// the stuff a boom box should do !
	public:
		static const int const SONGLIST = 10;
		//Music player constructor
		MusicPlayer();
		//Music player destructor
		~MusicPlayer();
		// kill the default reference copy constructors
		MusicPlayer(const MusicPlayer&) = delete;
		MusicPlayer(MusicPlayer&&) = delete;
		// kill the default pointer copy constructor
	//	MusicPlayer(const MusicPlayer*) = delete;
	//	MusicPlayer(MusicPlayer**) = delete;
		//remove the assignment operator , dont need it
		MusicPlayer operator=(MusicPlayer&) = delete;
		MusicPlayer operator=(MusicPlayer&&) = delete;
		// remove the addition operator , dont need it
		MusicPlayer operator+(MusicPlayer&) = delete;
		MusicPlayer operator+(MusicPlayer&&) = delete;
		// remove the bitwise operator , dont need it
		MusicPlayer operator<<(MusicPlayer&) = delete;
		MusicPlayer operator<<(MusicPlayer&&) = delete;
		// remove the bitwise operator , dont need it
		MusicPlayer operator>>(MusicPlayer&) = delete;
		MusicPlayer operator>>(MusicPlayer&&) = delete;
		// remove the subtraction operator , dont need it
		MusicPlayer operator-(MusicPlayer&) = delete;
		MusicPlayer operator-(MusicPlayer&&) = delete;
		// load the file path into the Music class
		bool Load(const std::string& filename, const int& index);
		// play the music obj inside the player
		bool Play(const int& index, const int& loop) const;
		// stop the tape
		bool Stop() const;
		// pause the tape
		bool Pause() const;
		// resume the tape
		bool Resume() const;
		//opens the audio channels
		bool OpenAudio() const;
		// control the volume
		void Volume(int volume) const;
		//closes the AudioChannel
		bool CloseAudio() const;
		//frees the current music
		bool RemoveMusic(const int& index);
		// rewind the tape
		bool RewindToBeginning(const int& index) const;
		void DestroyPlayer();
	private:
		//My array of Music i called songs
		Music* songs[SONGLIST];
	};
}
#endif