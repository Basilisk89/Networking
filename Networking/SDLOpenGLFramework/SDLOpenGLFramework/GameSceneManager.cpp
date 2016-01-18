#include "Timer.h"
#include "GameSceneManager.h"
#include <assert.h>
using namespace Game_Lib;
/// See the header file regarding unique_ptr
std::unique_ptr<GameSceneManager> GameSceneManager::_instance(nullptr);
GameSceneManager* GameSceneManager::GetInstance() {
	Debug::Log(EMessageType::INFO, "GSM", "getInstance", __FILE__, __LINE__, "Checking if the _instance obj is NULL or a null address");
	// if there is no instance for the unique pointer to retrieve
	if (_instance.get() == nullptr) {
		/// I originally set the unique_ptr to be null in the constructor -
		/// reset() sets the new address
		Debug::Log(EMessageType::INFO, "GSM", "getInstance", __FILE__, __LINE__, "Reseting unique ptr adress");
		// reset the new adress located in the unique ptr
		_instance.reset(new GameSceneManager());
	}
	Debug::Log(EMessageType::INFO, "GSM", "getInstance", __FILE__, __LINE__, "returning the instance");
	// return the instance of the unique ptr
	return _instance.get();
}
void GameSceneManager::DeleteInstance() {
	// if there is a instance to get within the unique ptr
	if (_instance.get()) {
		// log it
		Debug::Log(EMessageType::INFO, "GSM", "DeleteInstance", __FILE__, __LINE__, "Deleting Instance");
		// shut down the window
		windowInstance.Shutdown();
		// release the pointer within the unique ptr

		currentScene = nullptr;
		delete currentScene;
		_instance.release();
		// set the _instance to NULL
		_instance = nullptr;
	}
}
GameSceneManager::GameSceneManager() : windowInstance(), fps(60), currentScene(nullptr) {
	Debug::Log(EMessageType::INFO, "GSM", "GameSceneManager", __FILE__, __LINE__, "Hello from the constructor");
}
GameSceneManager::~GameSceneManager() {
	currentScene->isRunning = false;
	//	Debug::Log(EMessageType::INFO, "GSM", "~GameSceneManager", __FILE__, __LINE__, "good bye");
}

void GameSceneManager::Thread() {  /// Just a threading demo
	Debug::Log(EMessageType::INFO, "GSM", "Thread", __FILE__, __LINE__, "starting Thread logic");
	int j = 0;
	for (int i = 0; i >= j; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "::Hello from thread " << i << " Times" << std::endl;
	}
}
bool GameSceneManager::Initialize() {
	Debug::Log(EMessageType::INFO, "GSM", "Initialize", __FILE__, __LINE__, "setting windowSize of 1100 , 768");
	// set GSMs windowInstance windows sizw to 1000, 768 the size of the limbo picture
	windowInstance.SetWindowSize(1280, 720);
	Debug::Log(EMessageType::INFO, "GSM", "Initialize", __FILE__, __LINE__, "checking to see if windowInstance.initialize returns false");
	// if Initialize returns false
    windowInstance.Initialize();

	currentScene = new SplashScreenScene(windowInstance);
	
	Debug::Log(EMessageType::INFO, "GSM", "Initialize", __FILE__, __LINE__, "instantiating scene");
		 currentScene->OnCreate();
		
		 return true;
}

void GameSceneManager::Run() {
	isRunning = Initialize();
	
	Timer timer;
	timer.Start();
	while (isRunning) {
		timer.UpdateFrameTicks();
		HandleEvents();
		Update(timer.GetDeltaTime());
	
		Render();
		SDL_Delay(timer.GetSleepTime(fps));

	}
}
void GameSceneManager::Render() {
//	windowInstance.ClearRenderer();
	if (currentScene == nullptr) {
		std::cout << "No scene selected as current scene" << std::endl;
		assert(currentScene);
	}
	currentScene->Render();
//	SDL_RenderPresent(windowInstance.GetRenderer());
}
void GameSceneManager::Update(const float deltaTime) {
	if (currentScene) currentScene->Update(deltaTime);
}
void GameSceneManager::SwitchScene(const int index) {
	if (index == 0) {
		delete currentScene;
		currentScene = nullptr;
		if (currentScene == nullptr) {
			currentScene = new SplashScreenScene(windowInstance);
			currentScene->OnCreate();
			Debug::Log(EMessageType::INFO, "GSM", "SwitchScene", __FILE__, __LINE__, "Scene Swapped");
		}
	}
}

void GameSceneManager::HandleEvents() {
	SDL_Event SDLEvent;

	while (SDL_PollEvent(&SDLEvent)) {
		switch (SDLEvent.type) {
		case SDL_EventType::SDL_QUIT:
			isRunning = false;
			return;
		case SDL_EventType::SDL_MOUSEBUTTONDOWN:
		case SDL_EventType::SDL_MOUSEBUTTONUP:
		case SDL_EventType::SDL_MOUSEMOTION:
			assert(currentScene);
			currentScene->HandleEvents(SDLEvent);
			break;
		default:
			break;
		}
	}
}