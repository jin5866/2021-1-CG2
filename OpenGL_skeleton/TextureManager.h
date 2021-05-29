#pragma once
#include<memory>
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif // !STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include<map>
#include<string>
#include <glut.h>
class TextureManager
{
public:
	static TextureManager* getInstance();
	//GLuint LoadMeshFromFile(const char* texFile);
	GLuint LoadMeshFromFile(const std::string texFile);

private:
	std::unique_ptr<TextureManager> instance;
	std::map<std::string, GLuint> textures;
};

