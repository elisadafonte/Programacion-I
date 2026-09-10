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

struct Oficial
{
    Deporte deporte[100];
    Deportista deportista[100];
};

void AnadirDeporte(Oficial&oficial, int contadorDeportes) {
    if (contadorDeportes < 100)
    {
        cout << endl << "Ingrese el ID del deporte: ";
        cin >> oficial.deporte[contadorDeportes].id;
        cout << endl << "Ingrese el nombre del deporte: ";
        cin >> oficial.deporte[contadorDeportes].nombre;
        cout << endl << "Ingrese la descripcion del deporte: ";
        getline(cin, oficial.deporte[contadorDeportes].descripcion);
        contadorDeportes++;
        cout << "---Deporte registrado correctamente ---" << endl;
    }
    else
    {
        cout << "---Ha alcanzado el máximo de deportes---";
    }
}

void AnadirDeportista(Oficial& oficial, int contadorDeportistas, int contadorDeportes) {
    if (contadorDeportes < 100)
    {
        cout << endl << "Ingrese el ID del deportista: ";
        cin >> oficial.deportista[contadorDeportistas].id;
        cout << endl << "Ingrese el nombre del deportista: ";
        cin >> oficial.deportista[contadorDeportistas].nombre;
        cout << endl << "Ingrese el apellido del deportista: ";
        cin >> oficial.deportista[contadorDeportistas].apellido;
        cout << endl << "Ingrese la edad del deportista: ";
        cin >> oficial.deportista[contadorDeportistas].edad;

        if (contadorDeportes == 0) {
            AnadirDeporte(oficial, contadorDeportes);
            oficial.deportista[contadorDeportistas].idDeporte = oficial.deporte[0].id;
        }
        else {
            for (int i = 0; i < contadorDeportes; i++) {
                cout << endl << "ID: " << oficial.deporte[i].id;
                cout << endl << "Nombre: " << oficial.deporte[i].nombre;
                cout << endl << "Descripcion: " << oficial.deporte[i].descripcion;
                cout << endl << "--------------------------------------" << endl;
            }
            cout << "Seleccione el deporte introduciendo el ID: ";
            cin >> oficial.deportista[contadorDeportistas].idDeporte;
        };

        contadorDeportistas++;
    }
    else
    {
        cout << "---Ha alcanzado el máximo de deportistas---";
    };
};

void VerDeportes (Oficial& oficial, int contadorDeportes) {
    if (contadorDeportes == 0) {
        cout << "---No hay deportes agregados---";
    }
    else {
        for (int i = 0; i < contadorDeportes; i++) {
            cout << endl << "ID: " << oficial.deporte[i].id;
            cout << endl << "Nombre: " << oficial.deporte[i].nombre;
            cout << endl << "Descripcion: " << oficial.deporte[i].descripcion;
            cout << endl << "--------------------------------------" << endl;
        };
    };
}

void VerDeportistas(Oficial& oficial, int contadorDeportistas) {
    if (contadorDeportistas == 0) {
        cout << "---No hay deportistas agregados---";
    }
    else {
        for (int i = 0; i < contadorDeportistas; i++) {
            cout << endl << "ID: " << oficial.deportista[i].id;
            cout << endl << "Nombre: " << oficial.deportista[i].nombre;
            cout << endl << "Apellido: " << oficial.deportista[i].apellido;
            cout << endl << "Edad: " << oficial.deportista[i].edad;
            cout << endl << "ID Deporte: " << oficial.deportista[i].idDeporte;
            cout << endl << "--------------------------------------" << endl;
        }
    }
}

//UPDATE Y DELETE

int main()
{
    int contadorDeportes = 0;
    int contadorDeportistas = 0;
    int eleccion = -1;
    Oficial oficial;
    string nombreArchivoDeporte = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\27-11-2024(1)\\Deporte.txt";


    while (eleccion != 0) {
        cout << endl << "---MENU---";
        cout << endl << "1. AGREGAR DEPORTE.";
        cout << endl << "2. AGREGAR DEPORTISTA.";
        cout << endl << "3. VER DEPORTES.";
        cout << endl << "4. VER DEPORTISTAS.";
        cout << endl << "5. EDITAR DEPORTE.";
        cout << endl << "6. EDITAR DEPORTISTA.";
        cout << endl << "7. ELIMINAR DEPORTE.";
        cout << endl << "8. ELIMINAR DEPORTISTA.";
        cout << endl << "0. SALIR.";
        cout << endl << "Ingrese una opcion del menu: ";
        cin >>eleccion;
        switch (eleccion)
        {
        case 1: { AnadirDeporte(oficial, contadorDeportes); }
            break;
        case 2: { AnadirDeportista(oficial, contadorDeportistas, contadorDeportes); }
              break;
        case 3: { VerDeportes(oficial, contadorDeportes); }
              break;
        case 4: { VerDeportistas(oficial, contadorDeportistas); }
              break;
        }
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
