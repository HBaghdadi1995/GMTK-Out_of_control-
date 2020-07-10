#pragma once
#include <assert.h>
#include <string>

#include <GLFW/glfw3.h>



class Window
{
private:
	GLFWwindow* m_Window = nullptr;
	
	static Window* m_Instance;
public:
	static Window* Instance();
	static void Destroy();

	void CreateWindow(int width, int height, std::string name);
	bool Update();
private:
	Window();
	~Window();
};

