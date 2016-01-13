#pragma once
#include "SceneBase.h"
#include "Boy.h"
#include "Cat.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "EventHandler.h"
#include "Camera.h"
#include "Sprite.h"
#include "Collision.h"
#include "AnimatedSprite.h"
namespace Game_Lib {
	class SceneGame : public SceneBase {
	public:
		explicit SceneGame(Window& windowRef);
		virtual ~SceneGame();
		SceneGame(const SceneGame&) = delete;
		SceneGame(SceneGame&&) = delete;
		SceneGame& operator=(const	SceneGame&) = delete;
		SceneGame& operator=(SceneGame&&) = delete;
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual bool IsFinished() const;
		GameObject *cat;
		MusicPlayer musicplayer;
		KeyboardManager keyboard;
		MouseManager mouse;
		EventHandler eventhandler;
		Camera camera;
		Matrix4 ndc, ortho, projection;
		Sprite* bg;
		SDL_Event SDLevent;
		Collision c;
		AnimatedSprite* boy2;
		SDL_RendererFlip flip;
		SDL_Rect* clip;
		int FrameTime;
	private:
		std::vector<std::unique_ptr<GameObject>> boys;
	};
}
