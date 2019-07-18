#pragma once

#include <vector>
#include "Graphics.h"
#include "Forma.h"
#include "Grid.h"

class Coche : public Forma {
private:
	//std::vector<int> pos; // la pos esta ahora en Forma.h
	int tam;
	double orientacion = 1; // Hacia donde mira (de momento 0->dcha, 1->arriba, 2->izq, 3-> abajo)

	std::vector<double> vel = { 0, 0 };  // Velocidad ejes x, y
	double vmax = 7.5;					 // velocidad max
	std::vector<double> acel = { 0, 0 }; // Aceleracion ejes x, y

	double deceleracion_frente; // Deceleracion en la direccion que apunta el coche
	double deceleracion_lat; // Deceleracion lateral

	
	// Puede que las vuelva a usar:
	// int cuentaRelojMax = 20; // Para evitar cosas raras
	// int cuentaReloj = 0; // valor inicial

public:
	Coche(Graphics& gfx_, const int posx_, const int posy_, const int tam_, Grid& grid, const double decel_frente = 0.02, 
		  const double decel_lat = 0.15, const int r_=255, const int g_=255, const int b_=255);
	
	~Coche();

	// Dibuja el coche en su posicion a traves de sus graficos...
	void dibujar() const override;

	// Asigna al coche su nueva aceleracion en la direccion dir (como orientacion)
	void acelerar(const double nueva, const double dir);

	// Actualiza su velocidad (a partir de su acel) y su posicion
	void mover();

	// El coche no esta siendo acelerado
	void decelerar();

	// Para cuando sepa girar ptos rectangulos:
	// void rotar(const bool dcha);

	bool colision(const Forma& otra) const override;

private:
	// Auxiliar de decelerar
	void decelerar_lateral(const int i);
	//void decelerar_frente(double& v, double& a); // Ya no la uso
};
