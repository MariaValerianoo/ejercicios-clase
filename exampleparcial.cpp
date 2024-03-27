#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Clase base Videojuego
class Videojuego {
protected:
    string nombre;
    int cantidadJugadores;
    vector<string> categorias;
    string desarrollador;
    int anoLanzamiento;
    string plataforma;

public:
    Videojuego(const string& nombre, int cantidadJugadores, const vector<string>& categorias,
                const string& desarrollador, int anoLanzamiento, const string& plataforma)
        : nombre(nombre), cantidadJugadores(cantidadJugadores), categorias(categorias),
        desarrollador(desarrollador), anoLanzamiento(anoLanzamiento), plataforma(plataforma) {}

    // Funciones virtuales puras
    virtual void jugar() = 0;
    virtual void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad de jugadores: " << cantidadJugadores << endl;
        cout << "Categorías: ";
        for (const auto& categoria : categorias) {
            cout << categoria << ", ";
        }
        cout << endl;
        cout << "Desarrollador: " << desarrollador << endl;
        cout << "Año de lanzamiento: " << anoLanzamiento << endl;
        cout << "Plataforma: " << plataforma << endl;
    }
};

// Clase hija Juego1
class Juego1 : public Videojuego {
public:
    Juego1(const string& nombre, int cantidadJugadores, const vector<string>& categorias,
           const string& desarrollador, int anoLanzamiento, const string& plataforma)
        : Videojuego(nombre, cantidadJugadores, categorias, desarrollador, anoLanzamiento, plataforma) {}

    void jugar() override {
        // Lógica para jugar el juego 1
        cout << "Jugando Juego 1..." << endl;
    }
};

// Clase hija Juego2
class Juego2 : public Videojuego {
public:
    Juego2(const string& nombre, int cantidadJugadores, const vector<string>& categorias,
           const string& desarrollador, int anoLanzamiento, const string& plataforma)
        : Videojuego(nombre, cantidadJugadores, categorias, desarrollador, anoLanzamiento, plataforma) {}

    void jugar() override {
        // Lógica para jugar el juego 2
        cout << "Jugando Juego 2..." << endl;
    }
};

// Clase para gestionar la colección de videojuegos
class GestorVideojuegos {
private:
    vector<Videojuego*> listaVideojuegos;

public:
    // Funciones para agregar y mostrar videojuegos
    void agregarVideojuego(Videojuego* juego) {
        listaVideojuegos.push_back(juego);
    }

    void mostrarVideojuegos() const {
        for (const auto& juego : listaVideojuegos) {
            juego->mostrarInformacion();
        }
    }

    // Funciones de ordenamiento
    void ordenarPorTitulo() {
        sort(listaVideojuegos.begin(), listaVideojuegos.end(),
                  [](Videojuego* a, Videojuego* b) { return a->nombre < b->nombre; });
    }

    void ordenarPorAnoLanzamiento() {
        sort(listaVideojuegos.begin(), listaVideojuegos.end(),
                  [](Videojuego* a, Videojuego* b) { return a->anoLanzamiento < b->anoLanzamiento; });
    }

    // Otras funciones de utilidad
    // Implementar funciones para agregar categorías, filtrar por plataforma, etc.
};

// Función principal
int main() {
    // Ejemplo de uso del sistema
    GestorVideojuegos gestor;

    // Crear algunos juegos
    Juego1 juego1("Super Mario", 1, {"Plataforma", "Aventura"}, "Nintendo", 1985, "NES");
    Juego2 juego2("The Legend of Zelda", 1, {"Aventura", "Acción"}, "Nintendo", 1986, "NES");

    // Agregar juegos al gestor
    gestor.agregarVideojuego(&juego1);
    gestor.agregarVideojuego(&juego2);

    // Mostrar la lista de videojuegos
    gestor.mostrarVideojuegos();

    return 0;
}
