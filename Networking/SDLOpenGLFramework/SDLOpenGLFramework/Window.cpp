//inlcude my window.h class
#include "Window.h"
// include the sstream from vc
#include <sstream>
// include the debug.h file
#include <cassert>
using namespace Game_Lib;
//contructor window
Window::Window() :SDLWindow(nullptr), winRect(),glContext(nullptr), bIsInitialized(false), bIsFullScreen(false) {
	//log from the constructor
	Debug::Log(EMessageType::INFO, "Window", "Window", __FILE__, __LINE__, "Window Constructor");
}
//destructor window
Window::~Window() {
	// call shutdown of the window
	Shutdown();
	// log it happened
	//Debug::Log(EMessageType::INFO, "Window", "~Window", __FILE__, __LINE__, "Good bye from window");
}
// Window initialize function
bool Window::Initialize() {
	bIsInitialized = false;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		Debug::Log(EMessageType::FATAL_ERROR,"", std::string(SDL_GetError()), __FILE__, __LINE__,"");
		return bIsInitialized;
	}

	/// These attributes must be set before the SDL window is created 

	/// You may need to change this to 16 or 32 depending on your graphics card
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);/// Enable Depth Cueing (the Z-buffer) 
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);/// Turn on double buffering with a 24bit Z buffer. 

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);


	/// Create the SDL window
	SDLWindow = SDL_CreateWindow("Component Framework Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		winRect.w, winRect.h, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE| SDL_WINDOW_SHOWN);
	if (SDLWindow == nullptr) {
		Debug::Log(EMessageType::FATAL_ERROR,"", SDL_GetError(), __FILE__, __LINE__,"");
		return false;
	}

	/// Attach OpenGl to the new Window
	glContext = SDL_GL_CreateContext(SDLWindow);
	if (glContext == nullptr) {
		Debug::Log(EMessageType::FATAL_ERROR,"", SDL_GetError(), __FILE__, __LINE__,"");
		return false;
	}

	/// Fire up the GL Extension Wrangler
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK) {
		Debug::Log(EMessageType::FATAL_ERROR,"", (char*)glewGetErrorString(glewError), __FILE__, __LINE__,"");
		assert(0);
	}

	/// This makes the buffer swap syncronize with the monitor's vertical refresh 
	if (SDL_GL_SetSwapInterval(1) < 0) {
		Debug::Log(EMessageType::WARNING,"", SDL_GetError(), __FILE__, __LINE__,"");
	}

	Debug::Log(EMessageType::INFO,"" ,(char*)glewGetString(GLEW_VERSION), __FILE__, __LINE__,"");
	getGLInfo();


	bIsInitialized = true;
	return true;
}
//shut down the window method
void Window::Shutdown() {
	SDL_DestroyWindow(SDLWindow);
	SDL_Quit();
	SDL_GL_DeleteContext(glContext);
	SDLWindow = nullptr;
	glContext = nullptr;



	bIsInitialized = false;
}
//Set the window size
void Window::SetWindowSize(const int Width_, const int Height_) {
	//set the width and hieght of the window class
	winRect.w = Width_;
	winRect.h = Height_;
	// log it happened
	Debug::Log(EMessageType::INFO, "Window", "SetWindowSize", __FILE__, __LINE__, "Setting Window Size");
}

// toggle fullscreen method
void Window::ToggleFullScreen() {
	// this fullscreen flag is = what it is not.
	bIsFullScreen = !bIsFullScreen;
	// Set the Window to Fullscreen or not fullscreen
	SDL_SetWindowFullscreen(SDLWindow, (bIsFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
	// log it happened
	Debug::Log(EMessageType::INFO, "Window", "ToggleFullScreen", __FILE__, __LINE__, "Fullscreen Toggled");
}

//Get the width of the window
int Window::GetWidth() const {
	// return width for the method
	return winRect.w;
	// log it
	Debug::Log(EMessageType::INFO, "Window", "GetWidth", __FILE__, __LINE__, "Getting the Width of the Window");
}
// get the height of the window
int Window::GetHeight() const {
	// return heigth for the method
	return winRect.h;
	//log it happened
	Debug::Log(EMessageType::INFO, "Window", "GetHeight", __FILE__, __LINE__, "Getting the Height of the Window");
}

SDL_Window* Window::getWindow() const {
	return SDLWindow;
}
SDL_Rect Window::getRect() {
	return winRect;
}
/// Debug info about the graphics card and version of OpenGL installed
void Window::getGLInfo() {
	/// You can (and probably need) to get some info regarding versions and manufacturer
	const GLubyte *version = glGetString(GL_VERSION);
	/// You can also get the version as ints	
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);


	printf("GL Version - %s\n", version);
	printf("Graphics card vendor - %s\n", vendor);
	printf("Graphics card name - %s\n", renderer);
	printf("GLSL Version - %s\n", glslVersion);
}