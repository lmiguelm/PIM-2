#include "../headers/screens/funcionario.h"
#include "../models/funcionario.c"
#include "../util/bool.h"

int CadastroFuncionario(){

    char nome[100], email[100], senha[100], cpf[11], sobrenome[100];

    do {
      system("cls");
      printf("\n\n================ Cadastro ================\n");

      printf("Informe seu nome: ");
      fflush(stdin);
      gets(nome);

      printf("Informe seu sobrenome: ");
      fflush(stdin);
      gets(sobrenome);

      printf("Informe seu CPF: ");
      fflush(stdin);
      gets(cpf);

      printf("Informe seu E-mail: ");
      fflush(stdin);
      gets(email);

      printf("Insira uma senha: ");
      fflush(stdin);
      gets(senha);

      printf("\n\n==================================================\n");

      if(salvarFuncionario(nome, sobrenome, cpf, email, senha) == 0) {
        system("cls");
        printf("\n\n==================================================\n");
        printf("Cadastro realizado com sucesso!!");
        printf("\n\n==================================================\n\n");
        return 0;
      } else {
        system("cls");
        printf("\n\n==================================================\n");
        printf("Ops! Não conseguimos realizar seu cadastro. Tente novamente");
        printf("\n\n==================================================\n\n");
        system("pause");
      }
  } while(true);
}