#include "MeshRenderer.h"

void MeshRenderer::Draw()
{
	Mesh* mesh = object->getMesh();
	if (!mesh) return;

	auto& faces = mesh->getFaces();
	auto& n = mesh->getFaceNormal();
	auto& v = mesh->getVertex();
	auto& vt = mesh->getVertexTexture();
	auto& vn = mesh->getVertexNormal();
	bool isvt = vt.size() > 0;
	bool isvn = vn.size() > 0;

	glBindTexture(GL_TEXTURE_2D, object->getTexture());
	glEnable(GL_TEXTURE_2D);
	glScalef(10, 10, 10);
	for (int i = 0; i < faces.size(); i++) {
		auto& face = faces[i];
		

		switch (face.size())
		{
		case 3:
			glBegin(GL_TRIANGLES);
			//printf("triangle\n");
			break;
		case 4:
			glBegin(GL_QUADS);
			//printf("GL_QUADS\n");
			break;
		case 2:
			glBegin(GL_LINE);
			//printf("GL_LINE\n");
			break;
		default:
			glBegin(GL_POLYGON);
			//printf("POLYGON\n");
			break;
		}
		if (n.size() >= faces.size()) {
			//glNormal3fv(&n[i][0]);
		}
		for (auto& vertexofface : face) {
			/*for (auto v : vn[vertexofface[2]]) {
				printf("%f ", v);

			}
			printf("\n");*/
			if (isvn) {
				glNormal3f(vn[vertexofface[2]][0], vn[vertexofface[2]][1], vn[vertexofface[2]][2]);
				//glVertex3fv();
			}
			if (isvt) {
				glTexCoord2f(vt[vertexofface[1]][0],1- vt[vertexofface[1]][1]);
			}

			glVertex3f(v[vertexofface[0]][0], v[vertexofface[0]][1], v[vertexofface[0]][2]);
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
