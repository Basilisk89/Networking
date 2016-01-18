#ifndef SPLASHSCREENSCENE_H
#define SPLASHSCREENSCENE_H
#include "SceneBase.h"
#include "MusicPlayer.h"
#include "Shader.h"
#include "QuadSphere.h"
#include "Camera.h"
#include "LoadCubeMapRAW.h"
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
	
		virtual void HandleEvents(const SDL_Event &SDLEvent);
	private:
		Shader* shader;
		QuadSphere* sphere;
		Camera* camera;
		GLuint timeParam;
		
		GLuint noiseTex;
		float t;
	};
}
#endif 