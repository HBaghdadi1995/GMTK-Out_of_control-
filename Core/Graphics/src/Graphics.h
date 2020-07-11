#pragma once
#include "Shader.h"
#include "Shape.h"
#include "Texture.h"

#define GRAPHICS__BASICS 0x01

class Graphics
{
private:

	Graphics();
	~Graphics();
	static Graphics* m_Instance;
public:
	static Graphics* Instance();
	static void Destroy();

	void Bind(void* procAddress);

	//void Load(unsigned int assets);

	void EnableBlend();

	static void CheckForError();

	void Update();
private:

};