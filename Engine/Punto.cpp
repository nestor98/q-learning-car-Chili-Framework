#include "Punto.h"

Punto::Punto(const int x, const int y) : posx(x), posy(y) {}

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

//int Punto::operator[] (const int i) const
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

