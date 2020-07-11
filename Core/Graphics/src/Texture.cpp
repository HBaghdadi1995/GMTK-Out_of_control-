#include "Texture.h"

Texture::Texture()
{
	std::string filename = std::string(TEXTURE_SRC) + std::string("Hello Smile.png");
	m_Buffer = stbi_load(filename.c_str(), &m_Width, &m_Height, &m_Channels, 0);

	if (!m_Buffer) {
		assert(false);
	}
}

Texture::~Texture()
{
}
