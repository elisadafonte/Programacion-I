// PRACTICA 3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int TAREASMAX = 100;

struct Fecha {
    int dia = 0;
    int mes = 0;
    int anio = 0;
};

enum Categoria {
    Trabajo,
    Estudios,
    Hobbies,
    Familia,
    Hogar,
    Social
};

struct Tarea {
    string id;
    string nombre;
    bool estado;
    Fecha fecha;
    Categoria categoria;
};

struct Agenda {
    Tarea tareas[TAREASMAX];
    int numTareas = 0;
};

string CategoriaToString(Categoria categoria) {
    switch (categoria) {
    case Trabajo: return "Trabajo";
    case Estudios: return "Estudios";
    case Hobbies: return "Hobbies";
    case Familia: return "Familia";
    case Hogar: return "Hogar";
    case Social: return "Social";
    default: return "Desconocida";
    }
}

Categoria StringToCategoria( string categoriaStr) {
    if (categoriaStr == "Trabajo") return Trabajo;
    if (categoriaStr == "Estudios") return Estudios;
    if (categoriaStr == "Hobbies") return Hobbies;
    if (categoriaStr == "Familia") return Familia;
    if (categoriaStr == "Hogar") return Hogar;
    return Social;
}

int BuscarId(Agenda& agenda, string idIngresado) {
    for (int i = 0; i < agenda.numTareas; i++) {
        if (idIngresado == agenda.tareas[i].id) {
            return i;
        }
    }
    return -1;
}

void Anadir(Agenda& agenda) {
    if (agenda.numTareas < TAREASMAX) {
        int categoria;
        cout << "Ingrese el ID de la tarea: ";
        cin >> agenda.tareas[agenda.numTareas].id;
        cout <<endl<< "Ingrese la descripcion de la tarea: ";
        cin.ignore();
        getline(cin, agenda.tareas[agenda.numTareas].nombre);
        cout <<endl<< "Ingrese la categoria de la tarea (1.Trabajo, 2.Estudios, 3.Hobbies, 4.Familia, 5.Hogar, 6.Social): ";
        cin >> categoria;
        switch (categoria) {
        case 1: agenda.tareas[agenda.numTareas].categoria = Trabajo; break;
        case 2: agenda.tareas[agenda.numTareas].categoria = Estudios; break;
        case 3: agenda.tareas[agenda.numTareas].categoria = Hobbies; break;
        case 4: agenda.tareas[agenda.numTareas].categoria = Familia; break;
        case 5: agenda.tareas[agenda.numTareas].categoria = Hogar; break;
        case 6: agenda.tareas[agenda.numTareas].categoria = Social; break;
        }
        cout <<endl<< "Ingrese la fecha de la tarea - dia: ";
        cin >> agenda.tareas[agenda.numTareas].fecha.dia;
        cout <<endl<< "Ingrese la fecha de la tarea - mes: ";
        cin >> agenda.tareas[agenda.numTareas].fecha.mes;
        cout <<endl<< "Ingrese la fecha de la tarea - anio: ";
        cin >> agenda.tareas[agenda.numTareas].fecha.anio;
        agenda.tareas[agenda.numTareas].estado = false;
        agenda.numTareas++;
    }
    else {
        cout << endl << " -- HA ALCANZADO EL MAXIMO DE TAREAS -- " << endl;
    }
}

void Ver(Agenda& agenda) {
    int eleccion;
    if (agenda.numTareas == 0) {
        cout << endl << "--- No hay tareas anadidas ---"<<endl;
    }
    else {
        cout << endl<<"Ingrese las tareas que desea ver (1.Todas, 2.Completadas, 3.Pendientes): ";
        cin >> eleccion;
        switch (eleccion) {
        case 1: {
            cout << endl << "---- LISTA DE TAREAS ---- " << endl;
            for (int i = 0; i < agenda.numTareas; i++) {
                cout << i + 1 << ". " << agenda.tareas[i].id << ": " << agenda.tareas[i].nombre << " - " << CategoriaToString(agenda.tareas[i].categoria) << " --- " << agenda.tareas[i].fecha.dia << "/" << agenda.tareas[i].fecha.mes << "/" << agenda.tareas[i].fecha.anio << " --> " << (agenda.tareas[i].estado ? "COMPLETADA" : "PENDIENTE") << endl;
            }
            break;
        }
        case 2: {
            cout << endl << "---- LISTA DE TAREAS COMPLETADAS ---- " << endl;
            for (int i = 0; i < agenda.numTareas; i++) {
                if (agenda.tareas[i].estado==true) {
                    cout << i + 1 << ". " << agenda.tareas[i].id << ": " << agenda.tareas[i].nombre << " - " << CategoriaToString(agenda.tareas[i].categoria) << " --- " << agenda.tareas[i].fecha.dia << "/" << agenda.tareas[i].fecha.mes << "/" << agenda.tareas[i].fecha.anio << " --> COMPLETADA" << endl;
                }
            }
            break;
        }
        case 3: {
            cout << endl << "---- LISTA DE TAREAS PENDIENTES ---- " << endl;
            for (int i = 0; i < agenda.numTareas; i++) {
                if (agenda.tareas[i].estado==false) {
                    cout << i + 1 << ". " << agenda.tareas[i].id << ": " << agenda.tareas[i].nombre << " - " << CategoriaToString(agenda.tareas[i].categoria) << " --- " << agenda.tareas[i].fecha.dia << "/" << agenda.tareas[i].fecha.mes << "/" << agenda.tareas[i].fecha.anio << " --> PENDIENTE" << endl;
                }
            }
            break;
        }
        }
    }
}

void Editar(Agenda& agenda) {
    string idIngresado;
    int eleccion;
    int diaNuevo;
    int mesNuevo;
    int anioNuevo;
    string nombreNuevo;
    int categoriaNueva;
    cout << endl << "Ingrese el ID de la tarea que desea editar: ";
    cin >> idIngresado;
    int coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes == -1) {
        cout <<endl<< "--- No se ha encontrado la tarea. ----"<<endl;
    }
    else {
        cout <<endl<< "Ingrese la opcion que desea editar (1.Descripcion, 2.Fecha, 3.Categoria): ";
        cin >> eleccion;
        switch (eleccion) {
        case 1: {
            cout <<endl<< "Ingrese la nueva descripcion: ";
            cin.ignore();
            getline(cin, nombreNuevo);
            agenda.tareas[coincidentes].nombre = nombreNuevo;
            cout << endl << "--- La descripcion se ha cambiado con exito ---"<<endl;
            break;
        }
        case 2: {
            cout << endl << "Ingrese la nueva fecha - dia: ";
            cin >> diaNuevo;
            agenda.tareas[coincidentes].fecha.dia = diaNuevo;
            cout << endl << "Ingrese la nueva fecha - mes: ";
            cin >> mesNuevo;
            agenda.tareas[coincidentes].fecha.mes = mesNuevo;
            cout << endl << "Ingrese la nueva fecha - anio: ";
            cin >> anioNuevo;
            agenda.tareas[coincidentes].fecha.anio = anioNuevo;
            cout << endl << "--- La fecha se ha cambiado con exito ---"<<endl;
            break;
        }
        case 3: {
            cout << endl << "Ingrese la nueva categoria (1.Trabajo, 2.Estudios, 3.Hobbies, 4.Familia, 5.Hogar, 6.Social): ";
            cin >> categoriaNueva;
            switch (categoriaNueva) {
            case 1: agenda.tareas[coincidentes].categoria = Trabajo; break;
            case 2: agenda.tareas[coincidentes].categoria = Estudios; break;
            case 3: agenda.tareas[coincidentes].categoria = Hobbies; break;
            case 4: agenda.tareas[coincidentes].categoria = Familia; break;
            case 5: agenda.tareas[coincidentes].categoria = Hogar; break;
            case 6: agenda.tareas[coincidentes].categoria = Social; break;
            }
            cout << endl << "--- La categoria se ha cambiado con exito ---"<<endl;
            break;
        }
        }
    }
}

void Completada(Agenda& agenda) {
    string idIngresado;
    cout << endl << "Ingrese el ID de la tarea que desea editar: ";
    cin >> idIngresado;
    int coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes == -1) {
        cout <<endl<< "--- No se ha encontrado la tarea. ----"<<endl;
    }
    else {
        agenda.tareas[coincidentes].estado = true;
        cout <<endl<< "---La tarea se ha marcado como completada con exito ---" << endl;
    }
}

void Buscar(Agenda& agenda) {
    string idIngresado;
    cout << endl << "Ingrese el ID de la tarea que desea buscar: ";
    cin >> idIngresado;
    int coincidentes = BuscarId(agenda, idIngresado);
    if (coincidentes == -1) {
        cout <<endl<< "--- No se ha encontrado la tarea. ----"<<endl;
    }
    else {
        cout <<endl<< "Tarea encontrada:"<<endl;
        cout << agenda.tareas[coincidentes].id << ": " << agenda.tareas[coincidentes].nombre << " - " << CategoriaToString(agenda.tareas[coincidentes].categoria) << " --- " << agenda.tareas[coincidentes].fecha.dia << "/" << agenda.tareas[coincidentes].fecha.anio << endl;
    }
}

int cargarTareas(Agenda& agenda, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int contador = 0;
    if (archivo.is_open()) {
        while (archivo >> agenda.tareas[contador].id >> agenda.tareas[contador].estado
            >> agenda.tareas[contador].fecha.dia >> agenda.tareas[contador].fecha.mes >> agenda.tareas[contador].fecha.anio) {
            string categoriaStr;
            archivo.ignore();
            getline(archivo, agenda.tareas[contador].nombre);
            getline(archivo, categoriaStr);
            agenda.tareas[contador].categoria = StringToCategoria(categoriaStr);
            contador++;
        }
        archivo.close();
    }
    return contador;
}

void guardarTareas(Agenda& agenda, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < agenda.numTareas; i++) {
            archivo << agenda.tareas[i].id << ' ' << agenda.tareas[i].estado << ' '
                << agenda.tareas[i].fecha.dia << ' ' << agenda.tareas[i].fecha.mes << ' '
                << agenda.tareas[i].fecha.anio << '\n' << agenda.tareas[i].nombre << '\n'
                << CategoriaToString(agenda.tareas[i].categoria) << '\n';
        }
        archivo.close();
    }
}

int main() {
    Agenda agenda;
    string nombreArchivo = "C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\PRACTICA 3\\Tareas - PRACTICA 3.txt";
    agenda.numTareas = cargarTareas(agenda, nombreArchivo);
    int eleccion = -1;

    while (eleccion != 0) {
        cout << endl << "--- GESTOR DE TAREAS ---" << endl << "1. ANADIR TAREA" << endl << "2. VER TAREAS" << endl << "3. EDITAR TAREA" << endl << "4. MARCAR TAREA COMO COMPLETADA" << endl << "5. BUSCAR TAREA" << endl << "0. SALIR" << endl;
        cout << "Elija una opcion del menu: ";
        cin >> eleccion;
        switch (eleccion) {
        case 1: { Anadir(agenda); break; };
        case 2: { Ver(agenda); break; };
        case 3: { Editar(agenda); break; };
        case 4: { Completada(agenda); break; };
        case 5: { Buscar(agenda); break; };
        case 0: { cout << "--- Se ha salido del programa con exito ---" << endl; guardarTareas(agenda, nombreArchivo); break; };
        default: cout << "--- OPCION NO VALIDA ---" << endl;
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
