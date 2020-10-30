#include "../headers/login.h"
#include "./dashboard.c"
#include "../util/bool.h"

void login() {
  char email[100], senha[100];

  do {
    system("cls");
    printf("\n\n================ Entrar ================\n");
    printf("Informe seu e-mail: ");
    fflush(stdin);
    gets(email);

    printf("Informe sua senha: ");
    fflush(stdin);
    gets(senha);
    printf("\n\n==================================================\n");


    if(validarLogin(email, senha) != 0) { // senha ou email invalido
      system("cls");
      printf("\n\n==================================================\n");
      printf("Dados incorretos, tente novamente");
      printf("\n\n==================================================\n\n");
      system("pause");
    } else {
      DashboardScreen(); // dashboard
    }
   
  } while (true);
}

void LoginScreen() {
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
      case 0: exit(0);
              break;
      case 1: login();
              break;
      case 2: FuncionarioScreen();
              break;
      default: printf("\nOpcao invalida!");
    }

    printf("\n\n");
    system("pause");

  } while (option != 0);
}

