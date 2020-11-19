#include "../structs/paciente.h"

void PacienteScreen();

int salvarPaciente(Paciente element);
ArrayDePacientes recuperarPacientes();
void listarPacientes(ArrayDePacientes a);
int verificarCPF(char cpf[14]);

void initArrayPaciente(ArrayDePacientes *a);
void insertArrayPaciente(ArrayDePacientes *a, Paciente element);
void freeArrayPaciente(ArrayDePacientes *a);