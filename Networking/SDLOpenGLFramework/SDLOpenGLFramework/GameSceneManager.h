#ifndef GAMESCENEMANAGER_H
#define GAMESCENEMANAGER_H
#include <stdio.h>
//This header defines general utilities to manage dynamic memory:
#include <memory>
/*Thread
Class to represent individual threads of execution.
A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space.
An initialized thread object represents an active thread of execution; Such a thread object is joinable, and has a unique thread id.*/
#include <thread>
#include "SplashScreenScene.h"
#include "SceneGame.h"
#include "LoadScene.h"
namespace Game_Lib {
	//is running boolean
	static bool isRunning;
	class GameSceneManager {
		// anything here only the GSM can use
	private:

		//fps value
		unsigned int fps;
		// window obj
		Window windowInstance;
		// SceneBase Class

		SceneBase* nextScene;
		//GSM constructor
		GameSceneManager();
		// kill the default copy constructor of the adress of a const obj
		GameSceneManager(const GameSceneManager&) = delete;
		// kill the default copy constructor of the address of the address
		GameSceneManager(GameSceneManager&&) = delete;
		// kill the = assignment operator
		Game_Lib::GameSceneManager& operator=(const Game_Lib::GameSceneManager&) = delete;
		// kill the = assignment operator
		GameSceneManager& operator=(GameSceneManager&&) = delete;
		//GSM destructor
		~GameSceneManager();
		//instance unique ptr type of GSM
		static std::unique_ptr<GameSceneManager> _instance;
		friend std::default_delete<GameSceneManager>;

	protected:
		// anything here you want other classes to use
	public:
		//build the splash screen
		SceneBase* currentScene;
		// Get the GSM instance
		static GameSceneManager* GetInstance();
		// thread method
		void Thread();
		// Run method
		void Run();
		//Run Init
		bool Initialize();
		// update method
		void Update(const float deltaTime);
		//Delete the GSM instance
		void DeleteInstance();
		//Render function
		void Render();
		void SwitchScene(const int index);
	};
}
#endif