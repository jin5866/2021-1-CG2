#include "Rigidbody.h"
#include "MyMath.h"

void Rigidbody::Tick(float deltaTime)
{
	auto a = getRealA();
	v = v + a * deltaTime;
	auto newpos = transform->position + v * deltaTime;

	transform->position[0] = newpos[0];
	transform->position[1] = newpos[1];
	transform->position[2] = newpos[2];
}



void Rigidbody::setUseGravity(bool newb)
{
	usegravity = newb;
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
