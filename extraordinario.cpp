// extraordinario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAXCITAS = 150;

struct FechaHora
{
    int dia = 0;
    int mes = 0;
    int anio = 0;
    int hora = 0;
    int min = 0;
};

enum Estado
{
    Programada, Confirmada, Cancelada
};

struct Cita
{
    int id = 0;
    FechaHora fechahora;
    string nombrePaciente;
    string apellidoPaciente;
    string especialidad;
    Estado estado;
};

struct Agenda
{
    Cita cita[MAXCITAS];
    int contador = 0;
};

string EstadoToString(Estado estado) {
    switch (estado) {
    case Programada: return "Programada";break;
    case Confirmada: return "Confirmada";break;
    case Cancelada: return "Cancelada"; break;

    }
}

Estado StringToEstado(string strEstado) {
    if (strEstado == "Programada") {
        return Programada;}
    if (strEstado == "Confirmada") {
        return Confirmada;
    }
    if (strEstado == "Cancelada") {
        return Cancelada;
    }
}

int BuscarId(Agenda& agenda, int idIngresado) {
    for (int i = 0; i < agenda.contador; i++)
    {
        if (agenda.cita[i].id == idIngresado)
        {
            return i;
        }
    }
    return -1;
}

void BuscarCita(Agenda& agenda) {
    int idIngresado;
    cout << "Ingrese el ID de la cita que busca: ";
    cin >> idIngresado;
    int coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes==-1)
    {
        cout <<endl<< "---No se encontro ninguna cita con ese ID.---"<<endl;
    }
    else
    {
        cout << "Cita encontrada:" << endl << "ID: " << agenda.cita[coincidentes].id << endl;
        cout << "Fecha y Hora: " << agenda.cita[coincidentes].fechahora.dia << "/" << agenda.cita[coincidentes].fechahora.mes << "/" << agenda.cita[coincidentes].fechahora.anio << " " << agenda.cita[coincidentes].fechahora.hora << ":" << agenda.cita[coincidentes].fechahora.min<<endl;
        cout << "Paciente: " << agenda.cita[coincidentes].nombrePaciente << agenda.cita[coincidentes].apellidoPaciente<<endl;
        cout << "Especialidad: " << agenda.cita[coincidentes].especialidad << endl;
        cout << "Estado: " << EstadoToString(agenda.cita[coincidentes].estado);
    }
}

void MostrarCitas(Agenda& agenda) {
    if (agenda.contador==0)
    {
        cout <<endl<< "---No hay citas programadas---"<<endl;
    }
    else
    {
        for (int i = 0; i < agenda.contador; i++)
        {
            cout<<endl<< "ID: " << agenda.cita[i].id << endl;
            cout << "Fecha y Hora: " << agenda.cita[i].fechahora.dia << "/" << agenda.cita[i].fechahora.mes << "/" << agenda.cita[i].fechahora.anio << " " << agenda.cita[i].fechahora.hora << ":" << agenda.cita[i].fechahora.min << endl;
            cout << "Paciente: " << agenda.cita[i].nombrePaciente<<" " << agenda.cita[i].apellidoPaciente << endl;
            cout << "Especialidad: " << agenda.cita[i].especialidad << endl;
            cout << "Estado: " << EstadoToString(agenda.cita[i].estado) << endl;
            cout << "-----------------------------------" << endl;
        }
    }
}

void AgregarCita(Agenda& agenda) {
    cout<<"Ingrese el ID: ";
    cin >> agenda.cita[agenda.contador].id;
    cout << "Ingrese la fecha (dia): ";
    cin >> agenda.cita[agenda.contador].fechahora.dia;
    cout << "Ingrese la fecha (mes): ";
    cin >> agenda.cita[agenda.contador].fechahora.mes;
    cout << "Ingrese la fecha (anio): ";
    cin >> agenda.cita[agenda.contador].fechahora.anio;
    cout << "Ingrese la hora (hh): ";
    cin >> agenda.cita[agenda.contador].fechahora.hora;
    cout << "Ingrese la hora (mm): ";
    cin >> agenda.cita[agenda.contador].fechahora.min;
    cout << "ingres el nombre del paciente: ";
    cin >> agenda.cita[agenda.contador].nombrePaciente;
    cout << "Ingrese el apellido del paciente: ";
    cin >> agenda.cita[agenda.contador].apellidoPaciente;
    cout << "Ingrese la especialidad: ";
    cin >> agenda.cita[agenda.contador].especialidad;
    agenda.cita[agenda.contador].estado = Programada;
    agenda.contador++;
    cout <<endl<< "---Se ha ingresado la cita con exito---" << endl;
}

void ConfirmarCita(Agenda& agenda) {
    int idIngresado;
    cout << "Ingrese el ID de la tarea que desea confirmar: ";
    cin >> idIngresado;
    int coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes==-1)
    {
        cout <<endl<< "---No se ha encontrado ninuguna tarea con ese ID---"<<endl;
    }
    else
    {
        agenda.cita[coincidentes].estado = Confirmada;
        cout <<endl<< "---El estado se ha cambiado a Confirmada con exito ---" << endl;
    }
}

void CancelarCita(Agenda& agenda) {
    int idIngresado;
    cout << "Ingrese el ID de la tarea que desea cancelar: ";
    cin >> idIngresado;
    int coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes == -1)
    {
        cout <<endl<< "---No se ha encontrado ninuguna tarea con ese ID---"<<endl;
    }
    else
    {
        agenda.cita[coincidentes].estado = Cancelada;
        cout <<endl<< "---El estado se ha cambiado a Cancelada con exito ---" << endl;
    }
}

void Informe (string nombreArchivo, Agenda& agenda) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < agenda.contador; i++) {
            if (agenda.cita[i].estado == Cancelada) {
                archivo << "ID: " << agenda.cita[i].id << endl
                    << "Fecha y Hora: " << agenda.cita[i].fechahora.dia << "/"
                    << agenda.cita[i].fechahora.mes << "/"
                    << agenda.cita[i].fechahora.anio << " "
                    << agenda.cita[i].fechahora.hora << ":"
                    << agenda.cita[i].fechahora.min << endl
                    << "Paciente: " << agenda.cita[i].nombrePaciente << " "
                    << agenda.cita[i].apellidoPaciente << endl
                    << "Especialidad: " << agenda.cita[i].especialidad << endl
                    << "Estado: " << EstadoToString(agenda.cita[i].estado) << endl
                    << "-----------------------------------" << endl;
            }
        }
        archivo.close();
        cout <<endl<< "---Informe de citas canceladas se ha generado correctamente. ---" << endl;
    }
    else {
        cout << endl<<"---No se pudo abrir el archivo para generar el informe.---" << endl;
    }
}

void GuardarAgenda(string nombreArchivo, Agenda& agenda) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < agenda.contador; i++) {
            archivo << agenda.cita[i].id << " "
                << agenda.cita[i].fechahora.dia << " "
                << agenda.cita[i].fechahora.mes << " "
                << agenda.cita[i].fechahora.anio << " "
                << agenda.cita[i].fechahora.hora << " "
                << agenda.cita[i].fechahora.min << " "
                << agenda.cita[i].nombrePaciente << " "
                << agenda.cita[i].apellidoPaciente << " "
                << agenda.cita[i].especialidad << " "
                << EstadoToString(agenda.cita[i].estado) << endl;
        }
        archivo.close();
        cout <<endl<< "---Agenda guardada correctamente.---" << endl;
    }
    else {
        cout <<endl<< "--- No se pudo abrir el archivo para guardar la agenda. ---" << endl;
    }
}

    int CargarAgenda(Agenda & agenda, const string & nombreArchivo) {
        ifstream archivo(nombreArchivo);
        int contador = 0;
        if (archivo.is_open()) {
            while (archivo >> agenda.cita[contador].id
                >> agenda.cita[contador].fechahora.dia
                >> agenda.cita[contador].fechahora.mes
                >> agenda.cita[contador].fechahora.anio
                >> agenda.cita[contador].fechahora.hora
                >> agenda.cita[contador].fechahora.min
                >> agenda.cita[contador].nombrePaciente
                >> agenda.cita[contador].apellidoPaciente
                >> agenda.cita[contador].especialidad) {
                string strEstado;
                archivo >> strEstado;
                agenda.cita[contador].estado = StringToEstado(strEstado);
                contador++;
            }
            archivo.close();
        }
        else {
            cout <<endl<< "---No se pudo abrir el archivo para cargar la agenda.---" << endl;
        }
        return contador;
    }



int main()
{
    string nombreArchivo = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\agenda.txt";
    string nombreArchivo2 = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\informe.txt";
    Agenda agenda;
    agenda.contador = CargarAgenda(agenda, nombreArchivo);
    int eleccion=-1;
    while (eleccion != 0) {
        cout <<endl<< "------MENU-----";
        cout <<endl<< "1. MOSTRAR INFO DE UNA CITA.";
        cout <<endl<< "2. MOSTRAR LISTADO DE CITAS.";
        cout <<endl<< "3. AGREGAR CITA.";
        cout <<endl<< "4. CONFIRMAR CITA.";
        cout <<endl<< "5. CANCELAR CITA.";
        cout <<endl<< "6. GENERAR INFORME DE CITAS CANCELADAS.";
        cout <<endl<< "0. SALIR.";
        cout <<endl<< "Ingrese la opcion que desea: ";
        cin >> eleccion;
        switch (eleccion)
        {
        case 1: {
            BuscarCita(agenda);
            break;
        }
        case 2: {
            MostrarCitas(agenda);
            break;
        }
        case 3: {
            AgregarCita(agenda);
            break;
        }
        case 4: {
            ConfirmarCita(agenda);
            break;
        }
        case 5: {
            CancelarCita(agenda);
            break;
        }
        case 6: {
            Informe(nombreArchivo2, agenda);
            break;
        }
        case 0: {
            cout << "--salio del programa con exito---";
            GuardarAgenda(nombreArchivo, agenda);
            break;
        }
        }
        if (eleccion>6)
        {
            cout << endl<<"OPCION NO VALIDA, PORFAVOR SELECCIONE UNA OPCION DEL MENU."<<endl;
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
