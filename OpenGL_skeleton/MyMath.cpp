#include "MyMath.h"

std::vector<float> cross(const std::vector<float>& a, const std::vector<float>& b) {
	return { a[1] * b[2] - b[1] * a[2],a[2] * b[0] - b[2] * a[0],a[0] * b[1] - b[0] * a[1] };
}

std::vector<float> operator- (const std::vector<float>& a, const std::vector<float>& b) {
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}

std::vector<float> operator+ (const std::vector<float>& a, const std::vector<float>& b) {
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}

std::vector<float> operator+(const float* a, const std::vector<float>& b)
{
	return { a[0] - b[0],a[1] - b[1] ,a[2] - b[2] };
}

std::vector<float> operator* (const std::vector<float>& a, const float& b) {
	return { a[0] * b,a[1] * b ,a[2] * b };
}

std::vector<float> operator/ (const std::vector<float>& a, const float& ad) {
	return { a[0] / ad,a[1] / ad ,a[2] / ad };
}

float abs(const std::vector<float>& a) {
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] + a[2]);
}

std::vector<float> normalize(const std::vector<float>& a) {
	float ad = abs(a);
	return { a[0] / ad,a[1] / ad ,a[2] / ad };;
}