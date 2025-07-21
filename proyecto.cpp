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
    if (n >= MAX) {
        cout << "Nose pueden agregar más animales.\n";
        return;
    }
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

void mostrarAnimales(const Animal animales[], int n) {
    if (n == 0) {
        cout << "No hay animales registrados. " << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        cout << "---------------\n";
        cout << "\nAnimal #" << i << ":\n";
        cout << "Nombre: " << animales[i].nombre << endl;
        cout << "Especie: " << animales[i].especie << endl;
        cout << "Sexo: " << animales[i].sexo << endl;
        cout << "Edad: " << animales[i].edad << " a os\n";
        cout << "Habitat: " << animales[i].habitat << endl;
        cout << "---------------\n";
        cout << "Veterinario encargado:\n";
        cout << "Nombre: " << animales[i].encargado.nombre << endl;
        cout << "Anios de experiencia: " << animales[i].encargado.anios_exp << endl;
        cout << "---------------\n";
        cout << "Dieta:\n";
        cout << "Tipo de alimento: " << animales[i].alimentacion.tipo_alimento << endl;
        cout << "Cantidad diaria: " << animales[i].alimentacion.cantidad_diaria << " g\n";
        cout << "Frecuencia: " << animales[i].alimentacion.frecuencia << endl;
        cout << "---------------\n";
    }
    system("pause");
}

void eliminarAnimal(Animal animales[], int &n) {
    int pos;
    cout << "ID a eliminar: ";
    cin >> pos;
    if (pos >= 1 && pos < n) {
        for (int i = pos; i < n - 1; i++)
            animales[i] = animales[i + 1];
            n--;
        cout << "Eliminado.\n";
    } else {
        cout << "ID inválido.\n";
    }
}

void buscarPorNombre(const Animal animales[], int n, const string& nombre) {
    for (int i = 1; i < n; i++) {
        if (animales[i].nombre == nombre) {
            cout << "Encontrado en ID " << i << endl;
            return;
        }
    }
    cout << "No encontrado.\n";
}

int main() {
        Animal animales[MAX];
    int n = 1;
    int opcion;

    do {
        cout << "--------- MENU DEL ZOOLOGICO ---------" << endl;
        cout << "1. Agregar un animal\n";
        cout << "2. Modificar un animal\n";
        cout << "3. Mostrar todos los animales\n";
        cout << "4. Eliminar un animal\n";
        cout << "5. Buscar animal por nombre\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion valida: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarAnimal(animales, n);
                break;
            case 2:
                modificarAnimal(animales, n);
                break;
            case 3:
                mostrarAnimales(animales, n);
                break;
            case 4:
                eliminarAnimal(animales, n);
                break;
            case 5: {
                string nombre;
                cin.ignore();
                cout << "Ingrese el nombre del animal a buscar: ";
                getline(cin, nombre);
                buscarPorNombre(animales, n, nombre);
                break;
            }
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    
    return 0;
}

