#include "LoadScene.h"
using namespace Game_Lib;
LoadScene::LoadScene(Window& windowRef) :SceneBase(windowRef){
	sceneIndex = 2;
}
LoadScene::~LoadScene(){
	OnDestroy();
}

bool LoadScene::OnCreate(){
	nowloading = new Sprite(Rectangle(0.0, -100, 100, 200), windowPtr, 0.0);
	camera = Camera();
	ndc = camera.NormalizedDeviceCoord(windowPtr->GetWidth(), windowPtr->GetHeight());
	projection = camera.ScreenToWorld(ndc, 0, 800 * windowPtr->GetHeight() / windowPtr->GetWidth(), 0, 600 * windowPtr->GetHeight() / windowPtr->GetWidth(), 0, 1);
	boy.reset(new AnimatedSprite());
	boy->LoadAsset(windowPtr->GetRenderer(), "C:/GameDev/guy.png");
	nowloading->Load("C:/GameDev/loading.png");
	return true;
}

void LoadScene::OnDestroy(){
	boy.reset();
	boy = nullptr;
	delete nowloading;
	nowloading = nullptr;
}

void LoadScene::Update(const float deltaTime){
	accuTime += deltaTime * 2;
}

void LoadScene::Render() const{
	boy->Animate(0, 0, 1.0, clip, 0.0, true, flip, 8, projection);
	nowloading->Render(projection);
}

bool LoadScene::IsFinished() const{
	std::cout << accuTime << std::endl;
	if (accuTime >= 10.0f) {
		return true;
	}
	return false;
}