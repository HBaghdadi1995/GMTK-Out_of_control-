#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Window.h"

#include <stb_image.h>

Shape* shape = nullptr;
Texture* texture = nullptr;
Shader* basicShader = nullptr;

void Initialise() {
    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Hello World");

    Graphics::Instance();
    Graphics::Instance()->Bind(Window::Instance()->GetProcAddressFunction());

    //Graphics::Instance()->Load(GRAPHICS__BASICS);

    shape = Shape::GenerateTile(0, 14);
    texture = Texture::GetSmileyTexture();
    texture->Bind();

    basicShader = Shader::GenerateTexturedTileShaders();
    basicShader->Bind();

    basicShader->setUniform("u_Texture", texture->getSlot());
    basicShader->setUniform("u_Texture", texture->getSlot());

    Graphics::Instance()->EnableBlend();
    Graphics::CheckForError();

}

void Loop() {
    while (Window::Instance()->Update())
    {
        Graphics::Instance()->Update();
        shape->Draw();
    }
}

void Deinit() {

    delete basicShader;
    delete shape;
    delete texture;

    Graphics::Destroy();
    Window::Destroy();
}


int main(int argc, char *argv[]){

    Initialise();
    Loop();
    Deinit();

    return 0;
}