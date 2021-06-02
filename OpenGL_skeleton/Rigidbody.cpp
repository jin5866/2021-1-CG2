#include "Rigidbody.h"
#include "MyMath.h"
#include<random>
void Rigidbody::tick(float deltaTime)
{

}

void Rigidbody::preTick(float deltaTime)
{
	auto ra = getRealA();
	v = v +ra * deltaTime;
	auto newpos = transform->position + v * deltaTime;

	transform->position[0] = newpos[0];
	transform->position[1] = newpos[1];
	transform->position[2] = newpos[2];

	origv = v;
	origa = a;
}


void Rigidbody::setUseGravity(bool newb)
{
	usegravity = newb;
}

void Rigidbody::onCollision(Rigidbody* other)
{
	std::vector<float> otoi = {other->getTransform()->position[0] - transform->position[0], other->getTransform()->position[1] - transform->position[1], other->getTransform()->position[2] - transform->position[2]};
	auto& v2 = other->getOrigV();
	if (otoi * (v - v2) <= 0) {
		auto& a2 = other->getOrigtA();
		auto m2 = other->getMass();
		
		float e2 = other->getE();

		auto newv = (v2 * (e + 1) * m2 + v * (mass - e * m2)) / (m2 + mass);
		v = newv;

		//float otoilen = abs(otoi);
		
	}

}

void Rigidbody::onCollisionEnd(Rigidbody* other)
{
	origv = v;
	origa = a;
}

void Rigidbody::onCollision(const std::vector<float>& wall)
{
	if (v * wall <= 0) {
		auto vlen = abs(v);
		auto wallv = wall * (vlen / abs(wall));
		auto newv = (v + wallv) * 2 - v;
		v = newv * e;
	}

}

void Rigidbody::setV(std::vector<float> v)
{
	this->v = v;
}

void Rigidbody::setA(std::vector<float> a)
{
	this->a = a;
}

void Rigidbody::setMass(float m)
{
	mass = m;
}

void Rigidbody::setE(float e)
{
	this->e = e;
}

void Rigidbody::setRandom(float max)
{
	v[0] = static_cast<float>(rand()) / RAND_MAX * (max * 2) - max;
	v[1] = static_cast<float>(rand()) / RAND_MAX * (max * 2) - max;
	v[2] = static_cast<float>(rand()) / RAND_MAX * (max * 2) - max;
	mass = static_cast<float>(rand()) / RAND_MAX * (max - 1) + 1;
	e = static_cast<float>(rand()) / RAND_MAX * 0.5 + 0.5;

}


std::vector<float> Rigidbody::getRealA()
{
	if (usegravity) {
		return a + gravityacc;
	}
	else {
		return a;
	}
}
