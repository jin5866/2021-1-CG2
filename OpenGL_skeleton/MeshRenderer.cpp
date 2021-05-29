#include "MeshRenderer.h"

void MeshRenderer::Draw()
{
	if (!mesh) return;

	auto& faces = mesh->getFaces();
	auto& n = mesh->getFaceNormal();
	auto& v = mesh->getVertex();

	for (int i = 0; i < faces.size(); i++) {
		auto& face = faces[i];

		switch (face.size())
		{
		case 3:
			glBegin(GL_TRIANGLES);
			break;
		case 4:
			glBegin(GL_QUADS);
			break;
		case 2:
			glBegin(GL_LINE);
			break;
		default:
			glBegin(GL_POLYGON);
			break;
		}
		if (n.size() >= faces.size()) {
			glNormal3fv(&n[i][0]);
		}
		for (auto& vofface : face) {
			glVertex3fv(&v[vofface[0]][0]);
		}
		glEnd();
	}

	//for (int i = 0; i < 6; i++) {
	//	// One Cube has 6 quads
	//	glBegin(GL_QUADS);
	//	glNormal3fv(&n[i][0]); //face normal
	//	glTexCoord2f(1.0f, 1.0f); //uv coordinate
	//	glVertex3fv(&v[faces[i][0]][0]);
	//	glTexCoord2f(0.0f, 1.0f);
	//	glVertex3fv(&v[faces[i][1]][0]);
	//	glTexCoord2f(0.0f, 0.0f);
	//	glVertex3fv(&v[faces[i][2]][0]);
	//	glTexCoord2f(1.0f, 0.0f);
	//	glVertex3fv(&v[faces[i][3]][0]);
	//	glEnd();
	//}
}
