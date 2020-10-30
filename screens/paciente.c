#include "../headers/paciente.h"
#include "../models/paciente.c"
#include "../util/bool.h"

void PacienteScreen() {

	Paciente paciente;

  do {
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
    scanf("%d", &paciente.idade);

    printf("Infome o sexo: ");
    fflush(stdin);
    gets(paciente.sexo);
    printf("\n\n==================================================\n");

    if(salvarPaciente(paciente) == 0) {
      system("cls");
      printf("\n\n==================================================\n");
      printf("%s cadastrado com sucesso!", paciente.nome);
      printf("\n\n==================================================\n\n");
      return;
    } else {
      system("cls");
      printf("\n\n==================================================\n");
      printf("Ops! Nao conseguimos realizar seu cadastro. Tente novamente");
      printf("\n\n==================================================\n\n");
      system("pause");
    }

  } while(true);
}