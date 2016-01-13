#ifndef COLLISION_H
#define COLLISION_H
#include "GameObject.h"
#include "Boy.h"
#include "Cat.h"
namespace Game_Lib {
	class Collision
	{
	public:
		Collision();
		~Collision();
		void Collision2D(GameObject* boy, GameObject* cat);
	};
}
#endif 