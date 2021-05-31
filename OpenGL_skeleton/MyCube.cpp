#include "MyCube.h"
#include "Renderers.h"

MyCube::MyCube(float size)
{
	

	auto amesh = new Mesh("Contents/OBJ/2-3.obj");
	//std::vector<std::vector<GLfloat>> v = {
	//	{0.500000f * size, -0.500000f * size, 0.500000f * size},
	//	{-0.500000f * size, -0.500000f * size, 0.500000f * size},
	//	{-0.500000f * size, 0.500000f * size, 0.500000f * size},
	//	{0.500000f * size, 0.500000f * size, 0.500000f * size},
	//	{0.500000f * size, -0.500000f * size, -0.500000f * size},
	//	{-0.500000f * size, -0.500000f * size, -0.500000f * size},
	//	{-0.500000f * size, 0.500000f * size, -0.500000f * size},
	//	{0.500000f * size, 0.500000f * size, -0.500000f * size}
	//};
	//// Face Normal
	//std::vector<std::vector<GLfloat>> n = {

	//	{0.0f, 0.0f, 1.0f},
	//	{0.0f, 0.0f, -1.0f},
	//	{0.0f, 1.0f, 0.0f},
	//	{0.0f, -1.0f, 0.0f},
	//	{1.0f, 0.0f, 0.0f},
	//	{-1.0f, 0.0f, 0.0f}
	//};

	//// Face Element index
	//std::vector<std::vector<std::vector<GLint>>> faces = {
	//	{{0,0,0},{1,1,0},{2,2,0},{3,3,0}},
	//	{{7,0,0},{6,1,0},{5,2,0},{4,3,0}},
	//	{{3,0,0},{2,1,0},{6,2,0},{7,3,0}},
	//	{{1,0,0},{0,1,0},{4,2,0},{5,3,0}},
	//	{{0,0,0},{4,1,0},{7,2,0},{3,3,0}},
	//	{{2,0,0},{6,1,0},{5,2,0},{1,3,0}}
	//};

	//std::vector<std::vector<GLfloat>> vt = {
	//	{0,0,0},
	//	{0,1,0},
	//	{1,1,0},
	//	{1,0,0}
	//};

	//amesh->setFace(faces);
	//
	//amesh->setVertex(v);

	//amesh->setFaceNormal();

	//amesh->setVertexTexture(vt);

	mesh.reset(amesh);

	setTexture("Contents/OBJ/2-3.png");

	renderer.reset(new MeshRenderer(this));

	rigidbody.reset(new Rigidbody(&transform));

}
