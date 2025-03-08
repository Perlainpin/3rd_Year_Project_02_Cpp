#pragma once

enum Shape {
	ball,
	square
};

class GameObject {
public:
	GameObject();
	GameObject(Shape shape);
	GameObject(int size);
	GameObject(Shape shape, int size);
	~GameObject();

	void Update(std::vector<GameObject*> AllObjects, float deltaTime);
	void Move(float deltaTime);

	std::vector<GameObject*> _collidedWith;
	
	int onCollisionEnter(GameObject* go);
	int onCollisionStay(GameObject* go) { return 0; }
	int onCollisionExit(GameObject* go) { return 0; }
	//static std::vector<GameObject*> GetAll();

	void multiplyDirection(float x, float y);
	void setDirection(float x, float y);



	float _posX;
	float _posY;
	float _directionX;
	float _directionY;
	float _speed;

	float _size;

	float _gravity = 9.81f;
	float _bounciness = 1;
	Shape _shape;
	// sprite
	// hitbox
};