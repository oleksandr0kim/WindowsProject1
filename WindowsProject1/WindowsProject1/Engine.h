#pragma once

#include <Windows.h>

// переменный доступные для Main
const int Wind_Width = 960;
const int Wind_Height = 600;

// функции доступные для Main
void Init();
void Draw_Frame(HDC hdc);