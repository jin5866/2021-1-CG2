#pragma once
#include<vector>
#include<glut.h>

std::vector<float> cross(const std::vector<float>& a, const std::vector<float>& b);
std::vector<float> operator- (const std::vector<float>& a, const std::vector<float>& b);
std::vector<float> operator+ (const std::vector<float>& a, const std::vector<float>& b);
std::vector<float> operator+ (const float* a, const std::vector<float>& b);
float operator* (const std::vector<float>& a, const std::vector<float>& b);
std::vector<float> operator* (const std::vector<float>& a, const float& b);
std::vector<float> operator/ (const std::vector<float>& a, const float& ad);
float abs(const std::vector<float>& a);
std::vector<float> normalize(const std::vector<float>& a);



class MyMath
{
};

