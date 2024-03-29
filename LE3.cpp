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

    // Método para buscar un elemento en la lista, si no está, lo agrega y luego imprime la lista
    void buscarYAgregar(int valor) {
        if (!buscar(valor)) {
            agregarAlInicio(valor);
            cout << "El valor " << valor << " no estaba en la lista. Se ha agregado." << endl;
            cout << "Lista actualizada: ";
            imprimir();
        } else {
            cout << "El valor " << valor << " se encuentra en la lista." << endl;
        }
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

    lista.buscarYAgregar(valorBuscado);

    return 0;
}
