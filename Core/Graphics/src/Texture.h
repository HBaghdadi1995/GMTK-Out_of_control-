#pragma once

#include <string>
#include <assert.h>
#include <iostream>

#include <stb_image.h>
#include <glad/glad.h>

#ifdef DIST

#define TEXTURE_SRC "./Src/Textures/"

#else //DIST

#define TEXTURE_SRC "../../Src/Textures/"

#endif //DIST

class Texture
{
private:
	int m_Width;
	int m_Height;
	int m_Channels;
	unsigned char* m_CpuBuffer = nullptr;
	GLuint m_GpuBuffer;
	int m_Slot;

public:
	Texture();
	~Texture();

	void Bind();
	void Unbind();

	inline int getSlot() const { return m_Slot; }

private:
	static GLint getOpenGLSlot(int slot);
};