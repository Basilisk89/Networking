#include "Collision.h"
#include <stdio.h>

using namespace Game_Lib;

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::Collision2D(GameObject* boy, GameObject* cat)
{
	float distance = VMath::distance(boy->position, cat->position);

	if (distance < boy->radius + cat->radius)
	{
		Vec4 vector, Normal;
		vector.x = boy->position.x - cat->position.x;
		vector.y = boy->position.y - cat->position.y;
		float StandDistance = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z + vector.z));

		Normal = vector;
		float normal = VMath::Normalize(Normal);

		float damp = 2.0;
		Vec4 vector2;
		vector2 = VMath::dot(cat->velocity*damp, vector);

		Vec4 vector1;
		vector1 = VMath::dot(boy->velocity*damp, vector);

		float e = -1.0;

		Vec4 newvector1, newvector2;

		//newvector1 = ((ball1->mass - e*ball2->mass)*vector1 + (1+e) *ball2->mass*vector2)/(ball1->mass+ball2->mass);
		//newvector2 = ((ball2->mass - e*ball1->mass)*vector2 + (1+e) *ball1->mass*vector1)/(ball1->mass+ball2->mass);

		boy->velocity += 2 * (vector1 - vector1) * vector;
		cat->velocity += 2 * (vector2 - vector2) * vector;

		float touchingDistance = 1;
		float offset = 0.5f * (touchingDistance - normal);
		std::cout << cat->position << boy->position << std::endl;
		boy->velocity += vector;
		cat->velocity -= vector;
		std::cout << "Collision" << std::endl;
	}
}