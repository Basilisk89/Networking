//# predefined compiler operatives
//<> go to where the includes are
#include <stdio.h>
#include <stdlib.h>
#include <thread>
//Include GameSceneManager
#include "Main.h"
using namespace Game_Lib;
GameSceneManager* gsm;
void Game_Lib::MainInitialize() {
}
// old Main call
// int args
// char *argv[] i would like the pointer/address to the argv character array
int main(int args, char *argv[]) {
	Game_Lib::MainInitialize();

	Debug::clean();
	Debug::Log(EMessageType::INFO, "Main", "Main", __FILE__, __LINE__, "Main started");
	gsm = GameSceneManager::GetInstance();
	gsm->Run();

		
		return 0;
	
}

// when closing Program , since GameSceneManager is on the stack , since its out of scope , it calls its detructor.
//dynamic binding need to read up on