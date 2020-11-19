#include "../headers/funcionario.h"
#include "../models/funcionario.c"
#include "../util/bool.h"

void cadastrarF()
{
  int flag;

  if (recuperarUnidadeAtual() == 4)
  {
    system("cls");
    printf("\n\n==================================================\n\n");
    printf("Apenas funcionarios podem cadastrar novos Funcionarios de uma unidade especifica!");
    printf("\n\n==================================================\n\n");
    return;
  }

  Funcionario funcionario;

  do
  {
    system("cls");
    printf("\n\n================ Cadastro de funcionario ================\n");

    printf("Informe seu nome: ");
    fflush(stdin);
    gets(funcionario.nome);

    printf("Informe seu sobrenome: ");
    fflush(stdin);
    gets(funcionario.sobrenome);

    flag = true;
    do
    {
      printf("Informe seu CPF (xxx.xxx.xxx-xx): ");
      fflush(stdin);
      gets(funcionario.cpf);

      if (cpfExistenteFuncionario(funcionario.cpf) == 1)
      {
        printf("\n\n========================================================================\n\n");
        printf("\nCPF ja cadastrado no sistema!");
        printf("\n\n========================================================================\n\n");
        system("pause");
        system("cls");
      }
      else
      {
        flag = false;
      }
    } while (flag);

    flag = true;
    do
    {
      printf("Informe seu e-mail: ");
      fflush(stdin);
      gets(funcionario.email);

      if (emailExistente(funcionario.email) == 1)
      {
        printf("\n\n========================================================================\n\n");
        printf("\nE-mail ja cadastrado no sistema! Tente utilizar outro.");
        printf("\n\n========================================================================\n\n");
        system("pause");
        system("cls");
      }
      else
      {
        flag = false;
      }
    } while (flag);

    printf("Insira uma senha: ");
    fflush(stdin);
    gets(funcionario.senha);

    if (salvarFuncionario(funcionario) == 0)
    {
      system("cls");
      printf("\n\n==================================================\n");
      printf("%s cadastrado com sucesso!", funcionario.nome);
      printf("\n\n==================================================\n\n");
      return;
    }
    else
    {
      system("cls");
      printf("\n\n==================================================\n");
      printf("Ops! Nao conseguimos realizar seu cadastro. Tente novamente");
      printf("\n\n==================================================\n\n");
      system("pause");
    }

    printf("\n\n==================================================\n");
  } while (true);
}

void listarFuncionarios(ArrayDeFuncionarios array)
{
  system("cls");
  if (array.arrayDeFuncionarios[0].unidade > 4 || array.arrayDeFuncionarios[0].unidade < 1)
  {
    printf("\n\n======================================================\n\n");
    printf("Nao ha nenhum funcionario cadastrado!");
    printf("\n\n======================================================\n\n");
  }
  else
  {
    if (recuperarUnidadeAtual() == 4)
    {
      printf("\n\n================ Funcionarios Cadastrados ================\n");
    }
    else
    {
      printf("\n\n================ Funcionarios Cadastrados - Unidade %d ================\n", array.arrayDeFuncionarios[0].unidade);
    }
    for (int i = 0; i < array.used; i++)
    {
      printf("\n--------------------------------------------------");
      printf("\nNome: %s", array.arrayDeFuncionarios[i].nome);
      printf("\nSobrenome: %s", array.arrayDeFuncionarios[i].sobrenome);
      printf("\nCPF: %s", array.arrayDeFuncionarios[i].cpf);
      printf("\nE-mail: %s", array.arrayDeFuncionarios[i].email);
      printf("\n--------------------------------------------------\n");
    }
    printf("\n\n======================================================\n\n");
  }
  FreeArrayFuncionario(&array);
}

void FuncionarioScreen()
{
  int option;

  do
  {
    system("cls");
    printf("\n\n================ Funcionario ================\n");
    printf("\n[1] - Cadastrar Funcionario");
    printf("\n[2] - Listar Funcionarios");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      cadastrarF();
      break;
    case 2:
      listarFuncionarios(recuperarFuncionarios());
      break;
    case 0:
      return;
      break;
    default:
      printf("Opcao invalida");
    }
    printf("\n\n");
    system("pause");

  } while (true);
}