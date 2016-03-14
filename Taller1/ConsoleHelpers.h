#pragma once
#include <Windows.h>

int cleanConsole();
int getWitdh();
int getHeight();
int getCursor(int &x, int &y);
int setCursor(int x, int y);
int setTextAttributes(DWORD color);