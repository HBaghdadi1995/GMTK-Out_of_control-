#pragma once

#include <string>
#include <stb_image.h>
#include <assert.h>

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
	unsigned char* m_Buffer = nullptr;

public:
	Texture();
	~Texture();

};