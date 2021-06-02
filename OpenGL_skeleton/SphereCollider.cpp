#include "SphereCollider.h"
#include"CollisionDetector.h"
#include<glut.h>
#include"MyMath.h"



void SphereCollider::onCollision(SphereCollider* other)
{
	std::vector<float> otoi = { other->getTransform()->position[0] - transform->position[0], other->getTransform()->position[1] - transform->position[1], other->getTransform()->position[2] - transform->position[2] };
	float size1 = getSize();
	float size2 = other->getSize();
	float re = size1 + size2 - abs(otoi);
	float myre = re / (size1 + size2) * size1;
	auto a = transform->position + otoi / (abs(otoi)) * (-myre);
	newpos[0] = a[0];
	newpos[1] = a[1];
	newpos[2] = a[2];
	object->onCollision(other->getObject());
}

void SphereCollider::onCollisionEnd(SphereCollider* other)
{
	transform->position[0] = newpos[0];
	transform->position[1] = newpos[1];
	transform->position[2] = newpos[2];
	object->onCollisionEnd(other->getObject());
}


void SphereCollider::onCollision(const std::vector<float>& wall)
{
	object->onCollision(wall);
}

void SphereCollider::draw()
{
	if (isDraw) {
		glPushMatrix();
		glutWireSphere(size, 10, 10);
		glPopMatrix();
	}
}

float SphereCollider::getSize()
{
	return std::max(std::max(transform->scale[0], transform->scale[1]), transform->scale[2]) * size;
}

std::vector<float> SphereCollider::getpos()
{
	return std::vector<float>({ transform->position[0], transform->position[1], transform->position[2] });
}

SphereCollider::SphereCollider(MyObject* object, float size) : object(object), size(size) { 
	CollisionDetector::getInstance()->addCollider(this);
	transform = object->getTransform();
}