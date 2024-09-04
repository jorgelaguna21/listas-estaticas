#include <iostream>
#include <string>

using namespace std;

class Empleado {
public:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

Empleado() : ClaveEmpleado(0), Nombre(""), Domicilio(""), Sueldo(0.0), ReportaA("") {}

    Empleado(int claveEmpleado, const string& nombre, const string& domicilio, float sueldo, const string& reportaA) :
        ClaveEmpleado(claveEmpleado), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reportaA) {}

    void Imprime() {
        cout << "ClaveEmpleado: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "ReportaA: " << ReportaA << endl;
    }

    void CambiaDomic(const string& nuevoDomicilio) {
        Domicilio = nuevoDomicilio;
    }

    void CambiaReportaA(const string& nuevoReportaA) {
        ReportaA = nuevoReportaA;
    }

    void ActualSueldo(float nuevoSueldo) {
        Sueldo = nuevoSueldo;
    }
};

template <typename T>
class ListaEstatica {
private:
    T* datos;
    int capacidad;
    int tamanio;

public:
    ListaEstatica(int capacidad) : capacidad(capacidad), tamanio(0) {
        datos = new T[capacidad];
    }

    ~ListaEstatica() {
        delete[] datos;
    }

    bool Vacia() const {
        return tamanio == 0;
    }

    bool Llena() const {
        return tamanio == capacidad;
    }

    void Agrega(const T& elemento) {
        if (Llena()) {
            cout << "La lista esta llena." << endl;
        } else {
            datos[tamanio++] = elemento;
        }
    }

    int Buscar(const T& elemento) const {
        for (int i = 0; i < tamanio; i++) {
            if (datos[i].ClaveEmpleado == elemento.ClaveEmpleado) {
                return i;
            }
        }
        return -1;
    }

    void Elimina(const T& elemento) {
        int posicion = Buscar(elemento);
        if (posicion != -1) {
            for (int i = posicion; i < tamanio - 1; i++) {
                datos[i] = datos[i + 1];
            }
            tamanio--;
        } else {
            if (Vacia()) {
                cout << "La lista esta vacia." << endl;
            } else {
                cout << "El Empleado ingresado no existe." << endl;
            }
        }
    }

    void Inserta(const T& elemento, int posicion) {
        if (Llena()) {
            cout << "La lista esta llena." << endl;
        } else if (posicion < 0 || posicion > tamanio) {
            cout << "No se puede insertar el objeto en esa posicion." << endl;
        } else {
            for (int i = tamanio; i > posicion; i--) {
                datos[i] = datos[i - 1];
            }
            datos[posicion] = elemento;
            tamanio++;
        }
    }

    void Muestra() const {
        if (Vacia()) {
            return;
        }
        for (int i = 0; i < tamanio; i++) {
            datos[i].Imprime();
            cout << endl;
        }
    }
};

int main() {
    const int CAPACIDAD = 10;
    ListaEstatica<Empleado> lista(CAPACIDAD);

    int opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Agrega" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Elimina" << endl;
        cout << "4. Inserta" << endl;
        cout << "5. Muestra" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int claveEmpleado;
            string nombre, domicilio, reportaA;
            float sueldo;
            cout << "Dame la clave del empleado: ";
            cin >> claveEmpleado;
            cout << "Dame el nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Dame el domicilio del empleado: ";
            getline(cin, domicilio);
            cout << "Dame el sueldo del empleado: ";
            cin >> sueldo;
            cout << "Dame a quien reporta el empleado: ";
            cin.ignore();
            getline(cin, reportaA);
            lista.Agrega(Empleado(claveEmpleado, nombre, domicilio, sueldo, reportaA));
            break;
        }
        case 2: {
            int claveEmpleado;
            cout << "Dame la clave del empleado a buscar: ";
            cin >> claveEmpleado;
            int posicion = lista.Buscar(Empleado(claveEmpleado, "", "", 0, ""));
            if (posicion != -1) {
                cout << "El empleado se encuentra en la posicion " << posicion << endl;
            } else {
                if (lista.Vacia()) {
                    cout << "La lista no tiene elementos guardados aun." << endl;
                } else {
                    cout << "No hubo resultados en la busqueda." << endl;
                }
            }
            break;
        }
        case 3: {
            int claveEmpleado;
            cout << "Dame la clave del empleado a eliminar: ";
            cin >> claveEmpleado;
            lista.Elimina(Empleado(claveEmpleado, "", "", 0, ""));
            break;
        }
        case 4: {
            int claveEmpleado;
            string nombre, domicilio, reportaA;
            float sueldo;
            int posicion;
            cout << "Dame la clave del empleado a insertar: ";
            cin >> claveEmpleado;
            cout << "Dame el nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Dame el domicilio del empleado: ";
            getline(cin, domicilio);
            cout << "Dame el sueldo del empleado: ";
            cin >> sueldo;
            cout << "Dame a quien reporta el empleado: ";
            cin.ignore();
            getline(cin, reportaA);
            cout << "Dame la posicion donde se debe insertar el empleado: ";
            cin >> posicion;
            lista.Inserta(Empleado(claveEmpleado, nombre, domicilio, sueldo, reportaA), posicion);
            break;
        }
        case 5: {
            lista.Muestra();
            break;
        }
        case 6:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);

    return 0;
}
