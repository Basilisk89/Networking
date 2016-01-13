#pragma once
#include "SceneBase.h"
#include "AnimatedSprite.h"
#include "Camera.h"

namespace Game_Lib {
	class LoadScene :public SceneBase
	{
	public:
		explicit LoadScene(Window& windowRef);
		LoadScene(const LoadScene&) = delete;
		LoadScene(LoadScene&&) = delete;
		LoadScene& operator=(const LoadScene&) = delete;
		LoadScene& operator= (LoadScene&&) = delete;
		virtual ~LoadScene();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual bool IsFinished() const;
		std::unique_ptr<AnimatedSprite> boy;
		friend std::default_delete<GameObject>;
		float accuTime;
		Matrix4 ndc, projection;
		Camera camera;
		SDL_RendererFlip flip;
		SDL_Rect* clip;
		Sprite* nowloading;
	private:
	};
}