#pragma once
#include"MyStruct.h"
#include"Collider.h"
#include"Renderer.h"
#include<memory>
class MyObject
{
	
public:
	Transform transform;
	
	Collider* getCollider() {
		return collider.get();
	}
	Renderer* getRenderer() {
		return renderer.get();
	}

	virtual void Draw();

	MyObject() = default;
	MyObject(const MyObject&) = default;
	MyObject(MyObject&&) = default;
	MyObject& operator=(const MyObject&) = default;
	MyObject& operator=(MyObject&&) = default;

protected:
	std::unique_ptr<Collider> collider;
	std::unique_ptr<Renderer> renderer;
private:

};

