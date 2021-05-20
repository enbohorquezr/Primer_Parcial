#include "Gengar.h"
#include <iostream>

using namespace std;

Gengar::Gengar(Tile* _tile, Texture* _gengarTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_gengarTexture, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setGengar(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	// Inicializa propiedade de gengar
	posicionXDestino = getPosicionX();
	posicionYDestino = getPosicionY();

	velocidadX = 1;
	velocidadY = 1;
	velocidadPatron = _velocidadPatron;
}

void Gengar::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setGengar(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setGengar(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}

bool Gengar::tratarDeMover(MoveDirection _direccionNueva) {
	Tile* tileDestino = nullptr;

	switch (_direccionNueva) {
	case MOVE_UP:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
		break;
	case MOVE_DOWN:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
		break;
	case MOVE_LEFT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
		break;
	case MOVE_RIGHT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY());
		break;
	}

	if (tileDestino == nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	if (tileDestino->getPared() != nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	setTileSiguiente(tileDestino);

	return true;
}

void Gengar::update()
{
	if (enMovimiento) {
		GameObject::update();
	}
	else {
		direccionSiguiente = MoveDirection(rand() % 6);
	}

	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);

		if (tileSiguiente == nullptr)
			enMovimiento = false;
		else
			enMovimiento = true;
	}
	else {
		switch (direccionActual) {
		case MOVE_UP:
			posicionY = max(posicionY - velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = min(posicionY + velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_RIGHT:
			posicionX = max(posicionX - velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_LEFT:
			posicionX = min(posicionX + velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && getPosicionY() == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && getPosicionX() == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);

	}

	//variables

	//if (contadorTiempoVisible >= tiempoVisible) {
	//	visible = false;
	//	if (contadorTiempoNoVisible >= tiempoNoVisible) {
	//		posicionX = 1 + rand() % anchoPantalla;
	//		posicionY = 1 + rand() % altoPantalla;
	//		contadorTiempoVisible = 0;
	//		contadorTiempoNoVisible = 0;
	//		visible = true;
	//		//numeroFrutaVisible = rand() % frutasTextures.size();
	//		numeroGengarVisible = rand() % 1;
	//	}
	//	else {
	//		contadorTiempoNoVisible++;
	//		//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
	//	}
	//}
	//else {
	//	contadorTiempoVisible++;
	//}

}