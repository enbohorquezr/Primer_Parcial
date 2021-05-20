#pragma once
#include "GameObject.h"
#include "TileGraph.h"

class OtraPared :
    public GameObject
{
private:
    Tile* tileActual;

public:
    OtraPared(Tile* _tile, Texture* _otraParedTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
    Tile* getTile() { return tileActual; }
    void setTile(Tile* _tileNuevo);
};

