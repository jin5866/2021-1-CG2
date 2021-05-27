#include "MyObject.h"

void MyObject::Draw()
{
	if (renderer) { renderer->Draw(); }
}
