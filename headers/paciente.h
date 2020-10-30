#include "../structs/paciente.h"

void PacienteScreen();

int salvarPaciente(Paciente element);

void initArrayPaciente(ArrayDePacientes *a);
void insertArrayPaciente(ArrayDePacientes *a, Paciente element);
void freeArrayPaciente(ArrayDePacientes *a);