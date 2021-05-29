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
	std::vector<std::vector<GLint>> faces = {
		{0,1,2,3},
		{7,6,5,4},
		{3,2,6,7},
		{1,0,4,5},
		{0,4,7,3},
		{2,6,5,1}
	};
	amesh->setFace(faces);
	amesh->setFaceNormal(n);
	amesh->setVertex(v);

	mesh.reset(amesh);

	renderer.reset(new MeshRenderer(mesh.get()));
}
