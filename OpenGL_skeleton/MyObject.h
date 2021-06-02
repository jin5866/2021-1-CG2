#pragma once
#include"MyStruct.h"
#include"Collider.h"
#include"Renderer.h"
#include"Mesh.h"
#include"Rigidbody.h"
#include<memory>
#include<string>

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
	Mesh* getMesh() {
		return mesh.get();
	}
	GLuint getTexture() {
		return texture;
	}
	Rigidbody* getRigidbody() {
		return rigidbody.get();
	}

	Transform* getTransform() {
		return &transform;
	}

	virtual void setSize(std::vector<GLfloat>& size);
	virtual void setSize(std::vector<GLfloat> size);

	virtual void setTexture(std::string);

	virtual void Draw();

	virtual void preTick(float);
	virtual void tick(float);

	virtual void onCollision(MyObject* other);
	void onCollision(const std::vector<float>& wall);

	MyObject() = default;
	MyObject(const MyObject&) = default;
	MyObject(MyObject&&) = default;
	MyObject& operator=(const MyObject&) = default;
	MyObject& operator=(MyObject&&) = default;

protected:
	std::unique_ptr<Collider> collider;
	std::unique_ptr<Renderer> renderer;
	std::unique_ptr<Mesh> mesh;
	std::unique_ptr<Rigidbody> rigidbody;
	GLuint texture = 0;
	//std::vector<GLfloat> size = { 1.0,1.0,1.0 };
private:

};

