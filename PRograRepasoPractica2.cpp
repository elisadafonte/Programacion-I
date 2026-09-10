// PRograRepasoPractica2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// main.cpp
// Integrantes del equipo: [Nombres aquí]
// Práctica de Conecta 4 - Programación I

#include <iostream>
#include <windows.h> // Para manejar colores en consola
using namespace std;

// Constantes
const int N_FILAS = 6;
const int N_COLUMNAS = 8;

// Tipos de datos
enum Casilla { VACIO = 0, JUGADOR1 = 1, JUGADOR2 = 2 };

struct Tablero {
    Casilla matriz[N_FILAS][N_COLUMNAS];
    int espaciosLibres;
};

// Prototipos de funciones
void inicializaTablero(Tablero& t);
void muestraTablero(const Tablero& t);
bool quedanHuecos(const Tablero& t);
bool columnaLlena(const Tablero& t, int columna);
int ponerFicha(Tablero& t, int columna, Casilla jugador);
bool ganador(const Tablero& t, int fila, int columna, Casilla jugador);
void muestraCharColor(Casilla c);
void juegoConecta4();

// Implementaciones

void muestraCharColor(Casilla c) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (c == JUGADOR1) {
        SetConsoleTextAttribute(hConsole, 6); // Amarillo
        cout << char(4);
        SetConsoleTextAttribute(hConsole, 15); // Blanco
    }
    else if (c == JUGADOR2) {
        SetConsoleTextAttribute(hConsole, 4); // Rojo
        cout << char(4);
        SetConsoleTextAttribute(hConsole, 15); // Blanco
    }
    else {
        cout << " ";
    }
}

void inicializaTablero(Tablero& t) {
    t.espaciosLibres = N_FILAS * N_COLUMNAS;
    for (int i = 0; i < N_FILAS; ++i) {
        for (int j = 0; j < N_COLUMNAS; ++j) {
            t.matriz[i][j] = VACIO;
        }
    }
}

void muestraTablero(const Tablero& t) {
    cout << " ";
    for (int col = 0; col < N_COLUMNAS; ++col) {
        cout << "  " << col + 1 << " ";
    }
    cout << endl;

    for (int fila = 0; fila < N_FILAS; ++fila) {
        cout << char(179); // Borde izquierdo
        for (int col = 0; col < N_COLUMNAS; ++col) {
            cout << " ";
            muestraCharColor(t.matriz[fila][col]);
            cout << " " << char(179); // Separador entre columnas
        }
        cout << endl;
    }
    cout << endl;
}

bool quedanHuecos(const Tablero& t) {
    return t.espaciosLibres > 0;
}

bool columnaLlena(const Tablero& t, int columna) {
    return t.matriz[0][columna] != VACIO;
}

int ponerFicha(Tablero& t, int columna, Casilla jugador) {
    for (int fila = N_FILAS - 1; fila >= 0; --fila) {
        if (t.matriz[fila][columna] == VACIO) {
            t.matriz[fila][columna] = jugador;
            t.espaciosLibres--;
            return fila;
        }
    }
    return -1; // Error: columna llena
}

bool ganador(const Tablero& t, int fila, int columna, Casilla jugador) {
    int dx[] = { 0, 1, 1, 1 }; // Direcciones: vertical, horizontal, diagonal
    int dy[] = { 1, 0, 1, -1 }; // Vertical descendente y diagonales

    for (int d = 0; d < 4; ++d) {
        int cuenta = 1; // Fichas consecutivas

        // Dirección positiva
        for (int step = 1; step < 4; ++step) {
            int x = fila + step * dx[d];
            int y = columna + step * dy[d];
            if (x >= 0 && x < N_FILAS && y >= 0 && y < N_COLUMNAS && t.matriz[x][y] == jugador) {
                cuenta++;
            }
            else {
                break;
            }
        }

        // Dirección negativa
        for (int step = 1; step < 4; ++step) {
            int x = fila - step * dx[d];
            int y = columna - step * dy[d];
            if (x >= 0 && x < N_FILAS && y >= 0 && y < N_COLUMNAS && t.matriz[x][y] == jugador) {
                cuenta++;
            }
            else {
                break;
            }
        }

        if (cuenta >= 4) {
            return true;
        }
    }

    return false;
}

void juegoConecta4() {
    Tablero t;
    inicializaTablero(t);

    Casilla jugadorActual = JUGADOR1;
    bool jugando = true;
    int ganadorID = 0;

    while (jugando && quedanHuecos(t)) {
        muestraTablero(t);
        cout << "Turno del jugador " << (jugadorActual == JUGADOR1 ? "1 (amarillo)" : "2 (rojo)") << endl;

        int columna;
        do {
            cout << "Selecciona una columna (1-" << N_COLUMNAS << "): ";
            cin >> columna;
            columna--; // Ajustar al índice 0
        } while (columna < 0 || columna >= N_COLUMNAS || columnaLlena(t, columna));

        int fila = ponerFicha(t, columna, jugadorActual);

        if (ganador(t, fila, columna, jugadorActual)) {
            ganadorID = (jugadorActual == JUGADOR1 ? 1 : 2);
            jugando = false;
        }

        jugadorActual = (jugadorActual == JUGADOR1) ? JUGADOR2 : JUGADOR1;
    }

    muestraTablero(t);

    if (ganadorID != 0) {
        cout << "¡Jugador " << ganadorID << " ha ganado!\n";
    }
    else {
        cout << "¡Empate! No hay más espacios libres.\n";
    }
}

int main() {
    cout << "¡Bienvenido al juego de Conecta 4!\n";
    cout << "Reglas: conecta 4 fichas seguidas para ganar. ¡Buena suerte!\n";

    char jugarDeNuevo;
    do {
        juegoConecta4();
        cout << "¿Quieres jugar otra vez? (s/n): ";
        cin >> jugarDeNuevo;
    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    cout << "¡Gracias por jugar Conecta 4!\n";
    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
//C:\\Users\\elisa\\OneDrive\\Documentos\\INF + ADE\\6 - Programación I\\Practica3prograRepaso\\jugadores.txt
