#pragma once
#include "MyCube.h"

MyCube::MyCube(float size)
{
	

	auto amesh = new Mesh();
	std::vector<std::vector<GLfloat>> v = {
		{0.500000f * size, -0.500000f * size, 0.500000f * size},
		{-0.500000f * size, -0.500000f * size, 0.500000f * size},
		{-0.500000f * size, 0.500000f * size, 0.500000f * size},
		{0.500000f * size, 0.500000f * size, 0.500000f * size},
		{0.500000f * size, -0.500000f * size, -0.500000f * size},
		{-0.500000f * size, -0.500000f * size, -0.500000f * size},
		{-0.500000f * size, 0.500000f * size, -0.500000f * size},
		{0.500000f * size, 0.500000f * size, -0.500000f * size}
	};
	// Face Normal
	std::vector<std::vector<GLfloat>> n = {

		{0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, -1.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, -1.0f, 0.0f},
		{1.0f, 0.0f, 0.0f},
		{-1.0f, 0.0f, 0.0f}
	};

	// Face Element index
	std::vector<std::vector<std::vector<GLint>>> faces = {
		{{0,0,0},{1,0,0},{2,0,0},{3,0,0}},
		{{7,0,0},{6,0,0},{5,0,0},{4,0,0}},
		{{3,0,0},{2,0,0},{6,0,0},{7,0,0}},
		{{1,0,0},{0,0,0},{4,0,0},{5,0,0}},
		{{0,0,0},{4,0,0},{7,0,0},{3,0,0}},
		{{2,0,0},{6,0,0},{5,0,0},{1,0,0}}
	};

	amesh->setFace(faces);
	
	amesh->setVertex(v);

	amesh->setFaceNormal();

	mesh.reset(amesh);

	renderer.reset(new MeshRenderer(mesh.get()));
}
