#include "Mesh.h"


void Mesh::setFaceNormal()
{
	if (v.size() == 0) return;

	n.clear();
	for (auto& face : faces) {
		std::vector<GLfloat> result;
		if (face.size() >= 3) {
			std::vector<GLfloat>& v0 = v[face[0][0]];
			std::vector<GLfloat>& v1 = v[face[1][0]];
			std::vector<GLfloat>& v2 = v[face[2][0]];

			std::vector<GLfloat> s0 = v1 - v0;
			std::vector<GLfloat> s1 = v2 - v0;
			std::vector<GLfloat> cs = cross(s1, s0);
			result = normalize(cs);

		}
		n.push_back(result);

	}

	return;
}

Mesh::Mesh(const char* texFile)
{
}
