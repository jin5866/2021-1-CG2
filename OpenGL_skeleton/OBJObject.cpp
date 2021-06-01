#include "OBJObject.h"
#include "Renderers.h"

OBJObject::OBJObject(std::string meshFile, std::string textureFile, bool yreverse)
{
	auto amesh = new Mesh(meshFile,yreverse);
	mesh.reset(amesh);

	setTexture(textureFile);

	renderer.reset(new MeshRenderer(this));

	rigidbody.reset(new Rigidbody(&transform));
}

OBJObject::OBJObject()
{
}
