#include "../headers/paciente.h"
#include "../models/paciente.c"
#include "../util/bool.h"

void cadastrarP() {

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

void listarP() {
  system("cls");
  printf("\n\n================ Pacientes Cadastrados ================\n");
  listarPacientes(recuperarPacientes());
  printf("\n\n======================================================\n\n");
}

void PacienteScreen() {
  int option;

  do {
    system("cls");
    printf("\n\n================ Pacientes ================\n");
    printf("\n[1] - Cadastrar Paciente");
    printf("\n[2] - Listar Pacientes");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch(option) {
      case 1: cadastrarP();
              break;
      case 2: listarP();
              break;
      case 0: return;
              break;
      default: printf("Opcao invalida");
    }
    printf("\n\n");
    system("pause");

  } while(true);
}