#include "PhysParticle.h"

void PhysParticle::update(float time)
{
	updatePos(time);
	updateVelocity(time);
}

void PhysParticle::updatePos(float time)
{
	position = position + (velocity * time) + ((acceleration*powf(time, 2)) * (1/2));
}

void PhysParticle::updateVelocity(float time)
{
	velocity = velocity + acceleration * time;
	totalVelocity = totalVelocity + velocity;
}

float PhysParticle::measureTime()
{
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	return elapsed.asSeconds() * 1000;
}

bool PhysParticle::getIsDestroyed()
{
	return isDestroyed;
}

void PhysParticle::setIsDestroyed()
{
	isDestroyed = true;
}




