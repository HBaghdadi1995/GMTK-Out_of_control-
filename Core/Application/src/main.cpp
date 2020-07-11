#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Window.h"

#include <stb_image.h>


int main(int argc, char *argv[]){

    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Hello World");

    Graphics::Instance();
    Graphics::Instance()->Bind(Window::Instance()->GetProcAddressFunction());

    //Graphics::Instance()->Load(GRAPHICS__BASICS);

    Shape* shape = Shape::GenerateTile(0,14);
    Texture* texture = Texture::GetSmileyTexture();
    texture->Bind();

    Shader* basicShader = Shader::GenerateTexturedTileShaders();
    basicShader->Bind();

    basicShader->setUniform("u_Texture",texture->getSlot());
    basicShader->setUniform("u_Texture", texture->getSlot());

    Graphics::Instance()->EnableBlend();


    Graphics::CheckForError();

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

    Graphics::Destroy();
    Window::Destroy();

    return 0;
}