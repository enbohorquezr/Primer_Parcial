#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"
#include "TextureAnimation.h"

using namespace std;

class picachu :
    public GameObject
{
private:
	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	// Velocidad en eje X e Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXEnTextura;
	int posicionYEnTextura;

	TextureAnimation* texturaAnimacion;
public:
	//Constructores y destructores
	picachu(Tile* _tile, Texture* _texturaPicachu, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//~Pacman();

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }


	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event) override;
	// Mover pacman
	void update() override;
	// Renderizar imagen pacman
	void render() override;
	//void update();

};

