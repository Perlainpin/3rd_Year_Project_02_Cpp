#include "pch.h"
#include "Collider.h"
#include "GameObject.h"

Collider::Collider()
{

}

Collider::~Collider()
{

}

int Collider::Collide(GameObject* go, std::vector<GameObject*> allObjects, int windowSizeX, int windowSizeY, bool collideWithWindowBorders) {

	// Collide with window borders
	if (collideWithWindowBorders) {
		// x axis
		if (go->_posX /*- go->_size/2*/ <= 0) {
			go->multiplyDirection(-1, 1);
		}
		else if (go->_posX + go->_size >= windowSizeX) {
			go->multiplyDirection(-1, 1);
		}
		// y axis
		if (go->_posY /*- go->_size/2*/ <= 0) {
			go->multiplyDirection(1, -1);
		}
		else if (go->_posY + go->_size >= windowSizeY) {
			go->multiplyDirection(1, -1);
		}
	}
	return false;


	//for (int i = 0; i < allObjects.size(); i++)
	//{
	//	GameObject* otherObject;
	//	if (allObjects[i] != go) { // dont collide with yourself
	//		// check hitboxes
	//		otherObject = allObjects[i];

	//		float d1x = (otherObject->_posX - otherObject->_size) - (go->_posX + go->_size);
	//		float d1y = (otherObject->_posY - otherObject->_size) - (go->_posY + go->_size);
	//		float d2x = (go->_posX - go->_size) - (otherObject->_posX + otherObject->_size);
	//		float d2y = (go->_posY - go->_size) - (otherObject->_posY + otherObject->_size);

	//		if (d1x > 0.0f || d1y > 0.0f) {
	//			auto it = std::find(go->_collidedWith.begin(), go->_collidedWith.end(), otherObject);
	//			if (it != go->_collidedWith.end())
	//			{
	//				go->onCollisionExit(otherObject);
	//				go->_collidedWith.erase(it);
	//			}
	//			return 0;
	//		}

	//		if (d2x > 0.0f || d2y > 0.0f) {
	//			auto it = std::find(go->_collidedWith.begin(), go->_collidedWith.end(), otherObject);
	//			if (it != go->_collidedWith.end())
	//			{
	//				go->onCollisionExit(otherObject);
	//				go->_collidedWith.erase(it);
	//			}
	//			return 0;
	//		}

	//		//COLISION

	//		auto it = std::find(go->_collidedWith.begin(), go->_collidedWith.end(), otherObject);
	//		if (it != go->_collidedWith.end())
	//		{
	//			go->onCollisionStay(otherObject);
	//			//return 0;
	//		}
	//		else {
	//			//if not already collided with that object
	//			go->_collidedWith.push_back(otherObject);

	//			// Collide with window borders
	//			if (collideWithWindowBorders) {
	//				// x axis
	//				if (go->_posX /*- go->_size/2*/ <= 0) {
	//					go->multiplyDirection(-1, 1);
	//				}
	//				else if (go->_posX /*+ go->_size/2*/ >= windowSizeX) {
	//					go->multiplyDirection(-1, 1);
	//				}
	//				// y axis
	//				if (go->_posY /*- go->_size/2*/ <= 0) {
	//					go->multiplyDirection(1, -1);
	//				}
	//				else if (go->_posY /*+ go->_size/2*/ >= windowSizeY) {
	//					go->multiplyDirection(1, -1);
	//				}
	//			}
	//			return go->onCollisionEnter(otherObject);
	//		}
	//	}
	//}
};