#include "Forma.h"

Forma::Forma(const int x, const int y, Graphics& gfx, Grid& grid, const int r_, const int g_, const int b_) 
	:
	pos(x, y), m_gfx(gfx), m_grid(grid), r(r_), g(g_), b(b_)
{
	//cuadrantes.first = x;
}


void Forma::mod_grosor(const unsigned grosor)
{
	// No deberias llamar a esta si no eres una recta
	
}
