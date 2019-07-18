/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include <memory> // shared_ptr
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Rectangulo.h"
#include "Coche.h"
#include "Recta.h"


class Game
{
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Coche coche;
	enum class formas { // Para probar enum (class es por c++11)
		recta,
		rectangulo
	};
	formas seleccionada = formas::recta;
	std::vector<std::shared_ptr<Forma>> figs;// = { std::make_shared<Derived>() };; // Figuras del circuito
	unsigned grosor = 2; // de las rectas
	Punto p; // inicio de la recta dibujada
	bool dibujando = false; // no se ha soltado el raton 
							// (seguro que se puede hacer de otra forma)
	/********************************/

public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void procesarRaton(Mouse::Event& e);
	// Cambia la forma seleccionada
	void cambiarForma();
	// Dibuja la forma apropiada entre los puntos 1 y 2
	void dibujarForma(const int x1, const int y1, const int x2, const int y2);
	/********************************/
};