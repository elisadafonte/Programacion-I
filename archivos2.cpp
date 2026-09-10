// archivos2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string nombreArchivo = "C:\\Users\\elisa\\OneDrive\\Documentos\\Prueba2.txt";
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        archivo << "Hola mundo con archivos" << endl;
        archivo << "Esta es una prueba de ingreso de datos" << endl;
        archivo.close();
        cout << "Archivo de texto s eha creado exitosamente " <<nombreArchivo<< endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
