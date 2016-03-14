#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <Windows.h>

#include "menu.h"
#include "Ejercicio_4_5.h"
#include "ConsoleHelpers.h"


#define MAX_MATRIZ 5
#define LIMITE_INFERIOR 0
#define LIMIRE_SUPERIOR 500

#define printDato(i, j) printf_s("%3d", matriz[i][j])


using namespace std;

//Se requiere "global" para poder utilizar la funcionalidad de menus
int mt[MAX_MATRIZ][MAX_MATRIZ] = { 0 };
int len = 0;

int pintarEnPosicionYEsperar(int  i, int j, int x, int y, int dato)
{
	setCursor(x + (j * 3) + (2 * ((j == 0) ? 0 : j)), y + i);
	printf_s("%3d", dato);
	
	Sleep(1000);
	return 0;
}

int generarNumeroAleatorio()
{
	return LIMITE_INFERIOR + (rand() % (LIMIRE_SUPERIOR - LIMITE_INFERIOR + 1));
}

int generarMatrizAleatoria(int matriz[][MAX_MATRIZ], int n)
{
	srand((int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matriz[i][j] = generarNumeroAleatorio();
		}
	}
	return 0;
}

int mostrarMatriz(int matriz[][MAX_MATRIZ], int n)
{
	int t = getWitdh();
	int nEspacios = (t/2) - ((n/2)*3*2) ;
	printf_s("\n");
	for (int i = 0; i < n; i++)
	{
		printf_s("%*s", nEspacios, "");
		for (int j = 0; j < n; j++)
		{
			printDato(i, j);
			if (j != n)
			{
				printf_s("  ");
			}
		}

		printf_s("\n");
	}
	printf_s("\n");
	
	return 0;
}

int generalEjercicio45()
{
	mostrarMatriz(mt, len);

	return 0;
}

int mostrarMatrizEspiral(int matriz[][MAX_MATRIZ], int n, bool horario)
{
	int cursorX = 0;
	int cursorY = 0;
	int limInferior = 0;
	int limSuperior = 0;
	int t = getWitdh();
	int x, y;
	int nEspacios = (t / 2) - ((n / 2) * 3 * 2);

	printf_s("\n");

	getCursor(x, y);
	x += nEspacios;

	//calculo el centro de la matriz
	cursorX = cursorY = n / 2;

	limInferior = cursorX - 1;
	limSuperior = cursorY + 1;

	//Imprimo el caracter
	pintarEnPosicionYEsperar(cursorY, cursorX, x, y, matriz[cursorY][cursorX]);

	do
	{
		cursorX -= 1;

		//Imprimo el caracter
		pintarEnPosicionYEsperar(cursorY, cursorX, x, y, matriz[cursorY][cursorX]);

		while ((horario && (cursorY > limInferior)) || (!horario && (limSuperior > cursorY)))
		{
			cursorY += horario ? -1 : 1;

			//Imprimo el caracter
			pintarEnPosicionYEsperar(cursorY, cursorX, x, y, matriz[cursorY][cursorX]);
		}

		while (limSuperior > cursorX)
		{
			cursorX += 1;

			//Imprimo el caracter
			pintarEnPosicionYEsperar(cursorY, cursorX, x, y, matriz[cursorY][cursorX]);
		}

		while ((!horario && (cursorY > limInferior)) || (horario && (limSuperior > cursorY)))
		{
			cursorY += horario ? 1 : -1;

			//Imprimo el caracter
			pintarEnPosicionYEsperar(cursorY, cursorX, x, y, matriz[cursorY][cursorX]);
		}

		while (cursorX > limInferior)
		{
			cursorX -= 1;

			//Imprimo el caracter
			pintarEnPosicionYEsperar(cursorY, cursorX, x, y, matriz[cursorY][cursorX]);
		}

		limInferior -= 1;
		limSuperior += 1;
	} while (limInferior >= 0 && limSuperior < n );

	setCursor(0, y + n);

	printf_s("\n");
	return 0;
}

int mostrarMatrizEspiralHorario()
{
	cleanConsole();
	mostrarMatrizEspiral(mt, len, true);
	cin.ignore();
	cleanConsole();
	return 0;
}

int mostrarMatrizEspiralAntihorario()
{
	cleanConsole();
	mostrarMatrizEspiral(mt, len, false);
	cin.ignore();
	cleanConsole();
	return 0;
}

int iniciarEjercicio45()
{
	map<int, string> menuTitulos;
	map<int, FnPtr> menuFunciones;

	cleanConsole();
	len = 5;
	generarMatrizAleatoria(mt, len);
	mostrarMatriz(mt, len);

	agregarMenu(menuTitulos, menuFunciones, 1, "Mostrar matriz en espiral en sentido horario", mostrarMatrizEspiralHorario);
	agregarMenu(menuTitulos, menuFunciones, 2, "Mostrar matriz en esperial en sentodo anti-horario", mostrarMatrizEspiralAntihorario);
	
	pintarMenu(menuTitulos, menuFunciones, generalEjercicio45);

	return 0;
}