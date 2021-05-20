#include "TextureManager.h"

TextureManager::TextureManager()
{
	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	addTexture("pacman", pacmanTexture);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasma1);
	addTexture("fantasma1", fantasma1Texture);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	addTexture("fantasma2", fantasma2Texture);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	addTexture("fantasma3", fantasma3Texture);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	addTexture("fantasma4", fantasma4Texture);
	frutaTexture = new Texture();
	frutaTexture->loadFromImage(pathFruta);
	addTexture("fruta", frutaTexture);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	addTexture("moneda", monedaTexture);
	superMonedaTexture = new Texture();
	superMonedaTexture->loadFromImage(pathSuperMoneda);
	addTexture("supermoneda", superMonedaTexture);
	
    //picachu
	picachuTexture = new Texture();
	picachuTexture->loadFromImage(pathPicachu);
	addTexture("Picachu", picachuTexture);
	//gengar
	gengarTexture = new Texture();
	gengarTexture->loadFromImage(pathGengar);
	addTexture("gengar", gengarTexture);

	//pared
	paredTexture = new Texture();
	paredTexture->loadFromImage(pathPared1);
	addTexture("pared1", paredTexture);

	pared2Texture = new Texture();
	pared2Texture->loadFromImage(pathPared2);
	addTexture("pared2", pared2Texture);

	pared3Texture = new Texture();
	pared3Texture->loadFromImage(pathPared3);
	addTexture("pared3", pared3Texture);

	pared4Texture = new Texture();
	pared4Texture->loadFromImage(pathPared4);
	addTexture("pared4", pared4Texture);

	pared5Texture = new Texture();
	pared5Texture->loadFromImage(pathPared5);
	addTexture("pared5", pared5Texture);

	pared6Texture = new Texture();
	pared6Texture->loadFromImage(pathPared6);
	addTexture("pared6", pared6Texture);

	pared7Texture = new Texture();
	pared7Texture->loadFromImage(pathPared7);
	addTexture("pared7", pared7Texture);

	pared8Texture = new Texture();
	pared8Texture->loadFromImage(pathPared8);
	addTexture("pared8", pared8Texture);

	//otra pared

	otraParedTexture = new Texture();
	otraParedTexture->loadFromImage(pathOtraPared);
	addTexture("otraPared", otraParedTexture);


}

TextureManager::~TextureManager() {
	free();
}

void TextureManager::addTexture(string _key, Texture* _texture)
{
	mapTexturas[_key] = _texture;
}

void TextureManager::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}
