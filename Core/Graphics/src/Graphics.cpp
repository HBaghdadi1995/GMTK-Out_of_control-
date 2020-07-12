#include "Graphics.h"

Graphics* Graphics::m_Instance = nullptr;

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
    for (auto it = m_GraphicalObjects.begin(); it != m_GraphicalObjects.end(); ++it) {
        delete (*it);
    }
    for (auto it = m_Shaders.begin(); it != m_Shaders.end(); ++it) {
        delete (*it);
    }
    for (auto it = m_Textures.begin(); it != m_Textures.end(); ++it) {
        delete (*it);
    }
}

Graphics* Graphics::Instance()
{
    if (!m_Instance) {
        m_Instance = new Graphics();
    }
	return m_Instance;
}

void Graphics::Destroy()
{
    delete m_Instance;
}

void Graphics::Bind(void* procAddress)
{
    if (!gladLoadGLLoader((GLADloadproc)procAddress)) {
        assert(false);
    }
    if (!gladLoadGL()) {
        assert(false);
    }
}

void Graphics::EnableBlend()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Graphics::CheckForError()
{
    while (GLenum error = glGetError()) {
        std::cerr << "OPENGL ERROR: " << error << "\n";
        assert(false);
    }
}

void Graphics::Update()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, 640, 480);
}

void Graphics::BuildTests() {
    m_Textures.push_back(Texture::GetSmileyTexture());
    m_Shaders.push_back(Shader::GenerateTexturedTileShaders());
    m_GraphicalObjects.push_back(new GraphicalObject(0, 14, m_Shaders.back(), { m_Textures.back(), 0.0f, 1.0f, 0.0f, 1.0f }));
}

void Graphics::Draw()
{
    for (auto it = m_GraphicalObjects.begin(); it != m_GraphicalObjects.end(); ++it) {
        (*it)->Draw();
    }
}
