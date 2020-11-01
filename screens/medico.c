#include "../headers/medico.h"
#include "../models/medico.c"
#include "../util/bool.h"

void cadastrarM() {
  
  Medico medico;

  do {
    system("cls");
    printf("\n\n================ Cadastro de Medico ================\n");

    printf("Informe o nome: ");
    fflush(stdin);
    gets(medico.nome);

    printf("Informe o sobrenome: ");
    fflush(stdin);
    gets(medico.sobrenome);

    printf("Informe a especialidade: ");
    fflush(stdin);
    gets(medico.especialidade);

    printf("Informe o numero da CRM: ");
    fflush(stdin);
    scanf("%d", &medico.crm);
    printf("\n\n==================================================\n");

    if(salvarMedico(medico) == 0) {
      system("cls");
      printf("\n\n==================================================\n");
      printf("%s cadastrado com sucesso!", medico.nome);
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

void listarMedicos(ArrayDeMedicos array) {
  system("cls");
  printf("\n\n================ Medicos Cadastrados - Unidade %d ================\n", array.arrayDeMedicos[0].unidade);
  for(int i = 0; i < array.used; i++) {
    printf("\n--------------------------------------------------");
    printf("\nNome: %s", array.arrayDeMedicos[i].nome);
    printf("\nSobrenome: %s", array.arrayDeMedicos[i].sobrenome);
    printf("\nEspecialidade: %s", array.arrayDeMedicos[i].especialidade);
    printf("\nCRM: %d", array.arrayDeMedicos[i].crm);
    printf("\n--------------------------------------------------\n");
  }
  printf("\n\n======================================================\n\n");
  FreeArrayMedico(&array);
}

void MedicoScreen() {
  int option;

  do {
    system("cls");
    printf("\n\n================ Medico ================\n");
    printf("\n[1] - Cadastrar Medico");
    printf("\n[2] - Listar Medicos");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch(option) {
      case 1: cadastrarM();
              break;
      case 2:   listarMedicos(recuperarMedicos());
              break;
      case 0: return;
              break;
      default: printf("Opcao invalida");
    }
    printf("\n\n");
    system("pause");

  } while(true);
}