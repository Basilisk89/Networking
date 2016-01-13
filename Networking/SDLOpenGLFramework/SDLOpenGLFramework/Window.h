#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <glew.h>
#include <glut.h>
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
		void ClearRenderer() const;
		void SetWindowSize(const int Width_, const int Height_);
		void ToggleFullScreen();
		SDL_Renderer* GetRenderer() const;
		SDL_Surface* getSurface() const;
		SDL_Window* getWindow() const;
		SDL_Rect getRect();
		int GetWidth() const;
		int GetHeight() const;
		SDL_GLContext SDLGLContext;
	protected:
	private:
		SDL_Window* SDLWindow;
		SDL_Renderer* SDLRenderer;
		SDL_Surface* SDLSurface;
	
		int Width;
		int Height;
		SDL_Rect winRect;
		bool bIsInitialized;
		bool bIsFullScreen;
		void getGLInfo();
	};
}

#endif