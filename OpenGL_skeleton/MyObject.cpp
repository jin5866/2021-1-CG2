#include "MyObject.h"
#include"TextureManager.h"
void MyObject::Draw()
{
	if (renderer) { renderer->Draw(); }
}
