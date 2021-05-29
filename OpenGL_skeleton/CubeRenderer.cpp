#include "CubeRenderer.h"
void CubeRenderer::Draw()
{
	glutSolidCube(size);
}

CubeRenderer::CubeRenderer(float size) : size(size)
{}
