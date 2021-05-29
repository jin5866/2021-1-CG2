#pragma once
#include "MyObject.h"

void MyObject::setTexture(std::string texFile)
{
	//texture = TextureManager::getInstance()->LoadMeshFromFile(texFile);
}

void MyObject::Draw()
{
	if (renderer) { renderer->Draw(); }
}
