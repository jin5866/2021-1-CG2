#include "OBJObject.h"
#include "Renderers.h"

#include "SphereCollider.h"
//#include "CollisionDetector.h"
OBJObject::OBJObject(std::string meshFile, std::string textureFile, float collidersize, bool xrotated )
{
	auto amesh = new Mesh(meshFile, xrotated);
	mesh.reset(amesh);

	setTexture(textureFile);

	renderer.reset(new MeshRenderer(this));

	rigidbody.reset(new Rigidbody(&transform));

	collider.reset(new SphereCollider(this, collidersize));
}

OBJObject::OBJObject()
{
}
