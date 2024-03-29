#pragma once
#include <vector>
#include "Graphics.h"
#include "Punto.h"
#include "Grid.h"

class Forma {
protected:
	Punto pos; // posicion central
	int r, g, b; // Color
	Graphics& m_gfx;
	Grid& m_grid; // Colisionessss
	std::vector<int> cuadrantes; // Donde esta, para las colisiones 
public:
	Forma(const int x, const int y, Graphics& gfx, Grid& grid, const int r_ = 255, const int g_ = 255, const int b_ = 255);

	virtual ~Forma() = default;

	virtual void dibujar() const = 0;

	virtual bool colision(const Forma&) const = 0;
	 
	virtual void mod_grosor(const unsigned grosor);

private:
	// Para rellenar el vector de cuadrantes
	virtual void mis_cuadrantes(std::vector<int>& cuads) const = 0;
};