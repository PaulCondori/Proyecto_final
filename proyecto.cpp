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
    cin.ignore();

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
    cout << "Nombre del veterinario encargado: ";
    getline(cin, animales[n].encargado.nombre);
    cout << "Anios de experiencia del veterinario: ";
    cin >> animales[n].encargado.anios_exp;
    cout << "Tipo de alimento: ";
    cin.ignore();
    getline(cin, animales[n].alimentacion.tipo_alimento);
    cout << "Cantidad diaria (en gramos): ";
    cin >> animales[n].alimentacion.cantidad_diaria;
    cin.ignore();
    cout << "Frecuencia de alimentacion: ";
    getline(cin, animales[n].alimentacion.frecuencia);
    n++;
}


int main() {
    // Aui implementaremos todo
    return 0;
}

