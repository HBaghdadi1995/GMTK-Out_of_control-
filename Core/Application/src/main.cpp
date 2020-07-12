#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Timer.h"
#include "Window.h"
#include "InputManager.h"

#include <stb_image.h>

void Initialise() {
    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Reinventing the wheel");

    InputManager::Instance();
    InputManager::Instance()->AttachToGLFW(Window::Instance()->getWindowObject());

    Graphics::Instance();
    Graphics::Instance()->Bind(Window::Instance()->GetProcAddressFunction());

    Graphics::Instance()->BuildTests();

    Window::Instance()->setVSync(true);

    Graphics::Instance()->EnableBlend();
    Graphics::CheckForError();

}

void Loop() {

    while (Window::Instance()->Update() && InputManager::Instance()->PollEvents())
    {
        Graphics::Instance()->Update();
        Graphics::Instance()->Draw();
    }
}

void Deinit() {

    Graphics::Destroy();
    Window::Destroy();
}


int main(int argc, char *argv[]){

    Initialise();
    Loop();
    Deinit();

    return 0;
}