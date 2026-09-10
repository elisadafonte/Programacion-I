// Examen Final 23.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Reserva
{
    string dni;
    Fecha fechainicio;
    int numNoches;
    int codigoHabitacion;
    float precio;
};

struct Agencia
{
    Reserva reservas[100];
    int contador;
};

void GuardarArchivo(Agencia& agencia, const string nombreArchivoReservas) {
    ofstream archivo(nombreArchivoReservas);
    if (archivo.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (agencia.reservas[i].dni != "")
            {
                archivo << agencia.reservas[i].dni << " " << agencia.reservas[i].fechainicio.dia << " " << agencia.reservas[i].fechainicio.mes << " " << agencia.reservas[i].fechainicio.anio << " " << agencia.reservas[i].numNoches << " " << agencia.reservas[i].codigoHabitacion << " " << agencia.reservas[i].precio << endl;
            }
        }
        cout << "\n---Se ha creado el archivo con exito---\n";
        archivo.close();
    }
    else {
        cout << "\n---No se ha podido abir el archivo---\n";
    }
}

void CargaDatos(Agencia& agencia, const string nombreArchivoReservas) {
    ifstream archivo(nombreArchivoReservas);
    if (archivo.is_open()) {
        string dni = "";
        Fecha fechaInicio;
        int numNoches = 0;
        int codigoHabitacion = 0;
        float precio = 0;

        int cantidad = 0;
        while (archivo >> dni >> fechaInicio.dia >> fechaInicio.mes >> fechaInicio.anio >> numNoches >> codigoHabitacion >> precio) {
            if (cantidad < 100) {
                agencia.reservas[cantidad].dni = dni;
                agencia.reservas[cantidad].fechainicio = fechaInicio;
                agencia.reservas[cantidad].numNoches = numNoches;
                agencia.reservas[cantidad].codigoHabitacion = codigoHabitacion;
                agencia.reservas[cantidad].precio = precio;
                cantidad++;
            }
            else {
                cout << "\n---Se ha alcanzado el límite máximo de reservas.---\n";
                break;
            }
        }
        archivo.close();
    }
    else {
        cout << "\n---No se ha podido abir el archivo---\n";
    }
}


void AnadirReserva(Agencia& agencia) {
   
    for (int i = 0; i < 100; i++)
    {
        if (agencia.reservas[i].dni != "")
        {
            cout << "\nIngrese su DNI: ";
            cin >> agencia.reservas[i].dni;
            cout << "Ingrese el anio de la reserva: ";
            cin >> agencia.reservas[i].fechainicio.anio;
            cout << "Ingrese el mes (numero) de la reserva: ";
            cin >> agencia.reservas[i].fechainicio.mes;
            cout << "Ingrese el dia de la reserva: ";
            cin >> agencia.reservas[i].fechainicio.dia;
            cout << "Ingrese el numero de noches: ";
            cin >> agencia.reservas[i].numNoches;
            cout << "Ingrese el codigo de la habitacion: ";
            cin >> agencia.reservas[i].codigoHabitacion;
            cout << "Ingrese el precio: ";
            cin >> agencia.reservas[i].precio;
            agencia.contador += 1;
        }
        i = 101;
    }
}

int BuscarReserva(Agencia& agencia) {
    string dni = "";
    cout << "\nIngresar dni de la reserva que busca: ";
    cin >> dni;
    for (int i = 0; i < 100; i++)
    {
        if (dni == agencia.reservas[i].dni)
        {
            return i;
        }
    }
    return -1;
}

int menu() {
    int opcion = 0;

    cout << "\n---MENU PRINCIPAL---";
    cout << "\n1. ANADIR RESERVA";
    cout << "\n2. BUSCAR RESERVA POR CODIGO";
    cout << "\n3. GENERAR INFORME GENERAL";
    cout << "\n4. GENERAR INFORME MENSUAL";
    cout << "\n0. SALIR";
    cout << "\nIngrese una opcion del menu: ";
    cin >> opcion;
    return opcion;
}

void InformacionReserva(Agencia agencia, int resultadoBusqueda) {
    cout << "\n-------------------------------";
    cout << "\nINFORMACION DE LA RESERVA";
    cout << "\nDNI del cliente: " << agencia.reservas[resultadoBusqueda].dni << "\nFecha de inicio: " << agencia.reservas[resultadoBusqueda].fechainicio.dia << " " << agencia.reservas[resultadoBusqueda].fechainicio.mes << " " << agencia.reservas[resultadoBusqueda].fechainicio.anio << "\nNumero de noches: " << agencia.reservas[resultadoBusqueda].numNoches << "\nCodigo de Habitacion: " << agencia.reservas[resultadoBusqueda].codigoHabitacion << "\nPrecio: " << agencia.reservas[resultadoBusqueda].precio << "euros\n" << "--------------------------------" << endl;
}

bool ReservaEnFecha(Agencia agencia, int mesReserva, int anoReserva) {
    for (int i = 0; i < 100; i++)
    {
        if (agencia.reservas[i].fechainicio.anio == anoReserva and agencia.reservas[i].fechainicio.mes == mesReserva)
        {
            cout << "\n---Reserva encontrada---\n";
            return true;
        }
    }
    return false;
}

void InformeGeneral(Agencia agencia) {
    int numeroTotalReservas = 0;
    float precioTotalReservas = 0;
    float precioPromedioReservas = 0;
    float duracionPromedioReservas = 0;
    float precioMinimoReservas = 1000000;
    float precioMaximoReservas = 0;
    int aniosReserva[70];
    float numeroReservasPorAino[80];
    for (int i = 0; i < 100; i++)
    {
        if (agencia.reservas[i].dni != "")
        {
            numeroTotalReservas += 1;
            precioTotalReservas += agencia.reservas[i].precio;
            duracionPromedioReservas += agencia.reservas[i].numNoches;
        }
    }
    for (int i = 1990; i < 2050; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (agencia.reservas[j].fechainicio.anio == i)
            {
                aniosReserva[i] += 1;
            }
        }
    }
    for (int j = 0; j < 100; j++)
    {
        if (agencia.reservas[j].precio > precioMaximoReservas)
        {
            precioMaximoReservas = agencia.reservas[j].precio;
        }
        if (agencia.reservas[j].precio < precioMinimoReservas)
        {
            precioMinimoReservas = agencia.reservas[j].precio;
        }
    }
    duracionPromedioReservas = duracionPromedioReservas / numeroTotalReservas;
    precioPromedioReservas = precioTotalReservas / numeroTotalReservas;
    cout << "\n----------------------";
    cout << "\nINFORME GENERAL";
    cout << "\nNumero total de reservas: " << numeroTotalReservas;
    cout << "\nPrecio total de las reservas: " << precioTotalReservas<<"euros";
    cout << "\nPrecio promedio por reserva: " << precioPromedioReservas << " euros";
    cout << "\nDuracion promedio de las reservas: " << duracionPromedioReservas << " noches";
    cout << "\nNumero de reservas por ano: ";
    for (int i = 0; i < 2050; i++)
    {
        if (aniosReserva[i] != 0)
        {
            cout << "\nAnio " << i << ": " << aniosReserva[i] << " reservas";
        }
    }
    cout << "\nPrecio minimo de una reserva: " << precioMinimoReservas << " euros";
    cout << "\nPrecio minimo de una reserva: " << precioMaximoReservas << " euros";
    cout << "\n--------------------------------------------------";
}

void GenerarInforme(Agencia agencia) {
    string nombreRutaInforme = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF + ADE\\Examen Final 23\\Informe.txt";
    int anio = 0;
    int mes = 0;
    cout << "Introduce el mes: ";
    cin >> mes;
    cout << "Introduce el anio: ";
    cin >> anio;
    cout << "Generando archivo...";
    ofstream archivo(nombreRutaInforme);

    if (archivo.is_open())
    {
        archivo << "Reservas realizadas durante " << mes << "/" << anio << " " << endl;
        for (int i = 0; i < 100; i++)
        {
            if (agencia.reservas[i].dni != "")
            {
                archivo << agencia.reservas[i].dni << ": Reserva de " << agencia.reservas[i].numNoches << " en la habitación " << agencia.reservas[i].codigoHabitacion << ", por " << agencia.reservas[i].precio << " euros." << endl;
            }
        }
        archivo.close();
    }
    else
    {
        cout << "\n---No se ha podido abir el archivo---\n";
    }
}

void ProgramaPrincipal() {
    string nombreArchivoReservas = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\Examen Final 23\\Reservas.txt";
    int eleccion = 0;
    int opcion = -1;
    int resultadoBusqueda = 0;
    Agencia agencia;
    CargaDatos(agencia, nombreArchivoReservas);
    while (opcion != 0)
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            AnadirReserva(agencia);
            break;
        case 2:
            resultadoBusqueda = BuscarReserva(agencia);
            if (resultadoBusqueda == -1)
            {
                cout << endl<<"---NO SE HA ENCONTRADO LA RESERVA---"<<endl;
            }
            else
            {
                InformacionReserva(agencia, resultadoBusqueda);
            }
            break;
        case 3:
            
            InformeGeneral(agencia);
            break;
        case 4:
            GenerarInforme(agencia);
            break;
        }
    }
}

int main()
{
    ProgramaPrincipal();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
