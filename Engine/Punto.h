#pragma once

#include <utility> // std::pair

class Punto {
private:
	int posx, posy; // coordenadas
public:
	Punto(const int x=-1, const int y=-1);

	void asignar(const int x_, const int y_);

	void asignar(const std::pair <int, int> & p);

	// Devuelve la coord x
	int x() const;

	// Devuelve la coord y
	int y() const;

	//int operator[] (const int i) const;

	// Con & permite asignaciones (a[1] = 3)
	int& operator [] (const int i);
};