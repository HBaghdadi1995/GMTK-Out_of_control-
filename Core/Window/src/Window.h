//Copywright (C) 2020 Hasan Al-Baghdadi
#pragma once
#include <assert.h>
#include <string>

#include <GLFW/glfw3.h>

class Window
{
private:

    GLFWwindow* m_Window = nullptr;
    
    Window();
    ~Window();
    static Window* m_Instance;
public:
    static Window* Instance();
    static void Destroy();

    void CreateWindow(int width, int height, std::string name);
    bool Update();

    void* GetProcAddressFunction() const { return glfwGetProcAddress; }

    void Window::setVSync(bool on);

    GLFWwindow* getWindowObject();
private:
};

