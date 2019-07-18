/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	coche(gfx, gfx.ScreenWidth/2, gfx.ScreenHeight/2, 22, 0.02, 0.15, 255, 20, 20)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::procesarRaton(Mouse::Event& e) {
	// typedef Mouse::Event::Type;
	// using Mouse::Event::Type; // No se usar estas cosas
	switch (e.GetType()) {
		int x, y;
	case (Mouse::Event::Type::LPress):
		x = e.GetPosX();
		y = e.GetPosY();
		if (!dibujando) {
			p.asignar(x, y);
			dibujando = true;
		}
		else {
			if (!figs.empty())  figs.pop_back();
			dibujarForma(p.x(), p.y(), x, y);
			
		}
		break;
	case (Mouse::Event::Type::LRelease):
		if (dibujando)
			dibujarForma(p.x(), p.y(), wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
		dibujando = false;
		break;
	case (Mouse::Event::Type::RPress):
		break;
	case (Mouse::Event::Type::RRelease):
		//wnd.ShowMessageBox(L"Titulo", L"mensaje1");
		break;
	case (Mouse::Event::Type::WheelUp):
		if (grosor < 50) grosor++;
		if (dibujando) figs.back()->mod_grosor(grosor);
		break;
	case (Mouse::Event::Type::WheelDown):
		if (grosor > 0) grosor--;
		if (dibujando) figs.back()->mod_grosor(grosor);
		break;
	case (Mouse::Event::Type::Move):
		if (dibujando) {
			if (!figs.empty())  figs.pop_back();
			dibujarForma(p.x(), p.y(), e.GetPosX(), e.GetPosY());
		}
		break;

	default: // ...Type::Invalid
		wnd.ShowMessageBox(L"Vaya vaya", L"Mensaje de raton invalido??");
		break;
	}
	

}

void Game::cambiarForma()
{
	(seleccionada == formas::recta) ? (seleccionada = formas::rectangulo) : seleccionada = formas::recta;
}

void Game::dibujarForma(const int x1, const int y1, const int x2, const int y2)
{
	switch (seleccionada) {
	case (formas::recta) :
		figs.push_back(std::make_shared<Recta>(Recta(gfx, x1, y1, x2, y2, grosor)));
		break;
	
	case (formas::rectangulo):
		figs.push_back(std::make_shared<Rectangulo>(Rectangulo(x1, y1, x2, y2, gfx)));
		break;
	}
}


void Game::UpdateModel()
{
	double a = 0.18;
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		coche.acelerar(a, 1);
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		coche.acelerar(a, 3);
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		coche.acelerar(a, 0);
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		coche.acelerar(a, 2);
	}
	else {
		coche.decelerar();
	}
	//coche.actualizar_vel();
	if (wnd.kbd.KeyIsPressed(' ')) {
		// Se eliminan todas las figuras
		figs.clear();
	}
	if (wnd.kbd.KeyIsPressed('Q')) {
		cambiarForma(); // Cambiamos seleccion
		if (wnd.mouse.LeftIsPressed()) {
			if (!figs.empty()) figs.pop_back();
			dibujarForma(p.x(), p.y(), wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
		}
	}
	// Raton:
	while (!wnd.mouse.IsEmpty()) { // Se procesa cada evento
		procesarRaton(wnd.mouse.Read());
	}

	coche.mover();
	

}




void Game::ComposeFrame() {
	for (auto& f : figs) {
		f->dibujar();
	}

	coche.dibujar();

}
