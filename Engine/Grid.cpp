#include <cassert>
#include "Grid.h"
#include "Forma.h" // Se incluye aqui por lo de las dep circulares

Grid::Grid(Graphics& gfx, const unsigned nCol, const unsigned nFil) 
	:
	m_gfx(gfx), m_N(nCol), m_M(nFil), 
	pixelesLat(gfx.ScreenWidth / double(nCol)), 
	pixelesVer(gfx.ScreenHeight / double(nFil))
{
}

int Grid::numColumnas() const
{
	return m_N;
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

void Grid::cuadrantesDeForma(const Forma& f, std::vector<int>& cuadrantes) {
	cuadrantes.clear();
	//f.mis_cuadrantes(cuadrantes);
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
