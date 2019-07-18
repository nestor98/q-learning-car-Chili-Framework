#pragma once

#include "Forma.h"

class Rectangulo : public Forma {
private:
	int tamx, tamy;
public:

	Rectangulo(Graphics& gfx, Grid& grid, const int x, const int y, const int tamx_, const int tamy_, const int r_ = 125, const int g_ = 125, const int b_ = 125);

	// Constructor a partir de dos esquinas
	Rectangulo(const int x1, const int y1, const int x2, const int y2, Graphics& gfx, Grid& grid, const int r_ = 125, const int g_ = 125, const int b_ = 125);

	bool colision(const Forma& otra) const override;

	void dibujar() const override;

};