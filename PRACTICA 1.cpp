//PRACTICA 1 - Elisa Dafonte y Carolina Ragni

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nuevaTarea;

    string tarea1 = "";
    string tarea2 = "";
    string tarea3 = "";

    int eleccion = 0;
    int numTareas = 0;

    cout << "--- GESTOR DE TAREAS --- \n 1. INGRESAR TAREA (escriba directamente el nombre de la tarea) \n 2. VER LAS TAREAS \n 3. MARCAR TAREA COMO COMPLETADA \n 4. ELIMINAR TAREA \n 5. SALIR \n";

    do    
    {       
        cout << "\nElija una opcion del menu: ";
        cin >> eleccion;

        switch (eleccion)
        {
        case 1: // PARA INGRESAR TAREA

            if (numTareas < 3)
            {
                cout << " ";
                getline(cin, nuevaTarea);


                if (numTareas == 0)
                {
                    tarea1 = nuevaTarea;
                }
                else if (numTareas == 1)
                {
                    tarea2 = nuevaTarea;
                }
                else if (numTareas == 2)
                {
                    tarea3 = nuevaTarea;
                    cout << "\n AVISO: ha llegado al limite de tareas -> no podra ingresar mas" << endl;
                }
                numTareas++;
                cout << "\n Tarea ingresada." << endl;
            }
            else
            {
                cout << "No es posible crear mas de tres tareas. LIMITE ALCANZADO. " << endl;
            }
            break;

        case 2: // PARA VER LAS TAREAS
            cout << "\n--- LISTA DE TAREAS ----\n";
            if (numTareas == 0)
            {
                cout << "No hay tareas agregadas.\n";
            }
            else
            {
                cout << "Tareas:\n";
                if (numTareas >= 1)
                {
                    cout << "1. " << tarea1 << endl;
                }
                if (numTareas >= 2)
                {
                    cout << "2. " << tarea2 << endl;
                }
                if (numTareas == 3)
                {
                    cout << "3. " << tarea3 << endl;
                }
            }
            cout << "\n-------------------------------------------\n";
            break;

        case 3: // MARCAR COMO COMPLETA
            if (numTareas == 0)
            {
                cout << "No hay tareas para marcar como completadas.\n";
            }
            else
            {
                int num; //si lo pongo arriba se estropea codigo
                cout << "Introduce el numero de la tarea a marcar como completada (1-" << numTareas << "): ";
                cin >> num;

                if (num == 1 && numTareas >= 1)
                {
                    cout << "\n La tarea ha sido marcada como completada. " << endl;
                    tarea1 = tarea1 + " - COMPLETADA";
                }
                else if (num == 2 && numTareas >= 2)
                {
                    cout << "\n La tarea ha sido marcada como completada. " << endl;
                    tarea2 = tarea2 + " - COMPLETADA";

                }
                else if (num == 3 && numTareas == 3)
                {
                    cout << "\n La tarea ha sido marcada como completada. " << endl;
                    tarea3 = tarea3 + " - COMPLETADA";

                }
                else {
                    cout << "Numero de tarea invalido.\n";
                }
            }
            break;

        case 4: // PARA ELIMINAR
            if (numTareas == 0)
            {
                cout << "No hay tareas para eliminar.\n";
            }
            else
            {
                int num; //si lo pongo arriba se estropea codigo
                cout << "Introduce el numero de la tarea a eliminar (1-" << numTareas << "): ";
                cin >> num;

                if (num == 1 && numTareas >= 1)
                {
                    tarea1 = tarea2;
                    tarea2 = tarea3;
                    numTareas--;
                    cout << "\n La tarea ha sido eliminada. " << endl;
                }
                else if (num == 2 && numTareas >= 2)
                {
                    tarea2 = tarea3;
                    numTareas--;
                    cout << "\n La tarea ha sido eliminada. " << endl;

                }
                else if (num == 3 && numTareas == 3)
                {
                    numTareas--;
                    cout << "\n La tarea ha sido eliminada. " << endl;
                }
                else {
                    cout << "Numero de tarea invalido.\n";
                }
            }
            break;

        case 5: // PARA SALIR
            cout << "\n <<<Ha salido del programa>>> \n";
            break;

        default: //X SI INTRODUCEN UN TADO NO VALIDO (q no sea un num. del 1-5) -----> VUELVE A PREGUNTAR QUE INTRO. DATO
            cout << "Opcion invalida. Por favor, elige una opcion del menu.\n";
            break;
        }
    } while (eleccion != 5); //REPITICION hasta de que "eleccion=5"

    return 0;
}



