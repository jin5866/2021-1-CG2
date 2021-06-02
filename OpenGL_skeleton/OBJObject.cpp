#include "OBJObject.h"
#include "Renderers.h"
#include "SphereCollider.h"
OBJObject::OBJObject(std::string meshFile, std::string textureFile, bool xrotated)
{
	auto amesh = new Mesh(meshFile, xrotated);
	mesh.reset(amesh);

	setTexture(textureFile);

	renderer.reset(new MeshRenderer(this));

	rigidbody.reset(new Rigidbody(&transform));

	collider.reset(new SphereCollider(this, 0.1));
}

OBJObject::OBJObject()
{
}
