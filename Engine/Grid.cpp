#include "Grid.h"
#include <cassert>
Grid::Grid(Graphics& gfx, const unsigned nLat, const unsigned nVert) 
	:
	m_gfx(gfx), m_N(nLat), m_M(nVert), 
	pixelesLat(gfx.ScreenWidth / double(nLat)), 
	pixelesVer(gfx.ScreenHeight / double(nVert))
{
}

bool Grid::enMismoCuadrante(const Forma & una, const Forma & otra) const
{
	return false;
}

int Grid::cuadranteDePos(const Punto& p) const {
	return cuadranteDePos(p.x(), p.y());
}

int Grid::cuadranteDePos(const int x, const int y) const {
	int px = x / pixelesLat;
	int py = y / pixelesVer;
	return px + py * m_N;
}

std::pair<int, int> Grid::coordenadas(const unsigned cuadrante) const {
	return {cuadrante%m_N, cuadrante/m_N};
}

void Grid::dibujar(const int cuadrante) const
{
	Punto p(coordenadas(cuadrante));
	p.escalar(pixelesLat, pixelesVer);
	int pLatMed = pixelesLat / 2;
	int pVerMed = pixelesVer / 2;
	m_gfx.dibujarRect(p.x() + pLatMed, p.y() + pVerMed, pixelesLat, pixelesVer, 50,50,50);
} 

// airsolar
