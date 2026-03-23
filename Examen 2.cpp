#include <iostream>
#include <string>
using namespace std;


const int MAX_PACIENTES = 100;
const int MAX_MEDICOS = 50;
const int MAX_CITAS = 200;


struct Paciente {
    int id;
    string nombre;
    string historial;
};

struct Medico {
    int id;
    string nombre;
    string especialidad;
};

struct Cita {
    int idPaciente;
    int idMedico;
    string fecha;
};

Paciente pacientes[MAX_PACIENTES];
Medico medicos[MAX_MEDICOS];
Cita citas[MAX_CITAS];

int numPacientes = 0;
int numMedicos = 0;
int numCitas = 0;

void registrarPaciente() {
    if (numPacientes < MAX_PACIENTES) {
        pacientes[numPacientes].id = numPacientes + 1;
        cout << "Nombre del paciente: ";
        cin >> pacientes[numPacientes].nombre;
        pacientes[numPacientes].historial = "Historial vacio";
        cout << "Paciente registrado con ID: " << pacientes[numPacientes].id << endl;
        numPacientes++;
    } else {
        cout << "No se pueden registrar mas pacientes." << endl;
    }
}

void registrarMedico() {
    if (numMedicos < MAX_MEDICOS) {
        medicos[numMedicos].id = numMedicos + 1;
        cout << "Nombre del medico: ";
        cin >> medicos[numMedicos].nombre;
        cout << "Especialidad: ";
        cin >> medicos[numMedicos].especialidad;
        cout << "Medico registrado con ID: " << medicos[numMedicos].id << endl;
        numMedicos++;
    } else {
        cout << "No se pueden registrar mas medicos." << endl;
    }
}

void programarCita() {
    if (numCitas < MAX_CITAS) {
        int idPaciente, idMedico;
        cout << "ID del paciente: ";
        cin >> idPaciente;
        cout << "ID del médico: ";
        cin >> idMedico;
        cout << "Fecha de la cita (dd/mm/aaaa): ";
        cin >> citas[numCitas].fecha;
        citas[numCitas].idPaciente = idPaciente;
        citas[numCitas].idMedico = idMedico;
        cout << "Cita registrada exitosamente." << endl;
        numCitas++;
    } else {
        cout << "No se pueden registrar mas citas." << endl;
    }
}

void mostrarReportes() {
    cout << "\n--- Reporte de la Clinica ---" << endl;
    cout << "Pacientes registrados: " << numPacientes << endl;
    cout << "Medicos registrados: " << numMedicos << endl;
    cout << "Citas programadas: " << numCitas << endl;
}


int main() {
    int opcion;
    do {
        cout << "\n--- Clinica ---" << endl;
        cout << "1. Registrar Paciente" << endl;
        cout << "2. Registrar Medico" << endl;
        cout << "3. Programar Cita" << endl;
        cout << "4. Mostrar Reportes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarPaciente(); break;
            case 2: registrarMedico(); break;
            case 3: programarCita(); break;
            case 4: mostrarReportes(); break;
            case 0: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(opcion != 0);

    return 0;
}


