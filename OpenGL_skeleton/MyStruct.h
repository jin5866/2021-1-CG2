#pragma once
#include<vector>

class MyStruct
{


};

struct Transform {
	float position[3] = {0,0,0};
	float rotation[3] = {0,0,0,};
	float scale[3] = {1,1,1};

	void setPosition(const std::vector<float>& p) {
		position[0] = p[0];
		position[1] = p[1];
		position[2] = p[2];
	}
	void setPosition(std::vector<float>&& p) {
		position[0] = p[0];
		position[1] = p[1];
		position[2] = p[2];
	}

};

