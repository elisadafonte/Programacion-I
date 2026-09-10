// Examen final 23- simulacro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAXRESERVAS = 100;

struct Fecha
{
    int dia = 0;
    int mes = 0;
    int anio = 0;
};

struct Reserva
{
    string dni;
    Fecha fecha;
    int numNoches = 0;
    int codigo = 0;
    float precio = 0;
};

struct Agencia
{
    Reserva reserva[MAXRESERVAS];
    int contador = 0;
};

/*
MENU (MOSTRAR INFO DE UNA RESERVA POR SU CODIGO, MOSTRAR RESERVAS, INFOME RESERVAS SEGUN FECHA)
BUSCAR RESERVA (DNI) ------------------------------
CARGAR DATOS
INFORMACION RESERVA
RSERVA EN FECHA????
INFORME GENERAL (MOSTRAR TODO)
INFORME TXT (EN UNA FECHA)
*/

int BuscarDni(Agencia& agencia, string dni, int codigo) {
    for (int i = 0; i < agencia.contador; i++)
    {
        if (dni==agencia.reserva[i].dni && codigo==agencia.reserva[i].codigo)
        {
            return i;
        }
    }
    return -1;
}

void AnadirReserva(Agencia& agencia) {
    if (agencia.contador == MAXRESERVAS)
    {
        cout << endl << "---SE HA ALCANZADO EL MAXIMO DE RESERVAS---" << endl;
    }
    else
    {
        cout << endl << "Ingrese el DNI del huesped: ";
        cin >> agencia.reserva[agencia.contador].dni;
        cout << endl << "Ingrese el fecha de inicio (dia): ";
        cin >> agencia.reserva[agencia.contador].fecha.dia;
        cout << endl << "Ingrese el fecha de inicio (mes): ";
        cin >> agencia.reserva[agencia.contador].fecha.mes;
        cout << endl << "Ingrese el fecha de inicio (anio): ";
        cin >> agencia.reserva[agencia.contador].fecha.anio;
        cout << endl << "Ingrese el numero de noches: ";
        cin >> agencia.reserva[agencia.contador].numNoches;
        cout << endl << "Ingrese el codigo de reserva: ";
        cin >> agencia.reserva[agencia.contador].codigo;
        cout << endl << "Ingrese el precio maximo: ";
        cin >> agencia.reserva[agencia.contador].precio;
        agencia.contador++;
    }
}

void VerReservas(Agencia& agencia) {
    if (agencia.contador == 0)
    {
        cout << endl << "---NO HAY RESERVAS REGISTRADAS---" << endl;
    }
    else
    {
        for (int i = 0; i < agencia.contador; i++)
        {
            cout << endl << "--------------------------------------" << endl;
            cout << endl << "DNI del cliente: " << agencia.reserva[i].dni;
            cout << endl << "Fecha de inicio: " << agencia.reserva[i].fecha.dia<<"/"<< agencia.reserva[i].fecha.mes<<"/"<< agencia.reserva[i].fecha.anio;
            cout << endl << "Numero de noches: " << agencia.reserva[i].numNoches;
            cout << endl << "Codigo: " << agencia.reserva[i].codigo;
            cout << endl << "Precio: " << agencia.reserva[i].precio << endl;
        }
    }
}

void BuscarReserva(Agencia& agencia) {
    string dni;
    int codigo = 0;
    cout << endl << "Ingrese el DNI correspondiente a la reserva que busca: ";
    cin >> dni;
    cout << "Ingrese el codigo de la reserva: ";
    cin >> codigo;
    int coincidentes = BuscarDni(agencia, dni, codigo);
    if (coincidentes==-1)
    {
        cout << endl << "---NO SE HA ENCONTRADO LA RESERVA CON ESE CODIGO Y FECHA---" << endl;
    }
    else
    {
        cout << endl << "--------------------------------------" << endl;
        cout << endl << "DNI del cliente: " << agencia.reserva[coincidentes].dni;
        cout << endl << "Fecha de inicio: " << agencia.reserva[coincidentes].fecha.dia << "/" << agencia.reserva[coincidentes].fecha.mes << "/" << agencia.reserva[coincidentes].fecha.anio;
        cout << endl << "Numero de noches: " << agencia.reserva[coincidentes].numNoches;
        cout << endl << "Codigo: " << agencia.reserva[coincidentes].codigo;
        cout << endl << "Precio: " << agencia.reserva[coincidentes].precio << endl;
        cout << endl << "--------------------------------------" << endl;
    }
}

void Informe(Agencia& agencia) {
    int contadorcitas;
    string nombreArchivo = "Informe Reservas.txt";
    ofstream archivo(nombreArchivo, ios::out);
    int dia = 0;
    int mes = 0;
    int anio = 0;
    cout << endl << "Ingrese el fecha de inicio (dia): ";
    cin >> dia;
    cout << endl << "Ingrese el fecha de inicio (mes): ";
    cin >> mes;
    cout << endl << "Ingrese el fecha de inicio (anio): ";
    cin >> anio;
    if (archivo.is_open())    {
        
        for (int i = 0; i < agencia.contador; i++)
        {
            if (agencia.reserva[i].fecha.dia==dia && agencia.reserva[i].fecha.mes==mes && agencia.reserva[i].fecha.anio==anio)
            {
                archivo << '\n' << "--------------------------." << endl
                 << endl << "DNI del cliente: " << agencia.reserva[i].dni
                 << endl << "Fecha de inicio: " << agencia.reserva[i].fecha.dia << "/" << agencia.reserva[i].fecha.mes << "/" << agencia.reserva[i].fecha.anio
                 << endl << "Numero de noches: " << agencia.reserva[i].numNoches
                 << endl << "Codigo: " << agencia.reserva[i].codigo
                 << endl << "Precio: " << agencia.reserva[i].precio << endl;
            }
        }
        archivo.close();
        cout << endl << "---INFORME DE CITAS EN LA FECHA DADA GENERADO ---" << endl;
    }
    else
    {
        cout << endl << "---NO SE HA PODIDO ABRIR EL ARCHIVO---" << endl;
    }
}

int CargarDatos(Agencia& agencia) {
    string nombreArchivo = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\Reservas.txt";
    ifstream archivo(nombreArchivo);
    int contador=0;
    if (archivo.is_open())
    {
        while (archivo >> agencia.reserva[contador].dni
               >> agencia.reserva[contador].fecha.dia 
               >> agencia.reserva[contador].fecha.mes 
               >> agencia.reserva[contador].fecha.anio 
               >> agencia.reserva[contador].numNoches 
               >> agencia.reserva[contador].codigo 
               >> agencia.reserva[contador].precio) {
            contador++;
        }
        archivo.close();
    }
    else
    {
        cout << endl << "---NO SE HA PODIDO ABRIR EL ARCHIVO---" << endl;
    }    
    return contador;
}

void GuardarDatos(Agencia& agencia) {
    string nombreArchivo = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\Reservas.txt";
    ofstream archivo(nombreArchivo);
    if (archivo.is_open())
    {        
        for (int i = 0; i < agencia.contador; i++)
        {
            archivo << agencia.reserva[i].dni <<
                ' ' << agencia.reserva[i].fecha.dia <<
                ' ' << agencia.reserva[i].fecha.mes <<
                ' ' << agencia.reserva[i].fecha.anio <<
                ' ' << agencia.reserva[i].numNoches <<
                ' ' << agencia.reserva[i].codigo <<
                ' ' << agencia.reserva[i].precio << endl;
        }
        archivo.close();
    }
    else
    {
        cout << endl << "---NO SE HA PODIDO ABRIR EL ARCHIVO---" << endl;
    }
}

void InfGeneral(Agencia& agencia) {
    float precioTotal = 0;
    for (int i = 0; i < agencia.contador; i++)
    {
        precioTotal += agencia.reserva[i].precio;
    }
    float media = precioTotal / agencia.contador;
    float nochesTotal = 0;
    for (int i = 0; i < agencia.contador; i++)
    {
        nochesTotal += agencia.reserva[i].numNoches;
    }
    float mediaNoches = nochesTotal / agencia.contador;
    int reservas2024 = 0;
    for (int i = 0; i < agencia.contador; i++) {
        if (agencia.reserva[i].fecha.anio==2024)
        {
            reservas2024++;
        }
    }
    int reservas2025 = 0;
    for (int i = 0; i < agencia.contador; i++) {
        if (agencia.reserva[i].fecha.anio == 2025)
        {
            reservas2025++;
        }
    }
    int reservas2026 = 0;
    for (int i = 0; i < agencia.contador; i++) {
        if (agencia.reserva[i].fecha.anio == 2026)
        {
            reservas2026++;
        }
    }
    float minPrecio=100000000;
    for (int i = 0; i < agencia.contador; i++)
    {
        if (agencia.reserva[i].precio<minPrecio)
        {
            minPrecio = agencia.reserva[i].precio;
        }
    }
    float maxPrecio=0;
    for (int i = 0; i < agencia.contador; i++)
    {
        if (agencia.reserva[i].precio > maxPrecio)
        {
            maxPrecio = agencia.reserva[i].precio;
        }
    }

    cout << endl << "-----------------------------------------"
        << endl << "              INFORME GENERAL  "
        << endl << "------------------------------------------"
        << endl << "Numero total de reservas: " << agencia.contador
        << endl << "Precio total de todas las reservas: " << precioTotal
        << endl << "Precio promedio por reserva: " << media
        << endl << "Duracion promedio de las reservas: " << mediaNoches
        << endl << "Numero de reservas por anio: "
        << endl << "2024: " << reservas2024
        << endl << "2025: " << reservas2025
        << endl << "2026: " << reservas2026
        << endl << "Precio minimo de una reserva: " << minPrecio
        << endl << "Precio maximo de una reserva: " << maxPrecio
        << endl << "------------------------------------------";
}

void General() {
    int eleccion=-1;
    Agencia agencia;
    agencia.contador = CargarDatos(agencia);
    while (eleccion != 0) {
        cout <<endl<< "----MENU----" << endl
            << "1. ANADIR RESERVA" << endl
            << "2. VER RESERVAS" << endl
            << "3. BUSCAR RESERVA (POR FECHA Y CODIGO)" << endl
            << "4. GENERAR INFORME DE RESERVAS POR FECHA" << endl
            << "5. MOSTRAR INFORME GENERAL"<<endl
            <<"0. SALIR"<<endl;
        cout << "Seleccione una opcion del menu: ";
        cin >> eleccion;
        switch (eleccion)
        {
        case 1: { AnadirReserva(agencia); break; }
        case 2: { VerReservas(agencia); break; }
        case 3: { BuscarReserva(agencia); break; }
        case 4: { Informe(agencia); break; }
        case 5: { InfGeneral(agencia); break; }
        case 0: {
            cout << endl<<"---SE HA SALIDO SEL PROGRAMA CORRECTAMENTE---"<<endl;
            GuardarDatos(agencia);
        }
        }
    }
}



//INFORME GENERAL

int main()
{
    General();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
