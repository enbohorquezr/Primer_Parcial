#pragma once
#include <SDL.h>

class Pacman;
class Fantasma;
class Fruta;
class Moneda;
class Pared;
class picachu;
class Gengar;
class OtraPared;

class Tile
{
private:
	Pacman* pacman;
	Fantasma* fantasma;
	Fruta* fruta;
	Moneda* moneda;
	Pared* pared;
	picachu* Picachu;
	Gengar* gengar;
	OtraPared* otraPared;

	int posicionX;
	int posicionY;

public:
	static const int anchoTile = 25;
	static const int altoTile = 25;

public:
	Tile();
	Tile(int _x, int _y);

	Pacman* getPacman() { return pacman; }
	Fantasma* getFantasma() { return fantasma; }
	Fruta* getFruta() { return fruta; }
	Moneda* getMoneda() { return moneda; }
	Pared* getPared() { return pared; }
	//nueva implementación
	picachu* getPicachu() { return Picachu; }
	Gengar* getGengar() { return gengar; }
	OtraPared* getOtraPared() { return otraPared; }


	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }

	void setPacman(Pacman* _pacman) { pacman = _pacman; }
	void setFantasma(Fantasma* _fantasma) { fantasma = _fantasma; }
	void setFruta(Fruta* _fruta){ fruta = _fruta; }
	void setMoneda(Moneda* _moneda) { moneda = moneda; }
	void setPared(Pared* _pared) { pared = _pared; }
	//nueva implementación
	void setPicachu(picachu* _Picachu) { Picachu = _Picachu; }
	void setGengar(Gengar* _gengar) { gengar = _gengar; }
	void setOtraPared(OtraPared* _otraPared) { otraPared = _otraPared; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

};

