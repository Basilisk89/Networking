#ifndef ControllerManager_H
#define ControllerManager_H
#include "Controller.h"
namespace Game_Lib {
	class ControllerManager :public Controller {
	public:
		ControllerManager();
		~ControllerManager();
		// Initialize the keyboard manager , all keys are set to false
		void Initialize();
		// set the pressed key to true
		void Delete();
		void const OnPress(const unsigned int& keyCode);
		// set the released key as false
		void const OnRelease(const unsigned int& keyCode);
		// check to see if the key is actually pressed
		bool const IsPressed(const unsigned int& keyCode);
	private:
		Controller* controller;
	};
}
#endif