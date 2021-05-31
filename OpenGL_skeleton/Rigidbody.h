#pragma once
#include<vector>
#include"MyStruct.h"


class Rigidbody
{
public:
	virtual void Tick(float);

	Rigidbody(Transform* transform) : transform(transform) {};
	Rigidbody() = default;
	Rigidbody(const Rigidbody&) = default;
	Rigidbody(Rigidbody&&) = default;
	Rigidbody& operator=(const Rigidbody&) = default;
	Rigidbody& operator=(Rigidbody&&) = default;
private:
	std::vector<float> getRealA();

	std::vector<float> v = {0,0,0};
	std::vector<float> a = {0,0,0};
	float mass = 1;
	bool usegravity = true	;

	Transform* transform;

	const std::vector<float> gravityacc = { 0,9.8f,0 };
};



