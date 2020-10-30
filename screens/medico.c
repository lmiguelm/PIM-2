#include "../headers/medico.h"
#include "../models/medico.c"
#include "../util/bool.h"

void MedicoScreen() {
  
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