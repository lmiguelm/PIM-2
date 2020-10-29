#include "../headers/medico.h"
#include "../models/medico.c"

Medico MedicoScreen() {
  
  Medico medico;

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

  return medico;
}