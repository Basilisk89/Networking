#ifndef SCENE_H
#define SCENE_H

#include "Window.h"
#include "Debug.h"

#include "MusicPlayer.h"

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
		virtual void HandleEvents(const SDL_Event &SDLEvent) = 0;
		bool isRunning = true;
		int sceneIndex;
	protected:
		Window* windowPtr;
	};
}
#endif
