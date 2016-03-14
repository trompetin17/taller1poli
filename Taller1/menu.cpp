#include "stdafx.h"
#include <iostream>
#include "menu.h"

using namespace std;

int pintarMarco(int numeroRepeticiones)
{
	cout << "//";
	for (int i = 0; i < numeroRepeticiones; i++)
	{
		cout << "=";
	}
	cout << "\\\\" << endl;
	return 0;
}

int pintarEncabezado(const char* appName)
{
	int tamanno = strlen(appName);
	pintarMarco(tamanno);
	cout << appName << endl;
	pintarMarco(tamanno);
	return 0;
}


int pintarMenu(map<int, string> titulos, map<int, FnPtr> funciones, FnPtr funcionAlErrarOpcion)
{
	int opcionSeleccionada = -1;
	while (opcionSeleccionada == -1)
	{
		map<int, string>::iterator it;
		for (it = titulos.begin(); it != titulos.end(); it++)
		{
			cout << it->first << ". " << it->second.c_str() << endl;
		}
		cout << "0. Salir" << endl;
		cout << endl << "Seleccione su opcion y presione enter:";

		cin >> opcionSeleccionada;

		cout << endl;

		if (opcionSeleccionada == 0)
			break;

		if (titulos.find(opcionSeleccionada) != titulos.end())
		{
			//se hace el llamado a la funcion
			if (funciones.find(opcionSeleccionada) != funciones.end())
			{
				funciones[opcionSeleccionada]();
			}
		}

		if (funcionAlErrarOpcion)
			funcionAlErrarOpcion();

		opcionSeleccionada = -1;
	}
	return 0;
}