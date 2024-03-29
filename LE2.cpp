#include <iostream>

using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

// Definición de la clase ListaEnlazada
class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    // Método para agregar un elemento al inicio de la lista
    void agregarAlInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // Método para imprimir los elementos de la lista
    void imprimir() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    // Método para buscar un elemento en la lista
    bool buscar(int valor) {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            if (temp->dato == valor) {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }
};

int main() {
    ListaEnlazada lista;

    // Agregamos elementos a la lista
    lista.agregarAlInicio(3);
    lista.agregarAlInicio(2);
    lista.agregarAlInicio(1);

    lista.imprimir(); // Salida esperada: 1 2 3

    // Realizamos una búsqueda en la lista
    int valorBuscado;
    cout << "Ingrese el valor a buscar: ";
    cin >> valorBuscado;

    if (lista.buscar(valorBuscado)) {
        cout << "El valor " << valorBuscado << " se encuentra en la lista." << endl;
    } else {
        cout << "El valor " << valorBuscado << " no se encuentra en la lista." << endl;
    }

    return 0;
}
