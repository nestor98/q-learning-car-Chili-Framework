#pragma once
#include "Graphics.h"
#include "Punto.h"

class Forma {
protected:
	Punto pos; // posicion central
	int r, g, b; // Color
	Graphics& gfx;
public:
	Forma(const int x, const int y, Graphics& gr_, const int r_ = 255, const int g_ = 255, const int b_ = 255);

	virtual ~Forma() = default;

	virtual void dibujar() const = 0;

	virtual bool colision(const Forma&) const = 0;
	 
	virtual void mod_grosor(const unsigned grosor);
};