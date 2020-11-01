#include<stdio.h>
#include<string.h>
#include "./screens/login.c"
#include "./models/unidade.c"

void main() {
  int option;

  do {
    system("cls");
    printf("\n\n================ Seja bem-vindo(a) ================\n");
    printf("\n[1] - Unidade I");
    printf("\n[2] - Unidade II");
    printf("\n[3] - Unidade III");
    printf("\n\n[0] - Fechar");
    printf("\n\n==================================================\n\n");

    printf("Escolha sua unidade: ");
    scanf("%d", &option);

    if(option == 0) {
      exit(0);
    } else if (option == 1 || option == 2 || option == 3) {
     if(salvarUnidadeAtual(option) == 0) {
      LoginScreen();
     } else {
       system("cls");
       printf("Ops! nao foi possivel acessar essa unidade");
     }
    } else {
      printf("Opcao invalida!!");
    }
    printf("\n\n");
    system("pause");
  } while(true);
}