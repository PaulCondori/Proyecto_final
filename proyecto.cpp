#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Veterinario {
    string nombre;
    int anios_exp;
};

struct Dieta {
    string tipo_alimento;
    int cantidad_diaria;
    string frecuencia;
};

struct Animal {
    string nombre;
    string especie;
    char sexo;
    int edad;
    string habitat;
    Veterinario encargado;
    Dieta alimentacion;
};

void agregarAnimal(Animal animales[], int &n) {
    if (n >= MAX) return;

    cout << "Nombre del animal: ";
    getline(cin, animales[n].nombre);
    cout << "Especie: ";
    getline(cin, animales[n].especie);
    cout << "Sexo (M/H): ";
    cin >> animales[n].sexo;
    cin.ignore();
    cout << "Edad: ";
    cin >> animales[n].edad;
    cin.ignore();
    cout << "Habitat: ";
    getline(cin, animales[n].habitat);
    n++;
}

void modificarAnimal(Animal animales[], int n) {
    int pos;
    cout << "Ingrese el ID del animal a modificar: ";
    cin >> pos;
    if (pos >= 1 && pos < n) {
        cin.ignore();
        cout << "Nuevo nombre: ";
        getline(cin, animales[pos].nombre);

        cout << "Nueva especie: ";
        getline(cin, animales[pos].especie);

        cout << "Nuevo sexo (M/H): ";
        cin >> animales[pos].sexo;

        cout << "Nueva edad: ";
        cin >> animales[pos].edad;
        cin.ignore();

        cout << "Nuevo habitat: ";
        getline(cin, animales[pos].habitat);

        cout << "Nuevo nombre del veterinario: ";
        getline(cin, animales[pos].encargado.nombre);

        cout << "Nuevos anios de experiencia: ";
        cin >> animales[pos].encargado.anios_exp;
        cin.ignore();
    } else {
        cout << "ID invalido. " << endl;
    }
}

int main() {
    // Aqui implementaremos todo
    return 0;
}

