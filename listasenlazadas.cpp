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

    // Método para agregar un elemento al final de la lista
    void agregarAlFinal(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            return;
        }
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
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
};

int main() {
    ListaEnlazada lista;

    lista.agregarAlInicio(3);
    lista.agregarAlInicio(2);
    lista.agregarAlInicio(1);

    lista.imprimir(); // Salida esperada: 1 2 3

    lista.agregarAlFinal(4);
    lista.agregarAlFinal(5);

    lista.imprimir(); // Salida esperada: 1 2 3 4 5

    return 0;
}
