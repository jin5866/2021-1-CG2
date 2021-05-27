#include "MyCube.h"

MyCube::MyCube(float size)
{
	renderer.reset(new CubeRenderer(size));
}
