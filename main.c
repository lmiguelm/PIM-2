#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "./screens/login.c"
#include "./models/unidade.c"

void main()
{
  int option;

  do
  {
    system("cls");
    printf("\n\n================ Seja bem-vindo(a) ================\n");
    printf("\n[1] - Unidade I");
    printf("\n[2] - Unidade II");
    printf("\n[3] - Unidade III");
    printf("\n[4] - Entrar como adminstrador");
    printf("\n\n[0] - Fechar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    if (option == 0)
    {
      exit(0);
    }
    else if (option == 1 || option == 2 || option == 3 || option == 4)
    {
      if (salvarUnidadeAtual(option) == 0)
      {
        if (option == 4)
        {
          login();
        }
        else
        {
          LoginScreen(option);
        }
      }
      else
      {
        system("cls");
        printf("Ops! nao foi possivel acessar essa unidade");
      }
    }
    else
    {
      printf("Opcao invalida!!");
    }
    printf("\n\n");
    system("pause");
  } while (true);
}