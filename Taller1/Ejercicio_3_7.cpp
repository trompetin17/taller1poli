#include "stdafx.h"

#include <iostream>

#include "Ejercicio_3_7.h"

#define MAX_PALABRA36 40

using namespace std;

int iniciarEjercicio37()
{
	char palabra[MAX_PALABRA36];
	int x, a = 0, e = 0, f = 0, i = 0, o = 0, u = 0;
	float n = 0;

	cout << "Ingrese La Frase : ";
	cin.ignore();
	cin.getline(palabra, MAX_PALABRA36, '\n');

	for (x = 0; x < MAX_PALABRA36; x++)
	{

		switch (palabra[x])
		{
		case 'a': a = a + 1; n = n + 1; palabra[x] = '*'; break;
		case 'e': e = e + 1; n = n + 1; palabra[x] = '*'; break;
		case 'i': f = f + 1; n = n + 1; palabra[x] = '*'; break;
		case 'o': o = o + 1; n = n + 1; palabra[x] = '*'; break;
		case 'u': u = u + 1; n = n + 1; palabra[x] = '*'; break;

		}
	}

	cout << "\n Vocal	     Histograma	            Frecuencia \n";
	cout << "  A		"; for (i = 0; i < a; i++) { cout << "*"; }cout << "			" << a / n; cout << "\n";
	cout << "  E		"; for (i = 0; i < e; i++) { cout << "*"; }cout << "			" << e / n; cout << "\n";
	cout << "  I		"; for (i = 0; i < f; i++) { cout << "*"; }cout << "			" << f / n; cout << "\n";
	cout << "  O		"; for (i = 0; i < o; i++) { cout << "*"; }cout << "			" << o / n; cout << "\n";
	cout << "  U		"; for (i = 0; i < u; i++) { cout << "*"; }cout << "			" << u / n; cout << "\n";

	cout << "\n" << palabra << "\n \n";
	cin.ignore();

	return 0;
}