#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>

#include "Ejercicio_1_5.h"
#include "ConsoleHelpers.h"
#include "menu.h"

#define MAX_CARACTERES 25
#define ARCHIVO_15 "ejercicio15.txt"
#define MIN_MATRIZ15 1
#define MAX_MATRIZ15 10

using namespace std;

//Se usa esta variable global para utilizar la funcionalidad de menu de manera general
char texto[MAX_CARACTERES] = { 0 };
int len15 = 0;

int generalEjercicio15()
{
	cleanConsole();
	cout << endl << "Seleccione como mostrar el texto leido del archivo" << endl << endl;

	return 0;
}

int leerArchivoConTexto() {
	ifstream fentrada(ARCHIVO_15);

	if (!fentrada.good())
	{
		cout << "No se puedo abrir el archivo " << ARCHIVO_15 << endl;
		cin.get();
		return 1;
	}

	fentrada.get(texto, MAX_CARACTERES);
	len15 = strlen(texto);


	fentrada.close();

	return 0;
}

int mostrarHorizontal()
{
	int t = getWitdh();
	int nEspacios = (t / 2) - (len15 / 2);

	cleanConsole();
	setTextAttributes(FOREGROUND_RED);
	printf_s("\n%*s%s", nEspacios, "", texto);
	setTextAttributes(15);


	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int mostrarDiagonal()
{
	int t = getWitdh();
	int nEspacios = 0;

	cleanConsole();
	setTextAttributes(FOREGROUND_BLUE);

	for (int i = 0; i < len15; i++)
	{
		printf_s("\n%*s%c", nEspacios, "", texto[i]);
		nEspacios += 1;
		if (nEspacios > t)
		{
			nEspacios = 0;
		}
	}

	setTextAttributes(15);
	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int mostrarTriangulo()
{
	srand((int)time(NULL));
	DWORD color = FOREGROUND_BLUE + (rand() % (FOREGROUND_INTENSITY - FOREGROUND_BLUE + 1));
	cleanConsole();

	for (int i = 0; i < len15; i++)
	{
		setTextAttributes(color);
		for (int j = 0; j <= i; j++)
		{
			printf_s("%c", texto[j]);
		}
		printf_s("\n");
		color = FOREGROUND_BLUE + (rand() % (FOREGROUND_INTENSITY - FOREGROUND_BLUE + 1));
	}

	setTextAttributes(15);
	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int mostrarVertical()
{
	int mid = getWitdh() / 2;
	cleanConsole();

	for (int i = 0; i < len15; i++)
	{
		printf_s("\n%*s%c", (mid - 1), "", texto[i]);
		Sleep(500);
	}

	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int mostrarLocamente()
{
	int maxX = getWitdh();
	int maxY = maxX / 4;
	int x, y = 0;
	srand((int)time(NULL));
	cleanConsole();

	for (int i = 0; i < len15; i++)
	{
		x = 0 + (rand() % (maxX - 0 + 1));
		y = 0 + (rand() % (maxY - 0 + 1));
		setCursor(x, y);
		printf_s("%c", texto[i]);
	}

	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int mostrarCaminando()
{
	int maxX = getWitdh();
	int maxY = maxX / 4;
	
	for (int i = 0; i < maxY; i++)
	{
		for (int j = 0; j < (maxX - len15); j++)
		{
			cleanConsole();
			setCursor(j, i);
			printf_s("%s", texto);
			Sleep(2);
		}
	}

	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int mostrarEnMatriz()
{
	int n = 0;
	int split = 0;
	while (n < MIN_MATRIZ15 || n > MAX_MATRIZ15)
	{
		cleanConsole();
		cout << "Especifique n para mostrar el texto:" << endl;
		cin.ignore();
		cin >> n;
	}
	
	split = (len15 / n) + 1;

	for (int i = 0; i < len15; i++)
	{
		printf_s("%c", texto[i]);
		if (((i + 1) % split) == 0)
		{
			printf_s("\n");
		}
	}

	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}

int iniciarEjercicio15()
{
	map<int, string> menuTitulos;
	map<int, FnPtr> menuFunciones;

	cleanConsole();

	if (0 != leerArchivoConTexto())
	{
		cin.get();
		return 0;
	}

	agregarMenu(menuTitulos, menuFunciones, 1, "Horizontal en la mitad de la pantalla de color rojo", mostrarHorizontal);
	agregarMenu(menuTitulos, menuFunciones, 2, "En diagonal de color azul", mostrarDiagonal);
	agregarMenu(menuTitulos, menuFunciones, 3, "En triangulo de varios colores", mostrarTriangulo);
	agregarMenu(menuTitulos, menuFunciones, 4, "Vertical en la mitad de la pantalla cayendo lentamente", mostrarVertical);
	agregarMenu(menuTitulos, menuFunciones, 5, "Locamente", mostrarLocamente);
	agregarMenu(menuTitulos, menuFunciones, 6, "Cayendose", mostrarCaminando);
	agregarMenu(menuTitulos, menuFunciones, 7, "En una matriz de n filas", mostrarEnMatriz);

	pintarMenu(menuTitulos, menuFunciones, generalEjercicio15);

	return 0;
}