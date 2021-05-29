#pragma once
#include "MyMath.h"

std::vector<float> cross(std::vector<float>& a, std::vector<float>& b) {
	return { a[1] * b[2] - b[1] * a[2],a[2] * b[0] - b[2] * a[0],a[0] * b[1] - b[0] * a[1] };
}

std::vector<float> operator- (std::vector<float>& a, std::vector<float>& b) {
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}

std::vector<float> operator+ (std::vector<float>& a, std::vector<float>& b) {
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}

std::vector<float> operator* (std::vector<float>& a, float& b) {
	return { a[0] * b,a[1] * b ,a[2] * b };
}

std::vector<float> operator/ (std::vector<float>& a, float& ad) {
	return { a[0] / ad,a[1] / ad ,a[2] / ad };
}

float abs(std::vector<float>& a) {
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] + a[2]);
}

std::vector<float> normalize(std::vector<float>& a) {
	float ad = abs(a);
	return { a[0] / ad,a[1] / ad ,a[2] / ad };;
}