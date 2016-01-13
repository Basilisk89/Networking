#ifndef SCENE_H
#define SCENE_H
#include "SDL.h"
#include "Window.h"
#include "Debug.h"
#include "ImageLoader.h"
#include "MusicPlayer.h"
#include "boy.h"
#include "fly.h"
#include "Cat.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "EventHandler.h"
#include "Camera.h"
#include "Sprite.h"
#include "Collision.h"
#include <vector>

namespace Game_Lib {
	class SceneBase {
	public:
		explicit SceneBase(class Window& windowRef);
		virtual ~SceneBase();
		SceneBase(const SceneBase&) = delete;
		SceneBase(SceneBase&&) = delete;
		SceneBase& operator = (const SceneBase&) = delete;
		SceneBase& operator = (SceneBase&&) = delete;
		/// Create the following four abstract functions and make them polymorphic
		/// The proper term for these are "pure viruals"
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void Update(const float deltaTime) = 0;
		virtual void Render() const = 0;
		virtual bool IsFinished() const = 0;
		bool isRunning = true;
		int sceneIndex;
	protected:
		Window* windowPtr;
	};
}
#endif
