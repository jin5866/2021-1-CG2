#pragma once
#include<vector>
#include<glut.h>

std::vector<GLfloat> cross(std::vector<GLfloat>& a, std::vector<GLfloat>& b) {
	return { a[1] * b[2] - b[1] * a[2],a[2] * b[0] - b[2] * a[0],a[0] * b[1] - b[0] * a[1] };
}

std::vector<GLfloat> operator- (std::vector<GLfloat>& a, std::vector<GLfloat>& b) {
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}

std::vector<GLfloat> operator+ (std::vector<GLfloat>& a, std::vector<GLfloat>& b) {
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}
class MyMath
{
};

