#ifndef WINDOW_H
#define WINDOW_H
#include "Debug.h"
#include <glew.h>
#include <GL/gl.h>
#include <SDL.h>
enum WindowType : unsigned int {
	SDLWindow = 0,
	OpenGLWINDOW = 1
};
namespace Game_Lib {
	class Window {
	public:
		Window();
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;
		~Window();
		bool Initialize();
		void Shutdown();
		void SetWindowSize(const int Width_, const int Height_);
		void ToggleFullScreen();
		SDL_Window* getWindow() const;
		SDL_Rect getRect();
		int GetWidth() const;
		int GetHeight() const;
	protected:
	private:
		SDL_Window* SDLWindow;
		SDL_GLContext glContext;
		int Width;
		int Height;
		SDL_Rect winRect;
		bool bIsInitialized;
		bool bIsFullScreen;
		void getGLInfo();
	};
}

#endif