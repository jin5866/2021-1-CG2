#pragma once
#include "TextureManager.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif // !STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include<glut.h>
TextureManager* TextureManager::getInstance()
{
	if (!instance) {
		instance.reset(new TextureManager());
	}
	return instance.get();
}

void TextureManager::distroy()
{
	delete instance.release();
}

GLuint TextureManager::LoadMeshFromFile(const std::string& texFile)
{
	//printf("%s\n", texFile.c_str());
	auto tex = textures.find(texFile);
	if (tex != textures.end()) {
		return tex->second;
	}

	GLuint texture;
	glGenTextures(1, &texture);
	FILE* fp = NULL;
	if (fopen_s(&fp, texFile.c_str() , "rb")) {
		printf("ERROR : No %s. \n fail to bind %d\n", texFile.c_str(), texture);
		return false;
	}
	int width, height, channel;
	unsigned char* image = stbi_load_from_file(fp, &width, &height, &channel, 4);
	fclose(fp);

	//bind
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(image);

	textures.insert({ texFile,texture });

	return texture;
    
}

std::unique_ptr<TextureManager> TextureManager::instance = nullptr;