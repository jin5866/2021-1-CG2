#include "Mesh.h"


void Mesh::setFaceNormal()
{
	if (v.size() == 0) return;

	n.clear();
	for (auto& face : faces) {
		std::vector<GLfloat> result;
		if (face.size() >= 3) {
			std::vector<GLfloat>& v0 = v[face[0]];
			std::vector<GLfloat>& v1 = v[face[1]];
			std::vector<GLfloat>& v2 = v[face[2]];


		}

		
	}
}
