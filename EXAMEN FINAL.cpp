#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Aquí guardo los datos básicos de un proyecto
class Proyecto {
private:
    int codigo;              // código único del proyecto
    string nombre;           // nombre del proyecto
    string fechaInicio;      // fecha de inicio
    string fechaFin;         // fecha de fin
public:
    // Aqui incializo el proyecto con sus datos
    Proyecto(int c, string n, string fi, string ff) {
        codigo = c;
        nombre = n;
        fechaInicio = fi;
        fechaFin = ff;
    }
    //  Le agrego un método para tener el código del proyecto
    int getCodigo() { return codigo; }
    // Aquì agrego un metodo para mostrar la info completa del proyecto
    void mostrar() {
        cout << "Codigo: " << codigo
             << " | Nombre: " << nombre
             << " | Inicio: " << fechaInicio
             << " | Fin: " << fechaFin << endl;
    }
};

// Aquí se guardan los datos de cada trabajador
class Empleado {
private:
    int id;                        // ID único del empleado
    string nombre;                 // nombre del empleado
    string categoria;              // categoría (Administrador, Operario, Peon)
    double salario;                // salario
    string direccion;              // dirección
    vector<int> proyectosAsignados;// lista de proyectos donde trabaja
public:
    //inicializa el empleado con sus datos
    Empleado(int i, string n, string c, double s, string d) {
        id = i;
        nombre = n;
        categoria = c;
        salario = s;
        direccion = d;
    }
    // Método para obtener el ID del empleado
    int getId() { return id; }
    // Método para asignar un proyecto al empleado
    void asignarProyecto(int codigoProyecto) {
        proyectosAsignados.push_back(codigoProyecto);
    }
    // Método para mostrar la info completa del empleado
    void mostrar() {
        cout << "ID: " << id
             << " | Nombre: " << nombre
             << " | Categoria: " << categoria
             << " | Salario: " << salario
             << " | Direccion: " << direccion << endl;
        cout << "Proyectos asignados: ";
        if (proyectosAsignados.empty()) {
            cout << "Ninguno";
        } else {
            for (int p : proyectosAsignados) cout << p << " ";
        }
        cout << endl;
    }
};

int main() {
    // Aqui agrego vectores para guardar empleados y proyectos
    vector<Empleado> empleados;
    vector<Proyecto> proyectos;
    int opcion;

    // Menú principal que se repite hasta que el usuario elija salir
    do {
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Crear empleado\n";
        cout << "2. Crear proyecto\n";
        cout << "3. Listar empleados\n";
        cout << "4. Listar proyectos\n";
        cout << "5. Asignar proyecto a empleado\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Opción 1: crear un nuevo empleado
        if (opcion == 1) {
            int id;
            string nombre, categoria, direccion;
            double salario;
            cout << "Ingrese ID del empleado: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese nombre del empleado: ";
            getline(cin, nombre);
            cout << "Ingrese categoria (Administrador/Operario/Peon): ";
            getline(cin, categoria);
            cout << "Ingrese salario (250000 - 500000): ";
            cin >> salario;
            // Validación del salario
            if (salario < 250000 || salario > 500000) {
                cout << "Salario fuera de rango, se asigna 250000 por defecto.\n";
                salario = 250000;
            }
            cin.ignore();
            cout << "Ingrese direccion (si deja vacio se asigna San Jose): ";
            getline(cin, direccion);
            // Validación de dirección
            if (direccion.empty()) direccion = "San Jose";
            empleados.push_back(Empleado(id, nombre, categoria, salario, direccion));
        } 
        // Opción 2: crear un nuevo proyecto
        else if (opcion == 2) {
            int codigo;
            string nombre, fi, ff;
            cout << "Ingrese codigo del proyecto: ";
            cin >> codigo;
            cin.ignore();
            cout << "Ingrese nombre del proyecto: ";
            getline(cin, nombre);
            cout << "Ingrese fecha de inicio: ";
            getline(cin, fi);
            cout << "Ingrese fecha de fin: ";
            getline(cin, ff);
            proyectos.push_back(Proyecto(codigo, nombre, fi, ff));
            }
            // Opción 3: mostrar todos los empleados
        else if (opcion == 3) {
            cout << "\n--- Lista de empleados ---\n";
            for (auto &e : empleados) e.mostrar();
        } 
        // Opción 4: mostrar todos los proyectos
        else if (opcion == 4) {
            cout << "\n--- Lista de proyectos ---\n";
            for (auto &p : proyectos) p.mostrar();
        } 
        // Opción 5: asignar un proyecto a un empleado
        else if (opcion == 5) {
            int idEmp, codPro;
            cout << "Ingrese ID del empleado: ";
            cin >> idEmp;
            cout << "Ingrese codigo del proyecto: ";
            cin >> codPro;
            bool encontrado = false;
            for (auto &e : empleados) {
                if (e.getId() == idEmp) {
                    e.asignarProyecto(codPro);
                    cout << "Proyecto asignado correctamente.\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "Empleado no encontrado.\n";
        }
    } while (opcion != 6); // Opción 6: salir del programa

    return 0;
}
