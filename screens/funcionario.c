#include "../headers/funcionario.h"
#include "../models/funcionario.c"
#include "../util/bool.h"

void cadastrarF(){
  
  Funcionario funcionario;
  
  do {
    system("cls");
    printf("\n\n================ Cadastro de funcionario ================\n");

    printf("Informe seu nome: ");
    fflush(stdin);
    gets(funcionario.nome);

    printf("Informe seu sobrenome: ");
    fflush(stdin);
    gets(funcionario.sobrenome);

    printf("Informe seu CPF: ");
    fflush(stdin);
    gets(funcionario.cpf);

    printf("Informe seu E-mail: ");
    fflush(stdin);
    gets(funcionario.email);

    printf("Insira uma senha: ");
    fflush(stdin);
    gets(funcionario.senha);

    if(salvarFuncionario(funcionario) == 0) { 
      system("cls");
      printf("\n\n==================================================\n");
      printf("%s cadastrado com sucesso!", funcionario.nome);
      printf("\n\n==================================================\n\n");
      return;
    } else {
      system("cls");
      printf("\n\n==================================================\n");
      printf("Ops! Nao conseguimos realizar seu cadastro. Tente novamente");
      printf("\n\n==================================================\n\n");
      system("pause");
    }

    printf("\n\n==================================================\n");
  } while(true);
}

void listarF() {
  system("cls");
  printf("\n\n================ Funcionarios Cadastrados ================\n");
  listarFuncionarios(recuperarFuncionarios());
  printf("\n\n======================================================\n\n");
}

void FuncionarioScreen() {
  int option;

  do {
    system("cls");
    printf("\n\n================ Funcionario ================\n");
    printf("\n[1] - Cadastrar Funcionario");
    printf("\n[2] - Listar Funcionarios");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch(option) {
      case 1: cadastrarF();
              break;
      case 2: listarF();
              break;
      case 0: return;
              break;
      default: printf("Opcao invalida");
    }
    printf("\n\n");
    system("pause");

  } while(true);
}