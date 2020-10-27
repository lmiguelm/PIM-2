#include "../headers/screens/medico.h"
#include "../util/bool.h"

int MedicoScreen() {
  char nome[100];

  do {
    system("cls");
    printf("\n\n================ Cadastro ================\n");

    printf("Informe seu nome: ");
    fflush(stdin);
    gets(nome);
    
    printf("\n\n==================================================\n");

    system("cls");
    printf("\n\n==================================================\n");
    printf("Cadastro realizado com sucesso!!");
    printf("\n\n==================================================\n\n");

    return 0;
    
  } while(true);
}