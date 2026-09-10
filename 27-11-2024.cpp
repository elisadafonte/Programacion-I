// 27-11-2024.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Deporte
{
    int id = 0;
    string nombre;
    string descripcion;
};

struct Deportista
{
    int id = 0;
    string nombre;
    string apellido;
    int edad = 0;
    int idDeporte = 0;
};

void AnadirDeporte(Deporte&deporte, int contadorDeportes) {
    if (contadorDeportes < 100)
    {
        cout << endl << "Ingrese el ID del deporte: ";
        cin >> deporte[contadorDeportes].id;
        cout << endl << "Ingrese el nombre del deporte: ";
        cin >> deporte[contadorDeportes].nombre;
        cout << endl << "Ingrese la descripcion del deporte: ";
        getline(cin, deporte[contadoreDeportes].descripcion);
        contadorDeportes++;
        cout << "---Deporte registrado correctamente ---"<<endl;
    }
    else
    {
        cout << "---Ha alcanzado el máximo de deportes---";
    }
}

void AnadirDeportista(Deportista& deportista, int contadorDeportistas, Deporte&deporte, int contadorDeportes) {
    if (contadorDeportes < 100)
    {
        cout << endl << "Ingrese el ID del deportista: ";
        cin >> deporte.producto[contadorDeportistas].id;
        cout << endl << "Ingrese el nombre del deportista: ";
        cin >> deporte[contadorDeportistas].nombre;
        cout << endl << "Ingrese el apellido del deportista: ";
        cin>>deporte[contadorDeportoistas].apellido;
        cout << endl << "Ingrese la edad del deportista: ";
        cin >> deportista[contadorDeportistas].edad;
        
        if (contadorDeportes == 0) {
            AnadirDeporte(deporte, contadorDeportes);
            deportista[contadorDeportistas].idDeporte = deporte[0].id;
        }
        else {
            for (int i = 0, i < contadorDeportes, i++) {
                cout << endl << "ID: " << deporte[i].id;
                cout << endl << "Nombre: " << deporte[i].nombre;
                cout << endl << "Descripcion: " << deporte[i].descripcion;
                cout << endl << "--------------------------------------"<<endl;
            }
            cout << "Seleccione el deporte introduciendo el ID: ";
            cin >> deportista[contadorDeportistas].idDeporte;
        }

        contadorDeportistas++;
    }
    else
    {
        cout << "---Ha alcanzado el máximo de deportistas---";
    }
}

int main()
{
    string nombreArchivoDeporte = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\27-11-2024(1)\\Deporte.txt";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
