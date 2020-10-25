#include "../headers/funcionario.h"

int CadastroFuncionario(){

    char nome[100], email[120], senha[100];
    int cpf;

    do {
        system("cls");
        printf("\n\n================ Cadastro ================\n");

        printf("Informe seu nome: ");
        fflush(stdin);
        gets(nome);

        printf("Informe seu E-mail: ");
        fflush(stdin);
        gets(email);

        printf("Informe seu CPF: ");
        fflush(stdin);
        scanf("%d", &cpf);

        printf("Insira uma senha: ");
        fflush(stdin);
        gets(senha);

        printf("\n\n==================================================\n");

        system("cls");
        printf("\n\n==================================================\n");
        printf("Cadastro realizado com sucesso!!");
        printf("\n\n==================================================\n\n");

        return 0;
    
  } while(1==1);
}