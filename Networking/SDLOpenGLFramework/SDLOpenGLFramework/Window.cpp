//inlcude my window.h class
#include "Window.h"
// include the sstream from vc
#include <sstream>
// include the debug.h file
#include "Debug.h"
//Game_lib namespace , still just a bucket
#include "MusicPlayer.h"
using namespace Game_Lib;
//contructor window
Window::Window() :SDLWindow(nullptr), SDLRenderer(nullptr), SDLSurface(nullptr), winRect(), bIsInitialized(false), bIsFullScreen(false) {
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
	//window initialize bool set to false
	bIsInitialized = false;
	// log its starting
	Debug::Log(EMessageType::INFO, "Window", "Initialization", __FILE__, __LINE__, "trying to initialize window");
	//If it SDL cannot initialize the window
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		// log it cannot init anything
		Debug::Log(EMessageType::FATAL_ERROR, "Window", "Initialization", __FILE__, __LINE__, std::string(SDL_GetError()));
		// return the init flag as false
		Shutdown();
		return bIsInitialized = false;
	}
	
	
	// set the opengl context version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// turn on double buffering set the depth buffer to 24 bits
	// you may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	
	
	
	
	SDL_GLContext opengl3_context;
	
	
	
	
	// if SDL cannot find the render scale quality of 1?
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		// log it as a warning
		Debug::Log(EMessageType::WARNING, "Window", "Initialization", __FILE__, __LINE__, "Linear texture filtering is not enabled.");
		Shutdown();
		throw std::runtime_error("SDL_INIT FAILED");
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")) {
		// log it as a warning
		Debug::Log(EMessageType::WARNING, "Window", "Initialization", __FILE__, __LINE__, "Linear texture filtering is not enabled.");
		Shutdown();
		throw std::runtime_error("SDL_INIT FAILED");
	}
	// initialize the window now
	SDLWindow = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winRect.w, winRect.h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	// if there is NO window
	if (!SDLWindow) {
		// return a fatal error
		Debug::Log(EMessageType::FATAL_ERROR, "Window", "Initialization", __FILE__, __LINE__, "Failed to create a window!");
		//shutdown everything else in the window class
		Shutdown();
		// return the method flag as false
		return false;
	}
	//initialize the Renderer
	SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);
	// if there is no renderer
	if (!SDLRenderer) {
		// log it happened
		Debug::Log(EMessageType::FATAL_ERROR, "Window", "Initialization", __FILE__, __LINE__, std::string(SDL_GetError()));
		//shutdown everything else
		Shutdown();
		// return the flag of the method as false
		return false;
	}
	//set the Draw colour of the renderer as BLACK
	SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 255);
	//update the screen with any rendering performed since the previous call
	SDL_RenderPresent(SDLRenderer);
	// initialize the SDLsurface with the SLD _ get windows surface method
	SDLSurface = SDL_GetWindowSurface(SDLWindow);
	// set the init flag as true
	bIsInitialized = true;

  opengl3_context = SDL_GL_CreateContext(SDLWindow);
	int status = glewInit();
	getGLInfo();
	// log it happened
	Debug::Log(EMessageType::INFO, "Window", "initialize", __FILE__, __LINE__, "Window initialized");
	//return the method flag as true
	return true;
}
//shut down the window method
void Window::Shutdown() {
	//Debug::Log(EMessageType::INFO, "Window", "ShutDown", __FILE__, __LINE__, "ShutDown Window");
	// free the window , surface, and Renderer
	SDL_FreeSurface(SDLSurface);
	SDL_DestroyRenderer(SDLRenderer);
	SDL_DestroyWindow(SDLWindow);

	// then set the objs as null
	SDLSurface = nullptr;
	SDLRenderer = nullptr;
	SDLWindow = nullptr;
	delete SDLSurface,
		SDLRenderer,
		SDLWindow;
	// log it happened
	std::getchar();
	//set the init flag as false
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
// clear the renderer function
void Window::ClearRenderer() const {
	// set the draw colour to white
	SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 255);
	// then clear the renderer
	SDL_RenderClear(SDLRenderer);
	// log it happened
	//Debug::Log(EMessageType::INFO, "Window", "ClearRenderer", __FILE__, __LINE__, "Cleared Renderer");
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
//Get the renderer of the window
SDL_Renderer* Window::GetRenderer() const {
	//return the SDLRenderer
	return SDLRenderer;
	// log it happened
	Debug::Log(EMessageType::INFO, "Window", "GetRenderer", __FILE__, __LINE__, "Getting the SDL_Renderer");
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
SDL_Surface* Window::getSurface() const {
	return SDLSurface;
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
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);


	printf("GL Version - %s\n", version);
	printf("GL Version - %d.%d\n", major, minor);
	printf("Graphics card vendor - %s\n", vendor);
	printf("Graphics card name - %s\n", renderer);
	printf("GLSL Version - %s\n", glslVersion);
	getchar();
}