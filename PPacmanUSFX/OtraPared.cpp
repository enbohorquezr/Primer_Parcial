#include "OtraPared.h"

OtraPared::OtraPared(Tile* _tile, Texture* _otraParedTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_otraParedTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla) {

	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setOtraPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
};

void OtraPared::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setOtraPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setOtraPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
};
