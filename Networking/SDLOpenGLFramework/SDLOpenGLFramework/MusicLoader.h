#ifndef MUSICLOADER_H
#define MUSICLOADER_H
#include <SDL_mixer.h>
#include <string>
#include "Debug.h"
//here is SDL_MIXER gonna need it.
namespace Game_Lib {
	class MusicLoader {
	public:
		MusicLoader() = delete;
		MusicLoader(const MusicLoader&) = delete;
		MusicLoader(const MusicLoader&&) = delete;
		MusicLoader& operator=(const MusicLoader) = delete;
		MusicLoader& operator=(const MusicLoader&&) = delete;
		//Load Music place the file name and it will return a mixed music object
		static Mix_Music* LoadMusic(const std::string& filename);
		//static const Mix_music* GetLoadedMusic() const;
		//static Mix_music* SetMusic(const std::string filename);
	private:
		//static Mix_Music* music;
	};
}
#endif