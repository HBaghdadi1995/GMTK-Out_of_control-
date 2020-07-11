#include "Texture.h"

Texture::Texture(std::string texAddress):
	m_Slot(0)
{
	m_CpuBuffer = stbi_load(texAddress.c_str(), &m_Width, &m_Height, &m_Channels, 0);

	if (!m_CpuBuffer) {
		assert(false);
	}

	glGenTextures(1, &m_GpuBuffer);
	glBindTexture(GL_TEXTURE_2D, m_GpuBuffer);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_CpuBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
	stbi_image_free(m_CpuBuffer);
	glDeleteTextures(1, &m_GpuBuffer);
}

Texture* Texture::GetWhiteTexture()
{
	return new Texture(std::string(TEXTURE_SRC) + std::string("White.png"));
}

Texture* Texture::GetSmileyTexture()
{
	return new Texture(std::string(TEXTURE_SRC) + std::string("Hello Smile.png"));
}

void Texture::Bind()
{
	glActiveTexture(getOpenGLSlot(m_Slot));
	glBindTexture(GL_TEXTURE_2D, m_GpuBuffer);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLint Texture::getOpenGLSlot(int slot)
{
	return GL_TEXTURE0 + slot;
}
