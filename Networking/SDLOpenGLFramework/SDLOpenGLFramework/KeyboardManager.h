#ifndef KeyboardManager_H
#define KeyboardManager_H
#include "Keyboard.h"
namespace Game_Lib {
	class KeyboardManager :public Keyboard {
	public:

		KeyboardManager();

		~KeyboardManager();

		KeyboardManager(KeyboardManager&) = delete;
		KeyboardManager(KeyboardManager&&) = delete;

		KeyboardManager operator = (KeyboardManager&) = delete;
		KeyboardManager operator = (KeyboardManager&&) = delete;
		// initialize all boolean values of keyboard to false *CALL THIS IN OnCreate*
		void Initialize();
		// deletes the boolean array inside keyboard and set the pointer to the keyboard to nullptr *Call this in OnDestroy*
		void Delete();
		// Set the key index inside keyboard and set it to true *Call this after your case of ON_CLICK while polling the event inside update function of Scene*
		// example
		/*	case Keyboard::State::KEYDOWN:
		keyboard.OnPress(SDLEvent.type);*/
		void OnPress(const unsigned int& keyCode);
		//Set the key index inside keyboard and set it to false *Call this after your case of OFF_CLICK while polling the event inside update function of scene*
		// example
		/*	case Keyboard::State::KEYUP:
		keyboard.OnRelease(SDLEvent.type);*/
		void OnRelease(const unsigned int& keyCode);
		bool IsReleased(const unsigned int & keyCode);
		//return a boolean if the key was pressed or not *Call this when making any scancode call * after OnPress call
		//example
		/*if (keyboard.IsPressed(Keyboard::Key::A))*/
		bool IsPressed(const unsigned int& keyCode);
	private:
		// our Keyboard class , contains our keyboard booleans.
		Keyboard* keyboard;
	};
}
#endif
/*WARNING
still a work in progress , This technically is a one shot deal and will only really work
within the event thats polling, it will fire every time and keys will repeat , but there is a slight delay
when pressing the key down , for roughly half a second then it will consistantly repeat.
Also want to point out the managers do all the work, no need to call mouse or keyboard class objects.
*NOTE*
IF you have anything you want to add or change feel free! this is yours now , if you have any problems ,
here is my e-mail Ryan.aj.holubeshen@bell.net.
if you feel changes need to be changed for the betterment of the class
talk to Scott. */