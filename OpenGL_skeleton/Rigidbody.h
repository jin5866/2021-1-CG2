#pragma once
#include<vector>
#include"MyStruct.h"


class Rigidbody
{
public:
	virtual void preTick(float);
	virtual void tick(float);

	Rigidbody(Transform* transform) : transform(transform) {};
	Rigidbody() = default;
	Rigidbody(const Rigidbody&) = default;
	Rigidbody(Rigidbody&&) = default;
	Rigidbody& operator=(const Rigidbody&) = default;
	Rigidbody& operator=(Rigidbody&&) = default;

	void setUseGravity(bool newb);

	void onCollision(Rigidbody* other); // collision with other sphere
	void onCollisionEnd(Rigidbody* other); // collision with other sphere
	void onCollision(const std::vector<float>& wall); // collision with wall

	void setV(std::vector<float> v);
	void setA(std::vector<float> a);
	void setMass(float m);
	void setE(float e);

	void setRandom(float max = 15);

	float getMass() { return mass; }
	float getE() { return e; }
	const std::vector<float>& getV() { return v; }
	const std::vector<float>& getOrigV() { return origv; }
	const std::vector<float>& getA() { return a; }
	const std::vector<float>& getOrigtA() { return origa; }
	const Transform* getTransform() { return transform; }

private:
	std::vector<float> getRealA();

	std::vector<float> v = {0,0,0};
	std::vector<float> a = {0,0,0};
	float mass = 1;
	float e = 1;//COR
	bool usegravity = false	;

	std::vector<float> origv = { 0,0,0 };
	std::vector<float> origa = { 0,0,0 };

	Transform* transform;

	std::vector<float> newpos = { 0,0,0 };

	const std::vector<float> gravityacc = { 0,-9.8,0 };
};



