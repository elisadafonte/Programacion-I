// practica 1 simulacro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numeros[50];
	for (int i = 0; i < 50; i++)
	{
		numeros[i] = rand();
	}
	cout << "Los numeros contenidos en el array son: {";
	for (int i = 0; i < 50; i++)
	{
		cout << numeros[i] << ", ";
	}
	cout << "}";
	int max=-4;
	for (int i = 0; i < 50; i++)
	{
		
		if (numeros[i] > max) {
			max = numeros[i];
		}		
	}
	cout << endl << "El numero mas alto del array es: " << max;
	int min = 100000;
	for (int i = 0; i < 50; i++)
	{
		if (numeros[i] < min) {
			min = numeros[i];
		}
	}
	
	cout << endl << "El numero mas bajo del array es: " << min;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
