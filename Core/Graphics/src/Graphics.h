#pragma once
#include "GraphicalObject.h"
#include "Shape.h"
#include "Texture.h"

#include <vector>

enum eShaders
{
	eSHADER_TEXTURED_TILES
};
enum eTextures
{
	eTEXTURES_SMILEY,
	eTEXTURES_WHITE
};

enum eObjects
{
	eOBJECT_PLAYER = 300
};

class Graphics
{
private:

	Graphics();
	~Graphics();
	static Graphics* m_Instance;

	std::vector<Texture*> m_Textures = std::vector<Texture*>();
	std::vector<Shader*> m_Shaders = std::vector<Shader*>();
	std::vector<GraphicalObject*> m_GraphicalObjects = std::vector<GraphicalObject*>();
public:
	static Graphics* Instance();
	static void Destroy();

	void Bind(void* procAddress);

	//void Load(unsigned int assets);

	void EnableBlend();

	static void CheckForError();

	void Update();

	void BuildShaders();
	void BuildTextures();
	void BuildTiles();
	void BuildCharacter();

	void Draw();

	GraphicalObject* getGraphicalObject(int i);
private:

};