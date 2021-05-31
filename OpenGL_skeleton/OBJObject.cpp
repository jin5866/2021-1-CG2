#include "OBJObject.h"
#include "Renderers.h"

OBJObject::OBJObject(std::string meshFile, std::string textureFile)
{
	auto amesh = new Mesh(meshFile);
	mesh.reset(amesh);

	setTexture(textureFile);

	renderer.reset(new MeshRenderer(this));

	rigidbody.reset(new Rigidbody(&transform));
}

OBJObject::OBJObject()
{
}
