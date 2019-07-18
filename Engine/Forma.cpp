#include "Forma.h"

Forma::Forma(const int x, const int y, Graphics& gr_, const int r_, const int g_, const int b_) : pos(x, y), gfx(gr_), r(r_), g(g_), b(b_) {}

void Forma::mod_grosor(const unsigned grosor)
{
	// No deberias llamar a esta si no eres una recta
	
}
