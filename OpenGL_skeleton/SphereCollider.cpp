#include "SphereCollider.h"
#include<glut.h>


void SphereCollider::onCollision(SphereCollider* other)
{
	object->onCollision(other->getObject());
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
