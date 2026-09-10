//Practica2 - Carolina Ragni y Elisa Dafonte
//
#include <iostream>
#include <string>
using namespace std;


const int TAREASMAX = 100;

bool ingresarTarea(string tareas[], bool completadas[], int& numTareas) {
    if (numTareas >= TAREASMAX) {
        return false; // PARA QUE NO SE SUPEREN LAS 100 TAREAS
    }
    cout << "Introduce el nombre de la tarea: ";
    cin.ignore();
    getline(cin, tareas[numTareas]);
    completadas[numTareas] = false; // AUTOMATICAMENTE LA TAREA SE PONE COMO PENDIENTE
    numTareas++;
    cout << "Tarea anadida con estado pendiente." << endl;
    return true;
}

void verTareas(string tareas[], bool completadas[], int numTareas) {
    if (numTareas == 0) {
        cout << "No hay tareas agregadas." << endl;
    }
    else
    {
        int eleccion = 0;
        cout << "\n 1. Ver todas las tareas \n 2. Ver las tareas pedientes \n 3. Ver las tareas completadas" << endl;
        cout << "Ingrese la opcion que desee: ";
        cin >> eleccion;

        cout << "\n--- LISTA DE TAREAS ----\n";
        switch (eleccion) {

        case 1: // PARA VER TODAS LAS TAREAS
            for (int i = 0; i < numTareas; i++) {
                cout << (i + 1) << ". " << tareas[i] << " - " << (completadas[i] ? "COMPLETADA" : "PENDIENTE") << endl;
            }
            break;

        case 2: // PARA VER LAS TAREAS PENDEINTES
            for (int i = 0; i < numTareas; i++) {
                if (!completadas[i]) {
                    cout << (i + 1) << ". " << tareas[i] << " - PENDIENTE" << endl;
                }
            }
            break;

        case 3: // PARA VER LAS TAREAS COMPLETADAS
            for (int i = 0; i < numTareas; i++) {
                if (completadas[i]) {
                    cout << (i + 1) << ". " << tareas[i] << " - COMPLETADA" << endl;
                }
            }
            break;

        default:
            cout << "Esa opcion no es valida." << endl;
            break;
        }
        cout << "------------------------\n";
    }

}


void marcarTareaCompletada(bool completadas[], int totalTareas) {
    int numTarea = 0;
    cout << "\n Ingrese el numero de la tarea que quieres marcar como completada: ";
    cin >> numTarea;

    if (numTarea < 1 || numTarea > totalTareas) {
        cout << "\n El numeor ingresado no es valido." << endl;
        return;
    }

    completadas[numTarea - 1] = true; // PARA MARCAR TAREA COMO COMPLETADA
    cout << "Tarea " << numTarea << " marcada como completada." << endl;
}


int buscarTarea(string tareas[], string nombre, int numTareas) {
    for (int i = 0; i < numTareas; i++) {
        if (tareas[i] == nombre) {
            return i;
        }
    }
    return -1;
}


int main() {
    string tareas[TAREASMAX];
    bool completadas[TAREASMAX] = { false };
    int numTareas = 0;
    int eleccion;
    do {
        cout << "--- GESTOR DE TAREAS --- \n 1. INGRESAR TAREA \n 2. VER LAS TAREAS \n 3. MARCAR TAREA COMO COMPLETADA \n 4. BUSCAR TAREA \n 5. SALIR \n";
        cout << "\n Elija una opcion del menu: ";
        cin >> eleccion;


        switch (eleccion) {

        case 1:
            ingresarTarea(tareas, completadas, numTareas);
            break;

        case 2:
            verTareas(tareas, completadas, numTareas);
            break;

        case 3:
            marcarTareaCompletada(completadas, numTareas);
            break;

        case 4: {
            string nombre;
            int coincidentes = 0;

            cout << "Ingrese el nombre de la tarea que desea buscar: ";
            cin.ignore();
            getline(cin, nombre);
            coincidentes = buscarTarea(tareas, nombre, numTareas);
            if (coincidentes != -1) {
                cout << "Tarea encontrada: " << tareas[coincidentes] << " --- " << (completadas[coincidentes] ? "COMPLETADA" : "PENDIENTE") << endl;
            }
            else {
                cout << "No se ha encontrado la tarea." << endl;
            }
            break;
        }
        case 5: //PARA SALIR DEL PROGRAMA
            cout << "Ha salido del programa con exito. " << endl;
            break;

        default:
            cout << "Esa opcion no es valida." << endl;
            break;
        }
        cout << endl;
    } while (eleccion != 5);//POR SI EL NUM Q INTRO NO ES CORRECTO

    return 0;
}

