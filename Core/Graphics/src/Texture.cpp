#include "Texture.h"

int Texture::n_slots = 0;;

Texture::Texture(std::string texAddress):
	m_Slot(n_slots)
{
	++n_slots;
	stbi_set_flip_vertically_on_load(1);
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

Texture* Texture::GetScratchTileSet()
{
	return new Texture(std::string(TEXTURE_SRC) + std::string("Scratch_Tileset.png"));
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

float* Texture::getTexCoords(int x, int y)
{
	float ratio[2] = { static_cast<float>(tileSize) / static_cast<float>(m_Width), static_cast<float>(tileSize)/ static_cast<float>(m_Height) };
	float texCoords[4] = { x * ratio[0], (x + 1) * ratio[0], y * ratio[1], (y + 1) * ratio[1] };
	return texCoords;
}

GLint Texture::getOpenGLSlot(int slot)
{
	return GL_TEXTURE0 + slot;
}
