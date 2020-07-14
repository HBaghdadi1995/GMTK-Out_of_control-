//Copywright (C) 2020 Hasan Al-Baghdadi

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
    Window::Instance()->CreateWindow(640, 480, "Drunkard.exe");

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
    //Graphics::CheckForError();

    player = new RandPlayerObject();
    player->setGraphicalObject(Graphics::Instance()->getGraphicalObject(eOBJECT_PLAYER));
    player->SetPosition(10, 7);
    player->BindControlls();
}

void Loop() {

    bool shouldLose = false;
    player->SetPosition(10, 7);
    player->score = 0;
    player->speed = 0.01f;

    player->m_UpVal = 0x01;
    player->m_DownVal = 0x03;
    player->m_LeftVal = 0x00;
    player->m_RightVal = 0x02;

    while (Window::Instance()->Update() && InputManager::Instance()->PollEvents() && !shouldLose)
    {
        Graphics::Instance()->Update();
        Graphics::Instance()->Draw();
        shouldLose = player->ShouldLose();
    }

}

int main(int argc, char* argv[]);

void Deinit() {
deinit_begin:

    glfwHideWindow(Window::Instance()->getWindowObject());

    if (!glfwWindowShouldClose(Window::Instance()->getWindowObject())) {
        std::cout << "CONGRATZ, your score is : " << player->score << "\n";
        std::cout << "Type in r to reset, and anything else to leave" << "\n";
        std::string reset;
        std::cin >> reset;

        if (reset.size() == 1 && reset.c_str()[0] == 'r') {
            glfwShowWindow(Window::Instance()->getWindowObject());
            Loop();
            goto deinit_begin;
        }
    }
    


    delete player;
    Graphics::Destroy();
    Window::Destroy();
}


int main(int argc, char *argv[]){

    Initialise();
    Loop();
    Deinit();

    return 0;
}