#include "../headers/funcionario.h"
#include "../util/bool.h"

int FuncionarioScreen(){
  
  Funcionario funcionario;
  
  system("cls");
  printf("\n\n================ Cadastro ================\n");

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

  printf("\n\n==================================================\n");

  return 0;
}