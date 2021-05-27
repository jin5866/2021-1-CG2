#pragma once
#include "Renderer.h"
class CubeRenderer :
    public Renderer
{
public:
    virtual void Draw();

	CubeRenderer() : CubeRenderer(1.0f) {};
	CubeRenderer(const CubeRenderer&) = default;
	CubeRenderer(CubeRenderer&&) = default;
	CubeRenderer& operator=(const CubeRenderer&) = default;
	CubeRenderer& operator=(CubeRenderer&&) = default;

	CubeRenderer(float);

private:
	float size;
};

