#include "../headers/feedback.h"
#include "../util/bool.h"
#include "../models/feedback.c"

void cadastrarFed()
{

  if (recuperarUnidadeAtual() == 4)
  {
    system("cls");
    printf("\n\n==================================================\n\n");
    printf("Apenas funcionarios podem cadastrar Feedbacks de uma unicdade especifica!");
    printf("\n\n==================================================\n\n");
    return;
  }

  Feedback feedback;

  do
  {
    system("cls");
    printf("\n\n================ Painel de Feedbacks ================\n");
    printf("\n[1] - Otimo");
    printf("\n[2] - Mediano");
    printf("\n[3] - Ruim");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite uma opcao: ");
    fflush(stdin);
    scanf("%d", &feedback.avaliacao);

    system("cls");
    if (feedback.avaliacao == 1)
    {
      printf("Digite sua mensagem: ");
      fflush(stdin);
      gets(feedback.mensagem);

      if (salvarFeedback(feedback) == 0)
      {
        system("cls");
        printf("\n\n==================================================\n");
        printf("feedback cadastrado com sucesso!");
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
    }
    else if (feedback.avaliacao == 2)
    {
      printf("Digite sua mensagem: ");
      fflush(stdin);
      gets(feedback.mensagem);

      if (salvarFeedback(feedback) == 0)
      {
        system("cls");
        printf("\n\n==================================================\n");
        printf("feedback cadastrado com sucesso!");
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
    }
    else if (feedback.avaliacao == 3)
    {
      printf("Digite sua mensagem: ");
      fflush(stdin);
      gets(feedback.mensagem);

      if (salvarFeedback(feedback) == 0)
      {
        system("cls");
        printf("\n\n==================================================\n");
        printf("feedback cadastrado com sucesso!");
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
    }
    else if (feedback.avaliacao == 0)
    {
      return;
    }
    system("cls");
  } while (true);
}

void listarFeedbacks(ArrayDeFeedbacks array)
{
  int i;
  system("cls");
  if (array.arrayDeFeedbacks[0].unidade > 3 || array.arrayDeFeedbacks[0].unidade < 1)
  {
    printf("\n\n======================================================\n\n");
    printf("Nao ha nenhum feedback cadastrado!");
    printf("\n\n======================================================\n\n");
  }
  else
  {
    if (recuperarUnidadeAtual() == 4)
    {
      printf("\n\n================ Feedbacks Cadastrados ================\n");
    }
    else
    {
      printf("\n\n================ Feedbacks Cadastrados - Unidade %d ================\n", array.arrayDeFeedbacks[0].unidade);
    }
    for (i = 0; i < array.used; i++)
    {
      printf("\n--------------------------------------------------");
      printf("\nAvaliacao: %d", array.arrayDeFeedbacks[i].avaliacao);
      printf("\nMensagem: %s", array.arrayDeFeedbacks[i].mensagem);
      printf("\n--------------------------------------------------\n");
    }
    printf("\n\n======================================================\n\n");
  }
  FreeArrayFeedbacks(&array);
}

void FeedbackScreen()
{
  int option;

  do
  {
    system("cls");
    printf("\n\n================ Feedback ================\n");
    printf("\n[1] - Cadastrar Feedback");
    printf("\n[2] - Listar Feedbacks");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      cadastrarFed();
      break;
    case 2:
      listarFeedbacks(recuperarFeedbacks());
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