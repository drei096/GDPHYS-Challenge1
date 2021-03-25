#pragma once
#include<list>
#include"PhysParticle.h"

using namespace std;

class PhysicsWorld
{
public:
	list <PhysParticle*> particles;
public:
	void addParticle(PhysParticle* particle);
	void update(float time);
private:
	void updateParticleList();
};

