#pragma once
#include "MeshRenderer.h"

void MeshRenderer::Draw()
{
	if (!mesh) return;

	auto& faces = mesh->getFaces();
	auto& n = mesh->getFaceNormal();
	auto& v = mesh->getVertex();
	auto& vt = mesh->getVertexTexture();
	auto& vn = mesh->getVertexNormal();
	bool isvt = vt.size() > 0;
	bool isvn = vn.size() > 0;

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
		for (auto& vertexofface : face) {
			glVertex3fv(&v[vertexofface[0]][0]);
			if (isvt) {
				glTexCoord2f(vt[vertexofface[1]][0], vt[vertexofface[1]][1]);
			}
			if (isvn) {
				glVertex3fv(&vn[vertexofface[2]][0]);
			}
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
