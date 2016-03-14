#pragma once
#include <map>
using namespace std;

typedef int (*FnPtr)();


int pintarMarco(int numeroRepeticiones);
int pintarEncabezado(const char* appName);

int pintarMenu(map<int, string> titulos, map<int, FnPtr> funciones, FnPtr funcionAlErrarOpcion);

#define agregarMenu(titulos, funciones, indice, titulo, funcion) \
	titulos[indice] = titulo; \
	funciones[indice] = funcion;