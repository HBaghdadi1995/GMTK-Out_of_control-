#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Timer.h"
#include "Window.h"
#include "InputManager.h"

#include <stb_image.h>

GraphicalObject* graphicalObject = nullptr;
Texture* texture = nullptr;
Shader* basicShader = nullptr;
Timer* timer = nullptr;

void Initialise() {
    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Reinventing the wheel");

    InputManager::Instance();
    InputManager::Instance()->AttachToGLFW(Window::Instance()->getWindowObject());

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

    while (InputManager::Instance()->PollEvents())
    {
        Graphics::Instance()->Update();
        graphicalObject->Draw();
        Timer::WaitRepeat(&timer, LAMBDA(
            graphicalObject->moveCoords(0.1f, -0.1f);
        ), 33 );
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