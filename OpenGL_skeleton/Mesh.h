#pragma once
#include<vector>
#include<glut.h>
#include"MyMath.h"
class Mesh
{
public:
	void setVertex(std::vector<std::vector<GLfloat>>& newv) { v = newv; }
	void setVertex(std::vector<std::vector<GLfloat>>&& newv) { v = move( newv) ; }
	void setFaceNormal(std::vector<std::vector<GLfloat>>& newn) { n = newn; }
	void setFaceNormal(std::vector<std::vector<GLfloat>>&& newn) { n = move(newn); }
	void setFace(std::vector<std::vector<GLint>>& newfaces) { faces = newfaces; }
	void setFace(std::vector<std::vector<GLint>>&& newfaces) { faces = move(newfaces); }

	void setFaceNormal();

	std::vector<std::vector<GLfloat>>& getVertex() { return v; }
	std::vector<std::vector<GLfloat>>& getFaceNormal() { return n; }
	std::vector<std::vector<GLint>>& getFaces() { return faces; }

private:
	std::vector<std::vector<GLfloat>> v;
	std::vector<std::vector<GLfloat>> n;
	std::vector<std::vector<GLint>> faces;
};

