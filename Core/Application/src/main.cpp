#include <iostream>
#include <fstream>

#include "Graphics.h"
#include "Timer.h"
#include "Window.h"
#include "InputManager.h"

#include "RandPlayer.h"

#include <stb_image.h>

RandPlayerObject* player;

void Initialise() {
    Window::Instance();
    Window::Instance()->CreateWindow(640, 480, "Drunkard");

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

    player = new RandPlayerObject();
    player->setGraphicalObject(Graphics::Instance()->getGraphicalObject(eOBJECT_PLAYER));
    player->SetPosition(10, 7);
    player->BindControlls();
}

void Loop() {

    bool shouldLose = false;

    while (Window::Instance()->Update() && InputManager::Instance()->PollEvents() && !shouldLose)
    {
        Graphics::Instance()->Update();
        Graphics::Instance()->Draw();
        shouldLose = player->ShouldLose();
    }

    std::cout << "CONGRATZ, your score is : " << player->score << "\n";
    system("pause");
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