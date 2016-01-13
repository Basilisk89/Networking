//
#ifndef MUSIC_H
#define MUSIC_H
#include "MusicLoader.h"
#include "string"
#include "Debug.h"
namespace Game_Lib {
	/// music class which contains our Mix_Music* Obj
	///Keep in mind ogg file format music files
	class Music {
	public:
		/// Music Constructor
		Music();
		/// Music destructor
		~Music();
		/// Remove the music Obj
		bool Remove();
		/// lets let the music player do the work.
		friend class MusicPlayer;
		/// remove the addition operator , dont need it
		Music operator+(Music&) = delete;
		Music operator+(Music&&) = delete;
		/// remove the bitwise operator , dont need it
		Music operator<<(Music&) = delete;
		Music operator<<(Music&&) = delete;
		/// remove the bitwise operator , dont need it
		Music operator>>(Music&) = delete;
		Music operator>>(Music&&) = delete;
		/// remove the subtraction operator , dont need it
		Music operator-(Music&) = delete;
		Music operator-(Music&&) = delete;
		/// i wanna make Music class be able to equal its self and give its self some music !
		inline Music operator=(Music* _music) {
			///this music = the music im passing in
			music = _music->music;
		}
		/// I wanna make Music class be abile to equal its self and give its self some songs?
		inline Music operator=(Music** _music) {
			// music = _music[]->music;
		}
	private:
		///Private Music obj pointer , i only want our music player to handle it
		Mix_Music *music;
	};
}
#endif
