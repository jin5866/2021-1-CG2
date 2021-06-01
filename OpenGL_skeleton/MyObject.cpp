#include "MyObject.h"
#include"TextureManager.h"
void MyObject::setSize(std::vector<GLfloat>& newsize)
{
	
	transform.scale[0] = newsize[0];
	transform.scale[1] = newsize[1];
	transform.scale[2] = newsize[2];
}

void MyObject::setSize(std::vector<GLfloat> newsize)
{
	transform.scale[0] = newsize[0];
	transform.scale[1] = newsize[1];
	transform.scale[2] = newsize[2];
}

void MyObject::setTexture(std::string file)
{
	texture = TextureManager::getInstance()->LoadMeshFromFile(file);
	//printf("%d\n", texture);
}
void MyObject::Draw()
{
	if (renderer) { 
		glPushMatrix();
		glTranslatef(transform.position[0], transform.position[1], transform.position[2]);
		glRotatef(transform.rotation[0], 1, 0, 0);
		glRotatef(transform.rotation[1], 0, 1, 0);
		glRotatef(transform.rotation[2], 0, 0, 1);
		glScalef(transform.scale[0], transform.scale[1], transform.scale[2]);
		renderer->Draw(); 
		glPopMatrix();
	}
	
}

void MyObject::Tick(float deltaTime)
{
	if (rigidbody) {
		rigidbody->Tick(deltaTime);
	}
}
