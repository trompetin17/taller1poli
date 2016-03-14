#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <fstream>

#include "ConsoleHelpers.h"
#include "Ejercicio_2_5.h"

#define ARCHIVO_25 "ejercicio25.txt"
#define MAX_ESTUDIANTE 10
#define MAX_ESTUDIANTE_NAME 50
using namespace std;


struct estudiante
{
	char nombre[MAX_ESTUDIANTE_NAME];
	int mes;
	int anno;
	int dia;
	int numeroPersonal;
	char diaSemana[MAX_ESTUDIANTE_NAME];
};

int calcularDiaDeLaSemana(int dia, int mes, int anno, char (&diaSemana)[MAX_ESTUDIANTE_NAME])
{
	int a = (14 - mes) / 12;
	int y = anno - a;
	int m = mes + 12 * a - 2;

	int aDia = (dia + y  + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;
	switch (aDia)
	{
	case 6:
		strcpy_s(diaSemana, "Sabado");
		break;
	case 0:
		strcpy_s(diaSemana, "Domingo");
		break;
	case 1:
		strcpy_s(diaSemana, "Lunes");
		break;
	case 2:
		strcpy_s(diaSemana, "Martes");
		break;
	case 3:
		strcpy_s(diaSemana, "Miercoles");
		break;
	case 4:
		strcpy_s(diaSemana, "Jueves");
		break;
	case 5:
		strcpy_s(diaSemana, "Viernes");
		break;
	}
	return 0;
}

int calcularNumeroPersonal(int dia, int mes, int anno)
{
	char cDia[3] = { 0 };
	char cMes[3] = { 0 };
	char cAnno[5] = { 0 };
	char cBuffer[11] = { 0 };
	
	_itoa_s(dia, cDia, 3, 10);
	_itoa_s(mes, cMes, 3, 10);
	_itoa_s(anno, cAnno, 5, 10);

	strcat_s(cBuffer, cDia);
	strcat_s(cBuffer, cMes);
	strcat_s(cBuffer, cAnno);

	int size = strlen(cBuffer);

	while (size > 1)
	{
		int total = 0;
		int tmp = 0;

		//Sumo lo del dia
		for (int i = 0; i < size; i++)
		{
			char tmpChar[2] = { 0 };
			tmpChar[0] = cBuffer[i];
			tmp = atoi(tmpChar);
			total += tmp;
		}

		//limpio el buffer
		memset(&cBuffer[0], 0, sizeof(cBuffer));

		_itoa_s(total, cBuffer, 11, 10);
		size = strlen(cBuffer);
	}

	return atoi(cBuffer);
}

int leerEstudiantes(estudiante datos[MAX_ESTUDIANTE])
{
	cout << "Leyendo el archivo " << ARCHIVO_25 << endl;
	ifstream fentrada(ARCHIVO_25);
	char input[3] = { 0 };
	char input2[5] = { 0 };
	int contador = 0;
	if (!fentrada.good())
	{
		cout << "No se puedo abrir el archivo " << ARCHIVO_25 << endl;
		cin.get();
		return -1;
	}

	while (!fentrada.eof() && contador < MAX_ESTUDIANTE)
	{
		estudiante tmp = { 0 };

		fentrada.get(tmp.nombre, MAX_ESTUDIANTE_NAME, '#');
		fentrada.get(); //skip #
		fentrada.get(input, 3, '//');
		fentrada.get(); //skip /
		tmp.dia = atoi(input);
		fentrada.get(input, 3, '//');
		fentrada.get(); //skip /
		tmp.mes = atoi(input);
		fentrada.get(input2, 5, '\n');
		fentrada.get(); //skip \n
		tmp.anno = atoi(input2);

		tmp.numeroPersonal = calcularNumeroPersonal(tmp.dia, tmp.mes, tmp.anno);
		calcularDiaDeLaSemana(tmp.dia, tmp.mes, tmp.anno, tmp.diaSemana);
		datos[contador] = tmp;
		contador += 1;
	}


	fentrada.close();

	return contador;
}

int iniciarEjercicio25()
{
	estudiante datos[MAX_ESTUDIANTE] = { 0 };
	int cantidad = leerEstudiantes(datos);
	if (-1 == cantidad)
	{
		cin.get();
		return 0;
	}

	for (int i = 0; i < cantidad; i++)
	{
		int t = strlen(datos[i].nombre);
		printf_s("\n%s%*s%d %02d/%02d/%4d %s", datos[i].nombre, MAX_ESTUDIANTE_NAME - t, "", datos[i].numeroPersonal, datos[i].dia, datos[i].mes, datos[i].anno, datos[i].diaSemana);
	}
	cin.ignore();
	cin.get();
	cleanConsole();
	return 0;
}