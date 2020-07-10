#include <iostream>
#include "glad/glad.h"
#include "Window.h"

int main(int argc, char *argv[]){
    GLFWwindow* window;

    Window::Instance();

    Window::Instance()->CreateWindow(640, 480, "Hello World");
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        assert(false);
    }

    if (!gladLoadGL()) {
        assert(false);
    }

    while (Window::Instance()->Update())
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glfwTerminate();
    return 0;
}