#include "stdafx.h"
#include "ConsoleHelpers.h"
#include <Windows.h>

#define ConsoleInfo HANDLE hOut; \
		CONSOLE_SCREEN_BUFFER_INFO csbi;\
		hOut = GetStdHandle(STD_OUTPUT_HANDLE); \
		if (hOut == INVALID_HANDLE_VALUE) return 0; \
		if (!GetConsoleScreenBufferInfo(hOut, &csbi)) return 0; 

int cleanConsole()
{
	DWORD count;
	DWORD cellCount;
	COORD coords = { 0,0 };

	ConsoleInfo;

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(hOut, (TCHAR)' ', cellCount, coords, &count)) return 0;

	if (!FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, coords, &count)) return 0;

	SetConsoleCursorPosition(hOut, coords);
	return 0;
}

int getWitdh()
{
	ConsoleInfo;
	return csbi.dwSize.X;
}

int getCursor(int &x, int &y)
{
	ConsoleInfo;
	x = csbi.dwCursorPosition.X;
	y = csbi.dwCursorPosition.Y;
	return 0;
}

int setCursor(int x, int y)
{
	ConsoleInfo;
	COORD coords = { x, y };
	SetConsoleCursorPosition(hOut, coords);
	return 0;
}

int setTextAttributes(DWORD color) 
{
	ConsoleInfo;
	SetConsoleTextAttribute(hOut, color);
}

int getHeight()
{
	ConsoleInfo;
	return csbi.dwSize.Y;
}