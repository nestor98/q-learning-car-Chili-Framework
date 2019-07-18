#include "Punto.h"

Punto::Punto(const int x, const int y) : posx(x), posy(y) {}

Punto::Punto(const std::pair<int, int>& p) 
	:
	Punto(p.first, p.second)
{
}

int Punto::x() const
{
	return posx;
}


void Punto::asignar(const int x, const int y) {
	posx = x;
	posy = y;
}

void Punto::asignar(const std::pair<int, int>& p)
{
	posx = p.first;
	posy = p.second;
}

int Punto::y() const
{
	return posy;
}

void Punto::escalar(const int c)
{
	escalar(c, c);
}

void Punto::escalar(const int c1, const int c2)
{
	posx *= c1;
	posy *= c2;
}

//int Punto::operator[] (const int i) const // Solo lectura
//{
//	if (i == 0) {
//		return posx;
//	}
//	else {
//		return posy;
//	}
//}

int& Punto::operator[] (const int i)
{
	if (i == 0) {
		return posx;
	}
	else {
		return posy;
	}
}

