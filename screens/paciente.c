#include "../headers/paciente.h"
#include "../models/paciente.c"

Paciente PacienteScreen() {

	Paciente paciente;

  system("cls");
  printf("\n\n================ Cadastro de paciente ================\n");

  printf("Informe o nome: ");
  fflush(stdin);
  gets(paciente.nome);

  printf("Informe o sobrenome: ");
  fflush(stdin);
  gets(paciente.sobrenome);

  printf("Informe o CPF: ");
  fflush(stdin);
  gets(paciente.cpf);

  printf("Informe a idade: ");
  fflush(stdin);
  gets(paciente.idade);

  printf("Infome o sexo: ");
  fflush(stdin);
  gets(paciente.sexo);

  printf("\n\n==================================================\n");

	return paciente;
}