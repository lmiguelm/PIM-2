#include "../headers/login.h"

void login() {
  int option;

  do {
    system("cls");
    printf("\n\n================Seja bem-vindo(a) ================\n");
    printf("\n[1] - Entrar no sistema");
    printf("\n[2] - Registre-se");

    printf("\n\n[0] - Sair");
    printf("\n\n==================================================\n\n");

    printf("\nDigite: ");
    scanf("%d", &option);

    switch (option) {
      case 0: printf("\nSaiu");
              break;
      case 1: printf("\nlogou");
              break;
      case 2: printf("\nregistrado");
              break;
      default: printf("\nOpcao invalida!");
    }

    printf("\n\n");
    system("pause");

  } while (option != 0);
}

