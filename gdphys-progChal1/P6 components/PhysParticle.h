#pragma once
#include <SFML/System.hpp>
#include"PhysVector.h"

using namespace std;
class PhysParticle
{
public:
	string name;
	float mass;
	sf::Clock timer;
	PhysVector position = PhysVector(0,0);
	PhysVector velocity = PhysVector(0, 0);
	PhysVector acceleration = PhysVector(0, 0);
	PhysVector totalVelocity = PhysVector(0, 0);
	bool isFinished = false;
public:
	void update(float time);
	float measureTime();
	bool getIsDestroyed();
	void setIsDestroyed();
	
	//PhysVector getRenderPoint();
	
private:
	void updatePos(float time);
	void updateVelocity(float time);

private:
	bool isDestroyed = false;
	
};

