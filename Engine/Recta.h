#pragma once

#include "Forma.h"

class Recta : public Forma {
private:
	Punto ini, fin; // Definida por sus extremos
	int m_grosor;
public:
	Recta(Graphics& gfx, Grid& grid, const int x1, const int y1, const int x2, const int y2, 
		  const unsigned grosor = 1, const int r = 255, const int g = 255, const int b = 255);


	bool colision(const Forma& otra) const override;

	void dibujar() const override;

	// Para modificar el grosor
	void mod_grosor(const unsigned grosor);


	/*Recta& operator= (const Recta& r);*/
};