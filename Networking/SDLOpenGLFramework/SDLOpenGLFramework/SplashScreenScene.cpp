#include "SplashScreenScene.h"


using namespace Game_Lib;
GLuint CreateNoise3D();
SplashScreenScene::SplashScreenScene(class Window& windowRef) : SceneBase(windowRef) { sceneIndex = 1; }
SplashScreenScene::~SplashScreenScene() {
	Debug::Log(EMessageType::INFO, "SSS", "Delete", __FILE__, __LINE__, "Deleting Instance");
	OnDestroy();
}
bool SplashScreenScene::OnCreate() {
	/// load up the shader
	shader = new Shader("Shaders/sunVert.glsl", "Shaders/sunFrag.glsl", "vVertex", "vNormal", "vTexture", "vColor"); ///"vTexture","vColor");
	sphere =  new QuadSphere(3);
	
	timeParam = glGetUniformLocation(shader->getShader(), "time");
	noiseTex = CreateNoise3D();
	GLuint sunTextLoc = loadCubeMapRAW("sun.raw", "sun.raw", "sun.raw", "sun.raw", "sun.raw", "sun.raw", 128, 128);
	GLuint sunTexture = glGetUniformLocation(shader->getShader(), "sunTexture");
	
	shader->handleStdUniforms("projMatrix", "modelViewMatrix", "normalMatrix", "light_Pos");
	
	glUniform1i(noiseTex, glGetUniformLocation(shader->getShader(), "noiseTexture"));
	glUniform1i(sunTextLoc, sunTexture);

	camera = Camera::getInstance();
	
	camera->viewPort(windowPtr->GetWidth(),windowPtr->GetHeight());

	camera->loadPerspective(53.13f,camera->aspectRatio, 0.1, 100);
	
	camera->loadLookAt(Vec3(0, 0, 3), Vec3(0, 0, 0), Vec3(0, 1, 0));
	


	// set up music obj
	musicplayer.OpenAudio();
	musicplayer.Load("C:/GameDev/FFXIV_OST_Azys_Lla_Theme.mp3", 0);
	musicplayer.Volume(100);
	musicplayer.Play(0, -1);
	Debug::Log(EMessageType::INFO, "SSS", "OnCreate", __FILE__, __LINE__, "Assets loaded");
	return true;
}
/// Cleanup Assets
void SplashScreenScene::OnDestroy() {
	
	Debug::Log(EMessageType::INFO, "SplashScreenScene", "OnDestroy", __FILE__, __LINE__, "Destroying assets");
}
void SplashScreenScene::Update(const float deltaTime) {
	t += deltaTime;
}
/// Draw you scene
void SplashScreenScene::Render() const {
	/// Draw your scene here
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Camera* camera = Camera::getInstance();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glUseProgram(shader->getShader());


	camera->push();
	
	/// Pass the projection and modelview matricies down to the GPU
	glUniformMatrix4fv(shader->getStdUniformLoc(Shader::PROJECTION_MATRIX), 1, GL_FALSE, camera->getMatrixfv(PROJECTION));
	glUniformMatrix4fv(shader->getStdUniformLoc(Shader::MODELVIEW_MATRIX), 1, GL_FALSE, camera->getMatrixfv(MODELVIEW));
	glUniformMatrix3fv(shader->getStdUniformLoc(Shader::NORMAL_MATRIX), 1, GL_FALSE, camera->getMatrixfv(NORMAL));

//	Vec4 light(0.0, 15.0, 15.0, 0.0);
//	glUniform4fv(shader->getStdUniformLoc(Shader::LIGHT_POS), 1, light);
	
	
glUniform1f(timeParam, t / 100);
	sphere->render();
	camera->pop();
	
	glUseProgram(0);

	SDL_GL_SwapWindow(windowPtr->getWindow());
}

bool Game_Lib::SplashScreenScene::IsFinished() const {
	
	return false;
}void SplashScreenScene::HandleEvents(const SDL_Event& SDLEvent) {
		std::cout << "event!!" << std::endl;
}