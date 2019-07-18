#include "Recta.h"

Recta::Recta(Graphics& gfx, Grid& grid, const int x1, const int y1, const int x2, const int y2, const unsigned grosor, const int r, const int g, const int b)
	:
	Forma((x1+x2)/2, (y1+y2)/2, gfx, grid, r, g, b), ini(x1,y1), fin(x2, y2), m_grosor(grosor)
{}



bool Recta::colision(const Forma & otra) const
{
	return false;
}

void Recta::dibujar() const
{
	m_gfx.dibujarLinea(ini.x(), ini.y(), fin.x(), fin.y(), m_grosor, r, g, b);
}

void Recta::mod_grosor(const unsigned grosor)
{
	m_grosor = grosor;
}


// Algo falla aqui
//Recta& Recta::operator=(const Recta& r)
//{
//	return *this = r;
//}


