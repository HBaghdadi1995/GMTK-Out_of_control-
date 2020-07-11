#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Window.h"
#include "Shape.h"

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

    /*GLuint buffer;

    float positions[12] =
    { -0.5f, 0.5f,
      -0.5f, -0.5f,
      0.5f, -0.5f,
      0.5f, 0.5f,
      -0.5f, 0.5f,
      0.5f, -0.5f };

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), &positions, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        sizeof(float) * 2,                  // stride
        0            // array buffer offset
    );*/

    Shape* shape = Shape::GenerateSquare();

    Shader* basicShader = Shader::GenerateBasicShaders();
    basicShader->Bind();

    while (Window::Instance()->Update())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, 640, 480);
        shape->Draw();
    }
    while (GLenum error = glGetError()) {
        std::cerr << "OPENGL ERROR: " << error << "\n";
        assert(false);
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