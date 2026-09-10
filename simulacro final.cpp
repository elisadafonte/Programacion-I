// simulacro final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct FechaHora
{
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
};

enum Estado {
    Programada,
    Confirmada, 
    Cancelada
};

struct Cita {
    int id;
    FechaHora fechahora;
    string nombrePac;
    string apellidoPac;
    string especialidad;
    Estado estado;
};

struct Agenda {
    Cita cita[150];
    int contador;
};

string EstadoToString(Estado estado) {
    switch (estado)
    {
    case Programada: { return "PROGRAMADA"; }
        break;
    case Confirmada: { return "CONFIRMADA"; }
        break;
    case Cancelada: { return "CANCELADA"; }
        break;
    default:
        break;
    }
}

Estado StringToEstado(string estadostr) {
    if (estadostr=="PROGRAMADA")
    {
        return Programada;
    }
    if (estadostr=="CONFIRMADA")
    {
        return Confirmada;
    }
    if (estadostr=="CANCELADA")
    {
        return Cancelada;
    }
}

int BuscarId(Agenda& agenda, int idIngresado) {
    for (int i = 0; i < agenda.contador; i++)
    {
        if (idIngresado==agenda.cita[i].id)
        {
            return i;
        }
    }
    return -1;
}

void BuscarCita(Agenda& agenda) {
    int coincidentes;
    int idIngresado;
    cout << endl << "Ingrese el id de la cita que busca: ";
    cin >> idIngresado;
    coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes==-1)
    {
        cout <<endl<< "---NO SE HA ENCONTRADO NINGUNA CITA CON ESE ID---"<<endl;
    }
    else
    {
        cout << endl << "---CITA ENCONTRADA---" << endl;
        cout <<endl<< "-------------------------------------------" << endl;
        cout << "ID: " << agenda.cita[coincidentes].id << endl;
        cout << "Fecha: " << agenda.cita[coincidentes].fechahora.dia<<"/"<< agenda.cita[coincidentes].fechahora.mes<<"/"<< agenda.cita[coincidentes].fechahora.anio << endl;
        cout << "Hora: " << agenda.cita[coincidentes].fechahora.hora<< ":" << agenda.cita[coincidentes].fechahora.minuto << endl;
        cout << "Paciente: " << agenda.cita[coincidentes].apellidoPac<<", "<<agenda.cita[coincidentes].nombrePac << endl;
        cout << "Especialidad: " << agenda.cita[coincidentes].especialidad << endl;
        cout << "Estado: " << EstadoToString(agenda.cita[coincidentes].estado) << endl;
    }
}

void MostrarCitas(Agenda& agenda) {
    if (agenda.contador==0)
    {
        cout << endl << "--- NO HAY CITAS PROGRAMADAS ---" << endl;
    }
    else
    {
        for (int i = 0; i < agenda.contador; i++)
        {
            cout << endl << "-------------------------------------------" << endl;
            cout << "ID: " << agenda.cita[i].id << endl;
            cout << "Fecha: " << agenda.cita[i].fechahora.dia << "/" << agenda.cita[i].fechahora.mes << "/" << agenda.cita[i].fechahora.anio << endl;
            cout << "Hora: " << agenda.cita[i].fechahora.hora << ":" << agenda.cita[i].fechahora.minuto << endl;
            cout << "Paciente: " << agenda.cita[i].apellidoPac << ", " << agenda.cita[i].nombrePac << endl;
            cout << "Especialidad: " << agenda.cita[i].especialidad << endl;
            cout << "Estado: " << EstadoToString(agenda.cita[i].estado) << endl;
        }
    }
}





int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
