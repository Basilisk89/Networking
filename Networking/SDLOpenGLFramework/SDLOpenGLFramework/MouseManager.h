# ifndef MouseManager_H
#define MouseManager_H
#include "Mouse.h"
namespace Game_Lib {
	class MouseManager :public Mouse {
	public:
		MouseManager();
		MouseManager(MouseManager&) = delete;
		MouseManager(MouseManager&&) = delete;
		MouseManager operator = (MouseManager&) = delete;
		MouseManager operator = (MouseManager&&) = delete;
		~MouseManager();
		// initialize all boolean values of mouse to false
		//*CALL THIS IN OnCreate*
		void Initialize();
		// deletes the boolean array inside mouse
		//and set the pointer to the mouse to nullptr
		//*Call this in OnDestroy*
		void Delete();
		// Set the mousebutton index inside mouse and set it to true
		//*Call this after your case of KEYUP while polling the event inside update function of Scene*
		// example
		/*	case Mouse::State::DOWN_CLICK:
			mouse.OnPress(SDLEvent.button.button);*/
		void OnPress(const int keyCode);
		//Set the mousebutton index inside mouse and set it to false
		//*Call this after your case of KEYDOWN while polling the event inside update function of scene*
		// example
		/*	case Mouse::State::UP_CLICK:
			mouse.OnRelease(SDLEvent.button.button);*/
		void OnRelease(const int keyCode);
		//return a boolean if the key was pressed or not
		//*Call this when making any scancode call * after OnPress call
		//example
		/*if (mouse.IsPressed(Mouse::Buttons::LEFT_BUTTON))*/
		bool IsPressed(const int keyCode);

		Vec2 GetMouseCoordinates() const;

		void SetMouseCoordinates(const int x, const int y);
	private:
		// our private mouse , dont want anything except the mouse manager to deal with this object
		Mouse* mouse;
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