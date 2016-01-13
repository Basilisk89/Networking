#include "SceneGame.h"

using namespace Game_Lib;
SceneGame::~SceneGame() {
	OnDestroy();
}

Game_Lib::SceneGame::SceneGame(Window & windowRef) :SceneBase(windowRef) {
	sceneIndex = 3;
}
bool Game_Lib::SceneGame::OnCreate()
{
	camera = Camera();
	ndc = camera.NormalizedDeviceCoord(windowPtr->GetWidth(), windowPtr->GetHeight());
	projection = camera.ScreenToWorld(ndc, 0, windowPtr->GetWidth() * windowPtr->GetHeight() / windowPtr->GetWidth(), 0, windowPtr->GetHeight() * windowPtr->GetHeight() / windowPtr->GetWidth(), 0, 1);
	SDL_Event SDLevent;
	SDLevent = SDL_Event();
	eventhandler.Initialize(SDLevent);
	keyboard.Initialize();
	mouse.Initialize();
	cat = new Cat(Rectangle(150, -900, 50, 50), windowPtr, 0);
	bg = new Sprite(Rectangle(0.0, 0.0, windowPtr->GetHeight(), windowPtr->GetWidth()), windowPtr, 0);
	// Load the Vector Container<of unique_ptrs containing<GameObject>> with the boy sub class
	boys.push_back(std::unique_ptr<GameObject>(new Boy(Rectangle(10, -1300, 30, 40), windowPtr, 0.0f)));
	boys.push_back(std::unique_ptr<GameObject>(new Boy(Rectangle(400, -1300, 30, 40), windowPtr, 0.0f)));

	for (int i = 0; i < boys.size(); i++)
		boys.at(i)->OnCreate("C:/GameDev/hero.png");

	cat->OnCreate("C:/GameDev/Spider.png");
	bg->Load("C:/GameDev/background.jpg");

	boys.at(1)->LeftFlip();
	musicplayer.OpenAudio();
	musicplayer.Load("C:/GameDev/MakoReactor.ogg", 0);
	musicplayer.Volume(100);
	musicplayer.Play(0, -1);
	return true;
}

void Game_Lib::SceneGame::OnDestroy() {
	musicplayer.Stop(),
		musicplayer.CloseAudio(),
		delete cat;
	delete bg, boy2, mouse, keyboard, eventhandler, musicplayer;
	boy2 = nullptr, bg = nullptr, cat = nullptr;
	for (int i = 0; i < boys.size(); i++) {
		boys.at(i).reset();
		boys.at(i) = nullptr;
	}
	boys.clear();
	Debug::Log(EMessageType::INFO, "SceneGame", "OnDestroy", __FILE__, __LINE__, "Deleting");
}

void Game_Lib::SceneGame::Update(const float deltaTime) {
	if (cat != nullptr)

		cat->Update(deltaTime);

	for (int i = 0; i < boys.size(); i++) {
		boys.at(i)->Update(deltaTime);

		if (cat && boys.at(i) != nullptr) {
			c.Collision2D(boys.at(0).get(), cat);
			c.Collision2D(boys.at(0).get(), boys.at(1).get());

			while (eventhandler.Update()) {
				// figure out what event type it is
				switch (eventhandler.getType()) {
				case Keyboard::State::KEYDOWN:
					keyboard.OnPress(eventhandler.getScanCode());
					if (keyboard.IsPressed(Keyboard::Key::D)) {
						Vec4 move;
						move.x = 30;
						boys.at(0)->velocity.x = move.x;
						boys.at(0)->RightFlip();
						boys.at(1)->velocity.x = -move.x;
						boys.at(1)->LeftFlip();
					}if (keyboard.IsPressed(Keyboard::Key::A)) {
						Vec4 move;
						move.x = -30;
						boys.at(0)->velocity.x = move.x;
						boys.at(0)->LeftFlip();
						boys.at(1)->velocity.x = -move.x;
						boys.at(1)->RightFlip();
					}if (keyboard.IsPressed(Keyboard::Key::SPACE) && !keyboard.IsPressed(Keyboard::Key::D) && !keyboard.IsPressed(Keyboard::Key::A)) {
						Vec4 move;
						move.y = 250;
						boys.at(0)->velocity.y = move.y;
						boys.at(1)->velocity.y = move.y;
					}if (keyboard.IsPressed(Keyboard::Key::SPACE) && keyboard.IsPressed(Keyboard::Key::D)) {
						if (boys.at(0)->IsFlipped() != true) {
							Vec4 move;
							move.y += 50;
							boys.at(0)->velocity.y += move.y;
							boys.at(0)->velocity.x += 50.0;
						}if (keyboard.IsPressed(Keyboard::Key::SPACE) && keyboard.IsPressed(Keyboard::Key::A)) {
							if (boys.at(1)->IsFlipped() == true) {
								Vec4 move;
								move.y = 50;
								boys.at(0)->velocity.y += move.y;
								boys.at(0)->velocity.x = -50.0;
							}
						}
					}if (keyboard.IsPressed(Keyboard::Key::ESCAPE)) {
					}
					break;
				case Keyboard::State::KEYUP:
					keyboard.OnRelease(eventhandler.getScanCode());
					if (keyboard.IsReleased(Keyboard::Key::D)) {
						boys.at(0)->velocity.x = 0.0;
						boys.at(1)->velocity.x = 0.0;
					}if (keyboard.IsReleased(Keyboard::Key::A)) {
						boys.at(0)->velocity.x = 0.0f;
						boys.at(1)->velocity.x = 0.0f;
					}if (keyboard.IsReleased(Keyboard::Key::SPACE)) {
					}
					break;
				}
			}
		}
	}
}

void Game_Lib::SceneGame::Render() const {
	if (projection != NULL) {
		bg->Render(projection);
		cat->Render(projection);
		for (int i = 0; i < boys.size(); i++) {
			boys.at(i)->Render(projection);
		}
	}
	else {}
}

bool Game_Lib::SceneGame::IsFinished() const {
	if (boys.at(0)->position.x + boys.at(0)->radius >= 400) {
		return true;
	}
	return false;
}