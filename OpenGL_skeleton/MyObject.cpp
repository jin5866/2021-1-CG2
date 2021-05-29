#include "MyObject.h"
#include"TextureManager.h"
void MyObject::setTexture(std::string file)
{
	texture = TextureManager::getInstance()->LoadMeshFromFile(file);
	printf("%d\n", texture);
}
void MyObject::Draw()
{
	if (renderer) { renderer->Draw(); }
}
