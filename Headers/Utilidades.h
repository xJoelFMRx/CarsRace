#pragma once
#include "iostream"
#include "conio.h"
#include "string"
#define ANCHO_CONSOLA 160
#define ALTO_CONSOLA 40

using namespace System;
using namespace std;

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float RantFloat(float min, float max)
{
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

void Cursor(int x, int y)
{
    Console::SetCursorPosition(x, y);
}