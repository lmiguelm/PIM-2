#include "../headers/paciente.h"
#include "../models/paciente.c"
#include "../util/bool.h"

void cadastrarP()
{

  if (recuperarUnidadeAtual() == 4)
  {
    system("cls");
    printf("\n\n==================================================\n\n");
    printf("Apenas funcionarios podem cadastrar Pacientes de uma unicdade especifica!");
    printf("\n\n==================================================\n\n");
    return;
  }

  Paciente paciente;

  do
  {
    system("cls");
    printf("\n\n================ Cadastro de paciente ================\n");
    printf("Informe o nome: ");
    fflush(stdin);
    gets(paciente.nome);

    printf("Informe o sobrenome: ");
    fflush(stdin);
    gets(paciente.sobrenome);

    printf("Informe o CPF (xxx.xxx.xxx-xx): ");
    fflush(stdin);
    gets(paciente.cpf);

    printf("Informe a idade: ");
    fflush(stdin);
    scanf("%d", &paciente.idade);

    printf("Infome o sexo: ");
    fflush(stdin);
    gets(paciente.sexo);
    printf("\n\n==================================================\n");

    if (salvarPaciente(paciente) == 0)
    {
      printf("%s cadastrado com sucesso!", paciente.nome);
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

  } while (true);
}

void listarPacientes(ArrayDePacientes array)
{
  int i;
  system("cls");
  if (array.arrayDePacientes[0].unidade > 3 || array.arrayDePacientes[0].unidade < 1)
  {
    printf("\n\n======================================================\n\n");
    printf("Nao ha nenhum paciente cadastrado!");
    printf("\n\n======================================================\n\n");
  }
  else
  {
    if (recuperarUnidadeAtual() == 4)
    {
      printf("\n\n================ Pacientes Cadastrados ================\n");
    }
    else
    {
      printf("\n\n================ Pacientes Cadastrados - Unidade %d ================\n", array.arrayDePacientes[0].unidade);
    }
    for (i = 0; i < array.used; i++)
    {
      printf("\n--------------------------------------------------");
      printf("\nNome: %s", array.arrayDePacientes[i].nome);
      printf("\nSobrenome: %s", array.arrayDePacientes[i].sobrenome);
      printf("\nCPF: %s", array.arrayDePacientes[i].cpf);
      printf("\nSexo: %s", array.arrayDePacientes[i].sexo);
      printf("\nIdade: %d", array.arrayDePacientes[i].idade);
      printf("\n--------------------------------------------------\n");
    }
    printf("\n\n======================================================\n\n");
  }
  freeArrayPaciente(&array);
}

void PacienteScreen()
{
  int option;

  do
  {
    system("cls");
    printf("\n\n================ Pacientes ================\n");
    printf("\n[1] - Cadastrar Paciente");
    printf("\n[2] - Listar Pacientes");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      cadastrarP();
      break;
    case 2:
      listarPacientes(recuperarPacientes());
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