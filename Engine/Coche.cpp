#define NOMINMAX 
// (Para quitar la mierda de #define min y max de windows para usar los de std)
//#include <iostream>
#include <algorithm>
#include "Coche.h"



Coche::Coche(Graphics& gfx_, const int posx_, const int posy_, const int tam_, const double decel_frente,
			 const double decel_lat, const int r_, const int g_, const int b_)
	: 
	tam(tam_), Forma(posx_, posy_, gfx_, r_, g_, b_),
	deceleracion_frente(decel_frente), deceleracion_lat(decel_lat)
{}

Coche::~Coche() {}

void Coche::dibujar() const {
	gfx.dibujarCoche(pos.x(), pos.y(), tam, orientacion, r, g, b);
}

void Coche::acelerar(const double nueva, const double dir)
{
	orientacion = dir;
	int indice = int(dir) % 2;
	acel[indice] = (dir == 0 || dir == 3) ? (nueva) : (-nueva); // elegimos signo
	// gfx.dibujarCuad(int(orientacion)+20, int(orientacion)+20, 5, 255, 255, 255); // debug a lo bestia
	decelerar_lateral(indice);
}

// Devuelve la v minima entre v y vmax, teniendo en cuenta que hay velocidades negativas
// (devuelve la mas cercana a 0)
double minima_vel(const double v, const double vmax) {
	return (v < 0) ? (std::max(v, -vmax)) : (std::min(v, vmax));
}

void Coche::mover() {
	for (int i = 0; i < 2; i++) {
		vel[i] = minima_vel(vel[i] + acel[i], vmax);
		pos[i] += vel[i];
	}
}

bool Coche::colision(const Forma& otra) const {
	return false;
}

void Coche::decelerar_lateral(const int i) {
	if (vel[1 - i] > -0.08 && vel[1 - i] < 0.08) {
		acel[1 - i] = vel[1 - i] = 0;
	}
	else {
		acel[1 - i] = (vel[1 - i] > 0) ? (-deceleracion_lat) : (deceleracion_lat);
	}
}


void Coche::decelerar() {
	int indice = int(orientacion) % 2;
	if (-0.08 < vel[indice] && vel[indice] < 0.08) { // v aproximadamente 0
		acel[indice] = vel[indice] = 0;
	}
	else {
		acel[indice] = (vel[indice]>0) ? (-deceleracion_frente) : (deceleracion_frente);
	}
	decelerar_lateral(indice);
}


// En algun momento aprendere a dibujar rectangulos girados. Que bajo han caido mis expectativas vitales
//void Coche::rotar(const bool dcha) {
//	if (cuentaReloj <= 0) {
//		cuentaReloj = cuentaRelojMax;
//		double giro = 1; // gira a la izq
//		if (dcha) {
//			giro = -1;
//		}
//		orientacion += giro;
//		if (orientacion < 0) { 
//			// Nos hemos pasado de vuelta, corregimos
//			orientacion += 4;
//		}
//		double a_aux = acel[0];
//		double v_aux = vel[0];
//		acel[0] = acel[1];
//		vel[0] = vel[1];
//		acel[1] = acel[0];
//		vel[1] = vel[0];
//	}
//}
