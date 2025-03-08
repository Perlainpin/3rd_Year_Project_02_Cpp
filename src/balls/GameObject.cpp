#include "pch.h"
#include "GameObject.h"
#include "Math.h"
#include "Collider.h"

GameObject::GameObject()
{
	_posX = 0;
	_posY = 0;
	_shape = Shape::ball;
	_size = 100;
	_directionX = 0;
	_directionY = 0;
	_speed = 0;
}

GameObject::GameObject(int size)
{
	_posX = 0;
	_posY = 0;
	_shape = Shape::ball;
	_size = size;
	_directionX = 0;
	_directionY = 0;
	_speed = 0;
}

GameObject::GameObject(Shape shape)
{
	_posX = 0;
	_posY = 0;
	_shape = shape;
	_size = 10;
	_directionX = 0;
	_directionY = 0;
	_speed = 0;
}

GameObject::GameObject(Shape shape, int size)
{
	_posX = 0;
	_posY = 0;
	_shape = shape;
	_size = size;
	_directionX = 0;
	_directionY = 0;
	_speed = 0;
}

void GameObject::Update(std::vector<GameObject*> AllObjects, float deltaTime) {
	// check collisions
	deltaTime /= 1000; // convert to seconds
	Move(deltaTime);
	Collider::Collide(this, AllObjects, 800,800, true);
}

void GameObject::multiplyDirection(float x, float y)
{
	// bounce multiplier
	_speed *= _bounciness;
	setDirection(_directionX * x, _directionY * y);
}
void GameObject::setDirection(float x, float y)
{
	Math::normalize(&x, &y);
	_directionX = x;
	_directionY = y;
}

void GameObject::Move(float deltaTime) {
	
	_posX += (_directionX * deltaTime * _speed);
	_posY += (_directionY * deltaTime * _speed);

	// gravity
	// Seems to work, except its not bouncing back up so I'm leaving this as a comment
	//_directionY += _gravity * deltaTime / 100;
}

int GameObject::onCollisionEnter(GameObject* go) {
	float difXright = ((this->_posX - this->_size) - (go->_posX + go->_size));
	float difXleft = ((this->_posX + this->_size) - (go->_posX - go->_size));
	float difX = std::min(abs(difXleft), abs(difXright));

	float difYbottom = ((this->_posY - this->_size) - (go->_posY + go->_size));
	float difYtop = ((this->_posY + this->_size) - (go->_posY - go->_size));
	float difY = std::min(abs(difYtop), abs(difYbottom));

	if (difX < difY) {
		//vertical collision
		multiplyDirection(-1, 1);
		return 2;
	}
	else {
		//horizontal collision
		multiplyDirection(1, -1);
		return 3;
	}
}

GameObject::~GameObject()
{
}
