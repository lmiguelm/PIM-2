#include "../headers/login.h"
#include "./dashboard.c"
#include "../util/bool.h"

void login() {
  char email[100], senha[100];
  int option;

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
      printf("\n\n===================== Dados incorretos =============================\n");
      printf("\n[1] - Tentar novamente");
      printf("\n[0] - Voltar");
      printf("\n\n====================================================================\n\n");
      printf("\nDigite uma opcao: ");
      scanf("%d", &option);

      if(option == 0) {
        return;
      }
    } else {
      DashboardScreen(); // dashboard
      return;
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

    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("\nDigite: ");
    scanf("%d", &option);

    switch (option) {
      case 0: return;
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

