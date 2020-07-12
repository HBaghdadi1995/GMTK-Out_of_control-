#include "Window.h"

Window*  Window::m_Instance = nullptr;

Window* Window::Instance()
{
    if(!m_Instance)
        m_Instance = new Window();
    return m_Instance;
}

void Window::Destroy()
{
    delete m_Instance;
}

void Window::CreateWindow(int width, int height, std::string name)
{
    if (!m_Window) {
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
        if (!m_Window)
        {
            glfwTerminate();
            assert(false);
        }
        glfwMakeContextCurrent(m_Window);
    }
    else {
        assert(false);
    }
}

bool Window::Update()
{
    glfwSwapBuffers(m_Window);
    glfwSwapInterval(1);
    glfwPollEvents();
    return !glfwWindowShouldClose(m_Window);
}

Window::Window()
{
    if (!glfwInit())
        assert(false);
}

Window::~Window()
{
    glfwTerminate();
}

void Window::setVSync(bool on)
{
    if (on) {
        glfwSwapInterval(1);
    }
    else {
        glfwSwapInterval(0);
    }
}

GLFWwindow* Window::getWindowObject()
{
    return m_Window;
}


