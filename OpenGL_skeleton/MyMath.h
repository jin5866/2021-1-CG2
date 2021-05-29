#pragma once
#include<vector>
#include<glut.h>

std::vector<float> cross(std::vector<float>& a, std::vector<float>& b);
std::vector<float> operator- (std::vector<float>& a, std::vector<float>& b);
std::vector<float> operator+ (std::vector<float>& a, std::vector<float>& b);
std::vector<float> operator* (std::vector<float>& a, float& b);
std::vector<float> operator/ (std::vector<float>& a, float& ad);
float abs(std::vector<float>& a);
std::vector<float> normalize(std::vector<float>& a);



class MyMath
{
};

