#include <iostream>
#include <list>
#include <string>
using namespace std;

class Cancion {
private:
    string nomCancion;
    string artista;
    float duracion;
public:
    Cancion() {

    }
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
    list<Cancion> canciones;
public:
    void agregarCancion() {
        Cancion nuevaCancion;
        string nombre, artista;
        float duracion;

        cout << "Nombre de la cancion: ";
        cin.ignore(); // Ignorar el salto de línea anterior
        getline(cin, nombre);
        nuevaCancion.setNomCancion(nombre);

        cout << "Artista: ";
        getline(cin, artista);
        nuevaCancion.setArtista(artista);

        cout << "Duracion (en minutos): ";
        cin >> duracion ;
        nuevaCancion.setDuracion(duracion);

        canciones.push_back(nuevaCancion);
    }

    void mostrarLista() {
        for (const auto& cancion : canciones) {
            cout << "Cancion: " << cancion.getNomCancion() << endl;
            cout << "Artista: " << cancion.getArtista() << endl;
            cout << "Duracion: " << cancion.getDuracion() << " minutos" << endl;
            cout << endl;
        }
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
