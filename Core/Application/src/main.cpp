#include <iostream>

#include <glad/glad.h>
#include "Window.h"

int main(int argc, char *argv[]){
    GLFWwindow* window;

    Window::Instance();

    Window::Instance()->CreateWindow(640, 480, "Hello World");
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        assert(false);
    }

    GLuint buffer;

    float positions[6] =
    { 0.0f, 0.5f,
      -0.5f, -0.5f,
      0.5f, -0.5f };

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        sizeof(float),                  // stride
        0            // array buffer offset
    );

    if (!gladLoadGL()) {
        assert(false);
    }
    glPointSize(32);

    while (Window::Instance()->Update())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, 640, 480);
        glDrawArrays(GL_POINTS, 0, 3);
    }

    glfwTerminate();
    return 0;
}