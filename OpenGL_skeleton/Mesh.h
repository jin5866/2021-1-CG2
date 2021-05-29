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
	void setVertexNormal(std::vector<std::vector<GLfloat>>& newvn) { vn = newvn; }
	void setVertexNormal(std::vector<std::vector<GLfloat>>&& newvn) { vn = move(newvn); }
	void setVertexTexture(std::vector<std::vector<GLfloat>>& newvt) { vt = newvt; }
	void setVertexTexture(std::vector<std::vector<GLfloat>>&& newvt) { vt = move(newvt); }
	void setFace(std::vector<std::vector<std::vector<GLint>>>& newfaces) { faces = newfaces; }
	void setFace(std::vector<std::vector<std::vector<GLint>>>&& newfaces) { faces = move(newfaces); }

	void setFaceNormal();

	std::vector<std::vector<GLfloat>>& getVertex() { return v; }
	std::vector<std::vector<GLfloat>>& getFaceNormal() { return n; }
	std::vector<std::vector<GLfloat>>& getVertexNormal() { return vn; }
	std::vector<std::vector<GLfloat>>& getVertexTexture() { return vt; }
	std::vector<std::vector<std::vector<GLint>>>& getFaces() { return faces; }


	Mesh(const char* texFile);
	Mesh() = default;
	Mesh(const Mesh&) = default;
	Mesh(Mesh&&) = default;
	Mesh& operator=(const Mesh&) = default;
	Mesh& operator=(Mesh&&) = default;

private:
	std::vector<std::vector<GLfloat>> v;
	std::vector<std::vector<GLfloat>> n; //normal
	std::vector<std::vector<GLfloat>> vn; // vertex normal
	std::vector<std::vector<GLfloat>> vt; //vertex texture
	std::vector<std::vector<std::vector<GLint>>> faces; // v vt vn
};

