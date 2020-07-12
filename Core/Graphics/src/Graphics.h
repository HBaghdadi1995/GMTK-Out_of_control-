#pragma once
#include "GraphicalObject.h"
#include "Shape.h"
#include "Texture.h"

#include <vector>

#define GRAPHICS__BASICS 0x01

class Graphics
{
private:

	Graphics();
	~Graphics();
	static Graphics* m_Instance;

	std::vector<Texture*> m_Textures;
	std::vector<Shader*> m_Shaders;
	std::vector<GraphicalObject*> m_GraphicalObjects;
public:
	static Graphics* Instance();
	static void Destroy();

	void Bind(void* procAddress);

	//void Load(unsigned int assets);

	void EnableBlend();

	static void CheckForError();

	void Update();

	void BuildTests();

	void Draw();
private:

};