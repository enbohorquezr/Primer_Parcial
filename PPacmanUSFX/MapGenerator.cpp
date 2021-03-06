#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla)
{
	tileGraph = _tileGraph;
	textureManager = _textureManager;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared1"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
				//nueva pared
			case 'w':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared2"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
			case 'e':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared3"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
			case 'r':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared4"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
			case 't':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared5"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
			case 'y':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared6"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
			case 'u':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared7"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;
			case 'i':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared8"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;

				//fin pared

				//otra pared
			case 'l':
				objetoNuevo = new OtraPared(tileNuevo, textureManager->getTexture("otraPared"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(1);
				break;


			case '.':
				objetoNuevo = new Moneda(tileNuevo, textureManager->getTexture("moneda"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				//objetoNuevo->setParametrosAnimacion(4);
				break;
			case '*':
				objetoNuevo = new Moneda(tileNuevo, textureManager->getTexture("supermoneda"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(7);
				break;
			case 'p':
				objetoNuevo = new Pacman(tileNuevo, textureManager->getTexture("pacman"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'a':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma1"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'b':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma2"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'c':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma3"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'd':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma4"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(4);
				break;
				//picachu
			case 'q':
				objetoNuevo = new picachu(tileNuevo, textureManager->getTexture("Picachu"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
				//gengar
			case 'g':
				objetoNuevo = new Gengar(tileNuevo, textureManager->getTexture("gengar"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			}

			// If the object was created, add it to the vector
			if (objetoNuevo != nullptr) {
				vectorObjetosJuego.push_back(objetoNuevo);
			}
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*> &_vectorObjetosJuegoGM)
{
	/*for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}*/

	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}

}