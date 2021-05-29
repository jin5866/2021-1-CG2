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
	friend std::unique_ptr<TextureManager> std::make_unique<TextureManager>();
	friend std::unique_ptr<TextureManager>::deleter_type;
public:
	static TextureManager* getInstance();
	//GLuint LoadMeshFromFile(const char* texFile);
	GLuint LoadMeshFromFile(const std::string& texFile);
	~TextureManager() = default;
	TextureManager(const TextureManager&) = default;
	TextureManager(TextureManager&&) = default;
	TextureManager& operator=(const TextureManager&) = default;
	TextureManager& operator=(TextureManager&&) = default;
private:
	TextureManager() = default;

	static std::unique_ptr<TextureManager> instance;
	std::map<std::string, GLuint> textures;
};

std::unique_ptr<TextureManager> TextureManager::instance = nullptr;

