#ifndef SPLASHSCREENSCENE_H
#define SPLASHSCREENSCENE_H
#include "SceneBase.h"
#include "Boy.h"

namespace Game_Lib {
	class SplashScreenScene : public SceneBase {
	public:
		explicit SplashScreenScene(Window& windowRef);
		virtual ~SplashScreenScene();
		SplashScreenScene(const SplashScreenScene&) = delete;
		SplashScreenScene(SplashScreenScene&&) = delete;
		SplashScreenScene& operator=(const SplashScreenScene&) = delete;
		SplashScreenScene& operator=(SplashScreenScene&&) = delete;
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual bool IsFinished() const;
		MusicPlayer musicplayer;
		KeyboardManager keyboard;
		MouseManager mouse;
		EventHandler eventhandler;
		Camera camera;
		Matrix4 ndc, ortho, projection;
		Sprite* bg;
		SDL_Event SDLevent;
		Collision c;
		std::vector<GameObject*> Flys;
		std::unique_ptr<GameObject> boy;
	};
}
#endif 