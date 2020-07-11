#include <iostream>
#include <fstream>

#include "Graphics.h"
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

    Shape* shape = Shape::GenerateTile(0,14);

    Shader* basicShader = Shader::GenerateTileShaders();
    while (GLenum error = glGetError()) {
        std::cerr << "OPENGL ERROR: " << error << "\n";
        assert(false);
    }
    basicShader->Bind();
    while (GLenum error = glGetError()) {
        std::cerr << "OPENGL ERROR: " << error << "\n";
        assert(false);
    }

    while (Window::Instance()->Update())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, 640, 480);
        shape->Draw();
    }

    delete basicShader;
    delete shape;

    glfwTerminate();
    /*while (GLenum error = glGetError()) {
        std::cerr << "OPENGL ERROR: " << error << "\n";
        assert(false);
    }*/
    return 0;
}