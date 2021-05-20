#pragma once
#include<map>
#include "Texture.h"
using namespace std;

class TextureManager
{
private:
	map<string, Texture*> mapTexturas;

	const string pathPacman = "Resources/pac1.png";
	const string pathFantasma1 = "Resources/Blinky.bmp";
	const string pathFantasma2 = "Resources/Clyde.bmp";
	const string pathFantasma3 = "Resources/Inkey.bmp";
	const string pathFantasma4 = "Resources/Pinky.bmp";
	const string pathFruta = "Resources/Frutas.png";
	const string pathMoneda = "Resources/mPokebola.png";
	const string pathSuperMoneda = "Resources/Mball.png";
	const string pathPared1 = "Resources/pared/pared1.png";
	//picachu
	const string pathPicachu = "Resources/picachu100x100.png";
	//gengar
	const string pathGengar = "Resources/gengar100x100.png";
	//pared
	const string pathPared2 = "Resources/pared/pared2.png";
	const string pathPared3 = "Resources/pared/codo1.png";
	const string pathPared4 = "Resources/pared/codo2.png";
	const string pathPared5 = "Resources/pared/codo3.png";
	const string pathPared6 = "Resources/pared/codo4.png";
	const string pathPared7 = "Resources/pared/codo5.png";
	const string pathPared8 = "Resources/pared/codo6.png";
	//otra pared
	const string pathOtraPared = "Resources/centro.png";


	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;
	//pacman
	Texture* picachuTexture;
	//gengar
	Texture* gengarTexture;

	//pared texture
	Texture* pared2Texture;
	Texture* pared3Texture;
	Texture* pared4Texture;
	Texture* pared5Texture;
	Texture* pared6Texture;
	Texture* pared7Texture;
	Texture* pared8Texture;
	//otraPared
	Texture* otraParedTexture;

public:
	TextureManager();
	~TextureManager();

	Texture* getTexture(string _key) { return mapTexturas[_key]; }
	void addTexture(string _key, Texture* _texture);
	void free();


};

