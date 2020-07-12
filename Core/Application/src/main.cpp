#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Timer.h"
#include "Window.h"
#include "InputManager.h"

#include "PlayerObject.h"

#include <stb_image.h>

PlayerObject* player;

void Initialise() {
    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Reinventing the wheel");

    InputManager::Instance();
    InputManager::Instance()->AttachToGLFW(Window::Instance()->getWindowObject());

    Graphics::Instance();
    Graphics::Instance()->Bind(Window::Instance()->GetProcAddressFunction());

    Graphics::Instance()->BuildShaders();
    Graphics::Instance()->BuildTextures();
    Graphics::Instance()->BuildTiles();
    Graphics::Instance()->BuildCharacter();

    Window::Instance()->setVSync(true);

    Graphics::Instance()->EnableBlend();
    Graphics::CheckForError();

    player = new PlayerObject();
    player->setGraphicalObject(Graphics::Instance()->getGraphicalObject(eOBJECT_PLAYER));
    player->SetPosition(19, 7);
    player->BindControlls();
}

void Loop() {

    while (Window::Instance()->Update() && InputManager::Instance()->PollEvents())
    {
        Graphics::Instance()->Update();
        Graphics::Instance()->Draw();
    }
}

void Deinit() {
    Graphics::CheckForError();

    Graphics::Destroy();
    Window::Destroy();
}


int main(int argc, char *argv[]){

    Initialise();
    Loop();
    Deinit();

    return 0;
}