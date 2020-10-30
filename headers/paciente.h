#include "../structs/paciente.h"

void PacienteScreen();

int salvarPaciente(Paciente element);
ArrayDePacientes recuperarPacientes();
void listarPacientes(ArrayDePacientes a);

void initArrayPaciente(ArrayDePacientes *a);
void insertArrayPaciente(ArrayDePacientes *a, Paciente element);
void freeArrayPaciente(ArrayDePacientes *a);