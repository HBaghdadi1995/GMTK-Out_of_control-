#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Timer.h"
#include "Window.h"

#include <stb_image.h>

GraphicalObject* graphicalObject = nullptr;
Texture* texture = nullptr;
Shader* basicShader = nullptr;
Timer* timer = nullptr;

void Initialise() {
    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Hello World");

    Graphics::Instance();
    Graphics::Instance()->Bind(Window::Instance()->GetProcAddressFunction());

    Window::Instance()->setVSync(true);

    //Graphics::Instance()->Load(GRAPHICS__BASICS);

    texture = Texture::GetSmileyTexture();
    texture->Bind();

    basicShader = Shader::GenerateTexturedTileShaders();
    basicShader->Bind();

    basicShader->setUniform("u_Texture", texture->getSlot());

    graphicalObject = new GraphicalObject(0, 14, basicShader, {texture, 0.0f, 1.0f, 0.0f, 1.0f});

    Graphics::Instance()->EnableBlend();
    Graphics::CheckForError();

}

void Loop() {
    float i = 0;
    bool forward = true;

    while (Window::Instance()->Update())
    {
        Graphics::Instance()->Update();
        graphicalObject->Draw();
        Timer::WaitRepeat(&timer, LAMBDA(
            (forward) ? i+=0.3 : i-=0.3;
            (i > 18.7 || i < 0.3) ? (forward = !forward):(NULL);
            graphicalObject->setCoords(i, 14);
        ), 100 );
    }
}

void Deinit() {

    delete basicShader;
    delete graphicalObject;
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