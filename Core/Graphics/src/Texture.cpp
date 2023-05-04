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

    GL_CALL(glGenTextures(1, &m_GpuBuffer));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_GpuBuffer));


    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER));

    GL_CALL(glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        m_Width,
        m_Height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        m_CpuBuffer
    ));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}

Texture::~Texture()
{
    stbi_image_free(m_CpuBuffer);
   GL_CALL(glDeleteTextures(1, &m_GpuBuffer));
}

Texture* Texture::GetWhiteTexture()
{
    return new Texture(std::string(TEXTURE_SRC) + std::string("White.png"));
}

Texture* Texture::GetSmileyTexture()
{
    return new Texture(std::string(TEXTURE_SRC) + std::string("Hello Smile.png"));
}

Texture* Texture::GetBallTexture()
{
    return new Texture(std::string(TEXTURE_SRC) + std::string("Ball.png"));
}

Texture* Texture::GetScratchTileSet()
{
    return new Texture(std::string(TEXTURE_SRC) + std::string("Scratch_Tileset.png"));
}

void Texture::Bind()
{
    GL_CALL(glActiveTexture(getOpenGLSlot(m_Slot)));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_GpuBuffer));
}

void Texture::Unbind()
{
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}

float* Texture::getTexCoords(int x, int y)
{
    y = static_cast<float>(m_Height) / static_cast<float>(tileSize) - y;
    float ratio[2] = { static_cast<float>(tileSize) / static_cast<float>(m_Width), static_cast<float>(tileSize) / static_cast<float>(m_Height) };
    float* texCoords = new float[4];
    texCoords[0] = x* ratio[0];
    texCoords[1] = (x + 1)* ratio[0];
    texCoords[2] = (y-1) * ratio[1];
    texCoords[3] = (y) * ratio[1];
    return texCoords;
}

GLint Texture::getOpenGLSlot(int slot)
{
    return GL_TEXTURE0 + slot;
}
