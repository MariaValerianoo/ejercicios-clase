#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Clase base para representar una cuenta
class CuentaNequi {
protected:
    string nombreTitular;
    int edad;
    float saldo;
    vector<float> movimientos;

public:
    CuentaNequi(string _nombreTitular, int _edad, float _saldo) : nombreTitular(_nombreTitular), edad(_edad), saldo(_saldo) {}

    string getNombreTitular() const { return nombreTitular; }

    float getSaldo() const { return saldo; }

    void realizarMovimiento(float monto) {
        saldo += monto;
        movimientos.push_back(monto);
    }

    virtual void ordenarMovimientosPorLetra() = 0;
    virtual void ordenarMovimientosPorNumero() = 0;
    virtual void recargar(float monto) = 0;
    virtual void recargar(float monto, string puntoNequi, float minRecarga) = 0;
    virtual void recargar(string tipoBanco, string cuenta, float saldo) = 0;
    virtual void recargar(string codigo) = 0;
    virtual void agregarAlColchon(float monto) = 0;
    virtual void establecerMeta(float montoMeta) = 0;
    virtual void agregarABolsillos(float monto) = 0;
    virtual void sacarPlata(float monto) = 0;
    virtual void mostrarMovimientos() = 0;
};

// Clase derivada para representar una cuenta Nequi
class CuentaNequiImpl : public CuentaNequi {
private:
    vector<float> colchon;
    vector<float> meta;
    vector<float> bolsillos;

public:
    CuentaNequiImpl(string _nombreTitular, int _edad, float _saldo) : CuentaNequi(_nombreTitular, _edad, _saldo) {}

    void recargar(float monto) override {
        if (edad >= 18) {
            realizarMovimiento(monto);
            cout << "Recarga al toque exitosa. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "El usuario no es mayor de edad." << endl;
        }
    }

    void recargar(float monto, string puntoNequi, float minRecarga) override {
        cout << "Para recarga con efectivo, dirígete a " << puntoNequi << " y realiza una recarga mínima de " << minRecarga << " COP." << endl;
    }

    void recargar(string tipoBanco, string cuenta, float saldo) override {
        cout << "Recarga desde otro banco (" << tipoBanco << ") a la cuenta " << cuenta << " por un monto de " << saldo << " COP." << endl;
        realizarMovimiento(saldo);
    }

    void recargar(string codigo) override {
        if (codigo == "12345") {
            realizarMovimiento(100);
            cout << "Recarga exitosa con código de regalo. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "Código de regalo no válido." << endl;
        }
    }

    void agregarAlColchon(float monto) override {
        colchon.push_back(monto);
    }

    void establecerMeta(float montoMeta) override {
        meta.push_back(montoMeta);
    }

    void agregarABolsillos(float monto) override {
        bolsillos.push_back(monto);
    }

    void sacarPlata(float monto) override {
        if (saldo >= monto) {
            saldo -= monto;
            movimientos.push_back(-monto);
            cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    void mostrarMovimientos() override {
        cout << "Historial de movimientos:" << endl;
        for (const auto& movimiento : movimientos) {
            if (movimiento > 0) {
                cout << "Recarga: " << movimiento << " COP" << endl;
            } else {
                cout << "Retiro: " << -movimiento << " COP" << endl;
            }
        }
    }

    // Implementación de la función de ordenarMovimientosPorNumero
    void ordenarMovimientosPorNumero() override {
        // Implementación del ordenamiento burbuja
        int n = movimientos.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (movimientos[j] < movimientos[j + 1]) {
                    float temp = movimientos[j];
                    movimientos[j] = movimientos[j + 1];
                    movimientos[j + 1] = temp;
                }
            }
        }
    }

    // Implementación de la función de ordenarMovimientosPorLetra
    void ordenarMovimientosPorLetra() override {
        // Implementación del ordenamiento de cadenas
        int n = movimientos.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (to_string(movimientos[j])[0] > to_string(movimientos[j + 1])[0]) {
                    float temp = movimientos[j];
                    movimientos[j] = movimientos[j + 1];
                    movimientos[j + 1] = temp;
                }
            }
        }
    }
};

// Función para limpiar el buffer del teclado
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // Ejemplo de uso
    CuentaNequiImpl cuenta("Juan", 20, 1000);
    int opcion;

    do {
        cout << "----- Menú -----" << endl;
        cout << "1. Realizar recarga al toque" << endl;
        cout << "2. Realizar recarga con efectivo" << endl;
        cout << "3. Realizar recarga desde otro banco" << endl;
        cout << "4. Realizar recarga con código de regalo" << endl;
        cout << "5. Agregar al colchón" << endl;
        cout << "6. Establecer meta" << endl;
        cout << "7. Agregar a bolsillos" << endl;
        cout << "8. Sacar plata" << endl;
        cout << "9. Mostrar movimientos" << endl;
        cout << "10. Ordenar movimientos por número" << endl;
        cout << "11. Ordenar movimientos por letra" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        limpiarBuffer();

        switch (opcion) {
            case 1: {
                float monto;
                cout << "Ingrese el monto a recargar: ";
                cin >> monto;
                cuenta.recargar(monto);
                break;
            }
            case 2: {
                float monto;
                string puntoNequi;
                float minRecarga;
                cout << "Ingrese el monto a recargar: ";
                cin >> monto;
                limpiarBuffer();
                cout << "Ingrese el punto Nequi: ";
                getline(cin, puntoNequi);
                cout << "Ingrese el monto mínimo de recarga: ";
                cin >> minRecarga;
                cuenta.recargar(monto, puntoNequi, minRecarga);
                break;
            }
            case 3: {
            string tipoBanco, cuenta;
            float saldo;
            cout << "Ingrese el tipo de banco: ";
            getline(cin, tipoBanco);
            cout << "Ingrese el número de cuenta: ";
            getline(cin, cuenta);
            cout << "Ingrese el monto a recargar: ";
            cin >> saldo;
            limpiarBuffer(); // Limpiar el buffer antes de leer el tipo de banco
            cuenta.recargar(tipoBanco, cuenta, saldo);
            break;
        }



            case 4: {
                string codigo;
                cout << "Ingrese el código de regalo: ";
                getline(cin, codigo);
                cuenta.recargar(codigo);
                break;
            }
            case 5: {
                float monto;
                cout << "Ingrese el monto a agregar al colchón: ";
                cin >> monto;
                cuenta.agregarAlColchon(monto);
                break;
            }
            case 6: {
                float montoMeta;
                cout << "Ingrese el monto de la meta: ";
                cin >> montoMeta;
                cuenta.establecerMeta(montoMeta);
                break;
            }
            case 7: {
                float monto;
                cout << "Ingrese el monto a agregar a bolsillos: ";
                cin >> monto;
                cuenta.agregarABolsillos(monto);
                break;
            }
            case 8: {
                float monto;
                cout << "Ingrese el monto a sacar: ";
                cin >> monto;
                cuenta.sacarPlata(monto);
                break;
            }
            case 9: {
                cuenta.mostrarMovimientos();
                break;
            }
            case 10: {
                cuenta.ordenarMovimientosPorNumero();
                cout << "Movimientos ordenados por número." << endl;
                break;
            }
            case 11: {
                cuenta.ordenarMovimientosPorLetra();
                cout << "Movimientos ordenados por letra." << endl;
                break;
            }
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
        }
    } while (opcion != 0);

    return 0;
}