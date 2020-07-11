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
    );

    if (!gladLoadGL()) {
        assert(false);
    }
    glPointSize(32);

    char* vertex_shader_source = "\n\
    #version 330 core\n\
    \n\
        layout(location = 0) in vec4 position;\n\
    \n\
        void main()\n\
    {\n\
        gl_Position = position;\n\
    };";

    char* fragment_shader_source = "\n\
    #version 330 core\n\
    \n\
    layout(location = 0) out vec4 color;\n\
    \n\
        uniform vec4 u_Color;\n\
    \n\
    void main()\n\
    {\n\
        \n\
        color = vec4(1, 0, 0, 1);\n\
    };";

    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vertex_shader_source, NULL); // vertex_shader_source is a GLchar* containing glsl shader source code
    glCompileShader(vshader);

    GLint vertex_compiled;
    glGetShaderiv(vshader, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(vshader, 1024, &log_length, message);
        std::cout << message;
    }

    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &fragment_shader_source, NULL); // fragment_shader_source is a GLchar* containing glsl shader source code
    glCompileShader(fshader);

    GLint fragment_compiled;
    glGetShaderiv(fshader, GL_COMPILE_STATUS, &fragment_compiled);
    if (fragment_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(fshader, 1024, &log_length, message);
        std::cout << "frag" << message;
    }

    GLuint program = glCreateProgram();

    glAttachShader(program, vshader);
    glAttachShader(program, fshader);
    glLinkProgram(program);

    glUseProgram(program);

    while (Window::Instance()->Update())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, 640, 480);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    glfwTerminate();
    return 0;
}