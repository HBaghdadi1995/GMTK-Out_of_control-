#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Window.h"

#include <stb_image.h>

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
    Texture* texture = new Texture();
    texture->Bind();

    Shader* basicShader = Shader::GenerateTexturedTileShaders();
    basicShader->Bind();

    basicShader->setUniform("u_Texture",texture->getSlot());
    basicShader->setUniform("u_Texture", texture->getSlot());

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
    delete texture;

    glfwTerminate();
    /*while (GLenum error = glGetError()) {
        std::cerr << "OPENGL ERROR: " << error << "\n";
        assert(false);
    }*/
    return 0;
}