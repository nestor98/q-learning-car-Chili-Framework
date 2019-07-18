// Para la deteccion de colisiones, supongo que ayudara
// La idea es solo comprobar cacharros que estan en los mismos cuadrantes 

#pragma once
#include <vector>
#include "Graphics.h"
#include "Punto.h"
//#include "Forma.h" // Dep circular!

class Forma;

class Grid {
private:
	int m_N, m_M; // numero de lineas laterales y verticales
	int pixelesLat, pixelesVer; // nº pixeles de cada cuadrante
	Graphics& m_gfx;
public:
	typedef unsigned int Cuadrante;

	Grid(Graphics& gfx, const unsigned nCol = 16, const unsigned nFil = 12);

	// Devuelve el nº de cuadrantes horizontales (nº columnas)
	int numColumnas() const;

	// Devuelve true sii estan en el mismo
	bool enMismoCuadrante(const Forma& una, const Forma& otra) const;
	int cuadranteDePos(const Punto& p) const;
	int cuadranteDePos(const int x, const int y) const;
	std::pair<int, int> coordenadas(const unsigned cuadrante) const;

	void cuadrantesDeForma(const Forma& f, std::vector<int>& cuadrantes);

	// Para probar, dibuja el cuadrante del numero:
	void dibujar(const int cuadrante) const;
};