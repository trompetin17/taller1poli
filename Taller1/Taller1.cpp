// Taller1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>

#include "menu.h"
#include "ConsoleHelpers.h"
#include "Ejercicio_1_5.h"
#include "Ejercicio_2_5.h"
#include "Ejercicio_3_7.h"
#include "Ejercicio_4_5.h"

using namespace std;

int dummy()
{
	return 0;
}

int general()
{
	cleanConsole();
	return 0;
}

int main()
{
	map<int, string> menuTitulos;
	map<int, FnPtr> menuFunciones;

	agregarMenu(menuTitulos, menuFunciones, 1, "Ejercicio 1.5", iniciarEjercicio15);
	agregarMenu(menuTitulos, menuFunciones, 2, "Ejercicio 2.5", iniciarEjercicio25);
	agregarMenu(menuTitulos, menuFunciones, 3, "Ejercicio 3.7", iniciarEjercicio37);
	agregarMenu(menuTitulos, menuFunciones, 4, "Ejercicio 4.5", iniciarEjercicio45);

	pintarMenu(menuTitulos, menuFunciones, general);

	cin.ignore();
    return 0;
}

