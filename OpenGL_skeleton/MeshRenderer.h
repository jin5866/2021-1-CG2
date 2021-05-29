#pragma once
#include "Renderer.h"
#include"Mesh.h"
#include<glut.h>
#include "MyObject.h"
class MeshRenderer :
    public Renderer
{
public:

	virtual void Draw();
	MeshRenderer(MyObject* object) : object(object) {}
	//MeshRenderer(Mesh* mesh) : mesh(mesh) {}
	MeshRenderer() = default;
	MeshRenderer(const MeshRenderer&) = default;
	MeshRenderer(MeshRenderer&&) = default;
	MeshRenderer& operator=(const MeshRenderer&) = default;
	MeshRenderer& operator=(MeshRenderer&&) = default;

private:
	//Mesh* mesh;
	MyObject* object;
};

