#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo() : siguiente(nullptr) {}
    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};


template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
    int tamano;

public:
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}

    void insertarAlInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        tamano++;
    }

    void mostrar() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    int size() const {
        return tamano;
    }
};

class Cancion {
private:
    string nomCancion;
    string artista;
    float duracion;
public:
    Cancion() {}

    string getNomCancion() const {
        return nomCancion;
    }

    string getArtista() const {
        return artista;
    }

    float getDuracion() const {
        return duracion;
    }

    void setNomCancion(string nombre) {
        nomCancion = nombre;
    }

    void setArtista(string art) {
        artista = art;
    }

    void setDuracion(float dur) {
        duracion = dur;
    }
};

class ListaReproduccion {
private:
    ListaEnlazada<Cancion> canciones;
public:
    void agregarCancion() {
        Cancion nuevaCancion;
        string nombre, artista;
        float duracion;

        cout << "Nombre de la cancion: ";
        cin.ignore();
        getline(cin, nombre);
        nuevaCancion.setNomCancion(nombre);

        cout << "Artista: ";
        getline(cin, artista);
        nuevaCancion.setArtista(artista);

        cout << "Duracion (en minutos): ";
        cin >> duracion;
        nuevaCancion.setDuracion(duracion);

        canciones.insertarAlInicio(nuevaCancion);
    }

    void mostrarLista() {
        canciones.mostrar();
    }
};

int main() {
    ListaReproduccion lista;

    int opcion;
    do {
        cout << "Que deseas hacer?" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Mostrar lista de reproduccion" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            lista.agregarCancion();
            break;
        case 2:
            cout << "Lista de reproduccion:" << endl;
            lista.mostrarLista();
            break;
        case 3:
            cout << "Hasta luego!" << endl;
            break;
        default:
            cout << "Opcion no valida. Intentalo de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}
