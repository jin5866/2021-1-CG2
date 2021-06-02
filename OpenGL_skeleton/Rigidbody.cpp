#include "Rigidbody.h"
#include "MyMath.h"

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
	if (otoi * (v - v2) > 0) {
		auto& a2 = other->getOrigtA();
		auto m2 = other->getMass();
		
		float e2 = other->getE();

		auto newv = (v2 * (e + 1) * m2 + v * (mass - e * m2)) / (m2 + mass);
		v = newv;
	}

}

void Rigidbody::onCollisionEnd(Rigidbody* other)
{
	origv = v;
	origa = a;
}

void Rigidbody::onCollision(const std::vector<float>& wall)
{
	if (v * wall >= 0) {
		auto vlen = abs(v);
		auto wallv = wall * (vlen / abs(wall));
		auto newv = (v + wallv) * 2 - v;
		v = newv;
	}

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
