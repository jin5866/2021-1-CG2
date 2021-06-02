#pragma once
#include "Collider.h"
#include "MyStruct.h"
#include"MyObject.h"
#include<vector>
class SphereCollider :
    public Collider
{
public:
	SphereCollider(MyObject* object, float size = 0) : object(object), size(size) { transform = object->getTransform(); }
	//SphereCollider(Transform* transform,float size = 1) :transform(transform),size(size) {};
	SphereCollider() = default;
	SphereCollider(const SphereCollider&) = default;
	SphereCollider(SphereCollider&&) = default;
	SphereCollider& operator=(const SphereCollider&) = default;
	SphereCollider& operator=(SphereCollider&&) = default;

	MyObject* getObject() { return object; }

	virtual void onCollision(SphereCollider* other);
	void onCollision(const std::vector<float>& wall);

	virtual void draw();


	virtual float getSize();
	virtual std::vector<float> getpos();

private:
	MyObject* object;
	Transform* transform;
	float size;
	
};

