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
    static int n_slots;

public:
    Texture(std::string texAddress);
    ~Texture();

    static Texture* GetWhiteTexture();
    static Texture* GetSmileyTexture();
    static Texture* GetBallTexture();
    static Texture* GetScratchTileSet();

    void Bind();
    void Unbind();

    inline int getSlot() const { return m_Slot; }

    float* getTexCoords(int x, int y);

private:
    static GLint getOpenGLSlot(int slot);
    const int tileSize = 32;
};