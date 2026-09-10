// Practica3prograRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const int MAX_JUGADORES = 100;
const int FILAS = 6;
const int COLUMNAS = 7;
const char VACIO = ' ';
const char JUGADOR1 = 'X';
const char JUGADOR2 = 'O';

// Estructuras de datos
struct Tablero {
    char matriz[FILAS][COLUMNAS];
    int fichasColumna[COLUMNAS];
};

struct Jugador {
    string nick;
    int partidasGanadas;
    int partidasPerdidas;
};

struct DatosPartida {
    Jugador listaJugadores[MAX_JUGADORES];
    int numJugadores;
};

// Prototipos de funciones
void inicializarTablero(Tablero& t);
void mostrarTablero(const Tablero& t);
bool columnaValida(const Tablero& t, int columna);
bool insertarFicha(Tablero& t, int columna, char ficha);
bool hayGanador(const Tablero& t, char ficha);
bool tableroLleno(const Tablero& t);
Jugador iniciarSesion(DatosPartida& d, string nick);
int buscaJugador(DatosPartida d, string nick);
void cargaDatos(DatosPartida& d);
void muestraInfo(DatosPartida d, string nick);
void infoJugadores(DatosPartida d);
void actualizaJugador(DatosPartida& d, Jugador j);
void guardaJugadorNuevo(DatosPartida& d, Jugador j);
void guardaDatos(DatosPartida d);
void juegoConecta4(Tablero t, Jugador& j, DatosPartida& listaJugadores);
void mostrarMenu();

int main() {
    DatosPartida datos;
    datos.numJugadores = 0;

   
    cargaDatos(datos);

   
    string nick;
    cout << "Introduce tu nick: ";
    getline(cin, nick);

    Jugador jugadorActual = iniciarSesion(datos, nick);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1: 
            guardaDatos(datos);
            cout <<endl<< "--Se ha cerrado el juego con exito---" << endl;
            break;

        case 2: { 
            Tablero tablero;
            inicializarTablero(tablero);
            juegoConecta4(tablero, jugadorActual, datos);
            break;
        }

        case 3: 
            muestraInfo(datos, jugadorActual.nick);
            break;

        case 4: 
            infoJugadores(datos);
            break;

        case 5: { 
            string nickBuscar;
            cout << "Introduce el nick del jugador que busca: ";
            getline(cin, nickBuscar);
            muestraInfo(datos, nickBuscar);
            break;
        }

        default:
            cout <<endl<<"---Opcion no valida---" << endl;
        }
    } while (opcion != 1);

    return 0;
}

void inicializarTablero(Tablero& t) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            t.matriz[i][j] = VACIO;
        }
    }
    for (int j = 0; j < COLUMNAS; j++) {
        t.fichasColumna[j] = 0;
    }
}

void mostrarTablero(const Tablero& t) {
    cout << "\n";
    for (int i = FILAS - 1; i >= 0; i--) {
        cout << "|";
        for (int j = 0; j < COLUMNAS; j++) {
            cout << " " << t.matriz[i][j] << " |";
        }
        cout << "\n";
    }
    cout << " ";
    for (int j = 1; j <= COLUMNAS; j++) {
        cout << " " << j << "  ";
    }
    cout << "\n\n";
}

bool columnaValida(const Tablero& t, int columna) {
    return columna >= 0 && columna < COLUMNAS && t.fichasColumna[columna] < FILAS;
}

bool insertarFicha(Tablero& t, int columna, char ficha) {
    if (!columnaValida(t, columna)) return false;

    t.matriz[t.fichasColumna[columna]][columna] = ficha;
    t.fichasColumna[columna]++;
    return true;
}

bool hayGanador(const Tablero& t, char ficha) {
   
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j <= COLUMNAS - 4; j++) {
            if (t.matriz[i][j] == ficha &&
                t.matriz[i][j + 1] == ficha &&
                t.matriz[i][j + 2] == ficha &&
                t.matriz[i][j + 3] == ficha) {
                return true;
            }
        }
    }


    for (int i = 0; i <= FILAS - 4; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (t.matriz[i][j] == ficha &&
                t.matriz[i + 1][j] == ficha &&
                t.matriz[i + 2][j] == ficha &&
                t.matriz[i + 3][j] == ficha) {
                return true;
            }
        }
    }

    
    for (int i = 0; i <= FILAS - 4; i++) {
        for (int j = 0; j <= COLUMNAS - 4; j++) {
            if (t.matriz[i][j] == ficha &&
                t.matriz[i + 1][j + 1] == ficha &&
                t.matriz[i + 2][j + 2] == ficha &&
                t.matriz[i + 3][j + 3] == ficha) {
                return true;
            }
        }
    }

  
    for (int i = 3; i < FILAS; i++) {
        for (int j = 0; j <= COLUMNAS - 4; j++) {
            if (t.matriz[i][j] == ficha &&
                t.matriz[i - 1][j + 1] == ficha &&
                t.matriz[i - 2][j + 2] == ficha &&
                t.matriz[i - 3][j + 3] == ficha) {
                return true;
            }
        }
    }

    return false;
}

bool tableroLleno(const Tablero& t) {
    for (int j = 0; j < COLUMNAS; j++) {
        if (t.fichasColumna[j] < FILAS) return false;
    }
    return true;
}

Jugador iniciarSesion(DatosPartida& d, string nick) {
    int pos = buscaJugador(d, nick);
    if (pos == -1) {
        Jugador nuevoJugador;
        nuevoJugador.nick = nick;
        nuevoJugador.partidasGanadas = 0;
        nuevoJugador.partidasPerdidas = 0;
        guardaJugadorNuevo(d, nuevoJugador);
        return nuevoJugador;
    }
    return d.listaJugadores[pos];
}

int buscaJugador(DatosPartida d, string nick) {
    for (int i = 0; i < d.numJugadores; i++) {
        if (d.listaJugadores[i].nick == nick) {
            return i;
        }
    }
    return -1;
}

void cargaDatos(DatosPartida& d) {
    ifstream archivo("C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\6 - Programación I\\Practica3prograRepaso\\jugadores.txt");
    if (!archivo.is_open()) {
        d.numJugadores = 0;
        return;
    }

    d.numJugadores = 0;
    while (!archivo.eof() && d.numJugadores < MAX_JUGADORES) {
        Jugador j;
        archivo >> j.nick >> j.partidasGanadas >> j.partidasPerdidas;
        if (!archivo.fail()) {
            d.listaJugadores[d.numJugadores] = j;
            d.numJugadores++;
        }
    }
    archivo.close();
}

void muestraInfo(DatosPartida d, string nick) {
    int pos = buscaJugador(d, nick);
    if (pos == -1) {
        cout <<endl<< "---Jugador no encontrado---" << endl;
        return;
    }

    Jugador j = d.listaJugadores[pos];
    cout << "Nick: " << j.nick << endl;
    cout << "Partidas ganadas: " << j.partidasGanadas << endl;
    cout << "Partidas perdidas: " << j.partidasPerdidas << endl;
}

void infoJugadores(DatosPartida d) {
    if (d.numJugadores == 0) {
        cout << "No hay jugadores registrados" << endl;
        return;
    }

    cout << "\nInformación de todos los jugadores:" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < d.numJugadores; i++) {
        cout << "Nick: " << d.listaJugadores[i].nick << endl;
        cout << "Partidas ganadas: " << d.listaJugadores[i].partidasGanadas << endl;
        cout << "Partidas perdidas: " << d.listaJugadores[i].partidasPerdidas << endl;
        cout << "--------------------------------" << endl;
    }
}

void actualizaJugador(DatosPartida& d, Jugador j) {
    int pos = buscaJugador(d, j.nick);
    if (pos != -1) {
        d.listaJugadores[pos] = j;
    }
}

void guardaJugadorNuevo(DatosPartida& d, Jugador j) {
    if (d.numJugadores >= MAX_JUGADORES) {
        cout <<endl<<"---No se pueden registrar más jugadores---" << endl;
        return;
    }
    d.listaJugadores[d.numJugadores] = j;
    d.numJugadores++;
}

void guardaDatos(DatosPartida d) {
    ofstream archivo("C:\\Users\\elisa\\OneDrive\\Documentos\\INF+ADE\\6 - Programación I\\Practica3prograRepaso\\jugadores.txt");
    if (!archivo.is_open()) {
        cout << "---Error al guardar los datos---" << endl;
        return;
    }

    for (int i = 0; i < d.numJugadores; i++) {
        archivo << d.listaJugadores[i].nick << " "
            << d.listaJugadores[i].partidasGanadas << " "
            << d.listaJugadores[i].partidasPerdidas << endl;
    }
    archivo.close();
}

void juegoConecta4(Tablero t, Jugador& j, DatosPartida& listaJugadores) {
    char fichaJugador = JUGADOR1;
    char fichaMaquina = JUGADOR2;
    bool turnoJugador = true;

    while (true) {
        mostrarTablero(t);

        if (turnoJugador) {
            int columna;
            do {
                cout << "Introduce columna (1-7): ";
                cin >> columna;
                columna--; // Ajustar a índice 0-based
            } while (!columnaValida(t, columna) || !insertarFicha(t, columna, fichaJugador));

            if (hayGanador(t, fichaJugador)) {
                mostrarTablero(t);
                cout << endl<<"---HAS GANADO---" << endl;
                j.partidasGanadas++;
                break;
            }
        }
        else {
            // Estrategia simple para la máquina: elegir columna aleatoria
            int columna;
            do {
                columna = rand() % COLUMNAS;
            } while (!columnaValida(t, columna));

            insertarFicha(t, columna, fichaMaquina);
            cout << "La maquina elige la columna " << columna + 1 << endl;

            if (hayGanador(t, fichaMaquina)) {
                mostrarTablero(t);
                cout <<endl<< "---HAS PERDIDO---" << endl;
                j.partidasPerdidas++;
                break;
            }
        }

        if (tableroLleno(t)) {
            mostrarTablero(t);
            cout <<endl<< "--HABEIS EMPATADO---" << endl;
            break;
        }

        turnoJugador = !turnoJugador;
    }

    actualizaJugador(listaJugadores, j);
}

void mostrarMenu() {
    cout << "\nMENU:" << endl;
    cout << "1. SALIR" << endl;
    cout << "2. JUGAR" << endl;
    cout << "3. VER MI INFORMACION" << endl;
    cout << "4. VER LA INFORMACION DE LOS USUARIOS REGISTRADOS" << endl;
    cout << "5. BUSCAR A UN JUGADOR" << endl;
    cout << "Elige una opción: ";
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
