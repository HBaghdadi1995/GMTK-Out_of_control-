#include "Graphics.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
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
}
