#pragma once
#include "Utilidades.h"

class Coche
{
private:
	float x;
	float y;
	float dx;
	int color;
	float velocidad;
	int modelo;

public:
	Coche();
	Coche(float x, float y, int modelo);
	void BorrarCoche();
	void MoverCoche();
	void DibujarCoche();
	bool LlegarMeta();
};

Coche::Coche()
{
	x = 1;
	y = 5;
	dx = 1;
	color = RandInt(1, 15);
	velocidad = RantFloat(0.1, 1);
	modelo = 1;
}

Coche::Coche(float x, float y, int modelo)
{
	this->x = x;
	this->y = y;
	this->modelo = modelo;
	color = RandInt(1, 15);
	dx = 1;
	velocidad = RantFloat(0.1, 1);
}

void::Coche::BorrarCoche()
{
	switch (modelo)
	{
	case 1:
		Cursor(x, y);
		cout << "           ";
		Cursor(x, y + 1);
		cout << "               ";
		Cursor(x, y + 2);
		cout << "               ";
		break;
	case 2:
		Cursor(x, y);
		cout << "            ";
		Cursor(x, y + 1);
		cout << "               ";
		Cursor(x, y + 2);
		cout << "                ";
		break;
	case 3:
		Cursor(x, y);
		cout << "             ";
		Cursor(x, y + 1);
		cout << "              ";
		Cursor(x, y + 2);
		cout << "               ";
		break;
	}
}

void::Coche::MoverCoche()
{
	x += velocidad * dx;
}

void::Coche::DibujarCoche()
{
	Console::ForegroundColor = ConsoleColor(color);
	switch (modelo)
	{
	case 1:
		Cursor(x, y);
		cout << " __/  |_\\_";
		Cursor(x, y + 1);
		cout << "|  _     _``-.";
		Cursor(x, y + 2);
		cout << "'-(_)---(_)--'";
		break;
	case 2:
		Cursor(x, y);
		cout << " _.-.___\\__";
		Cursor(x, y + 1);
		cout << "|  _      _`-.";
		Cursor(x, y + 2);
		cout << "'-(_)----(_)--`";
		break;
	case 3:
		Cursor(x, y);
		cout << " ____/   ___";
		Cursor(x, y + 1);
		cout << "|_   \\__'  _\\";
		Cursor(x, y + 2);
		cout << " `-(*)----(*)'";
		break;
	}
	Console::ResetColor();
}

bool Coche::LlegarMeta()
{
	return x >= ANCHO_CONSOLA - 15;
}