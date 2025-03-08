#pragma once

class GameObject;

class Collider
{
public:
	Collider();
	virtual ~Collider();
	static int Collide(GameObject* go, std::vector<GameObject*> allObjects, int windowSizeX, int windowSizeY, bool collideWithWindowBorders = true);

};
