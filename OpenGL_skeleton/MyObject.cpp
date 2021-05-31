#include "MyObject.h"
#include"TextureManager.h"
void MyObject::setTexture(std::string file)
{
	texture = TextureManager::getInstance()->LoadMeshFromFile(file);
	//printf("%d\n", texture);
}
void MyObject::Draw()
{
	if (renderer) { 
		glPushMatrix();
		glScalef(size[0], size[1], size[2]);
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
