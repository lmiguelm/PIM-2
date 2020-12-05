#include "../headers/relatorio.h"
#include "../util/bool.h"

void pacientesPorUnidade()
{
  int i;
  ArrayDePacientes pacientes = recuperarPacientes();
  int unidade1 = 0, unidade2 = 0, unidade3 = 0, soma = 0;

  for (i = 0; i < pacientes.used; i++)
  {
    if (pacientes.arrayDePacientes[i].unidade == 1)
    {
      unidade1++;
    }
    else if (pacientes.arrayDePacientes[i].unidade == 2)
    {
      unidade2++;
    }
    else
    {
      unidade3++;
    }
    soma++;
  }
  system("cls");
  printf("\n\n================ Pacientes por unidade de rede ================\n");
  printf("\nUnidade 1 possui um total de %d paciente(s)", unidade1);
  printf("\nUnidade 2 possui um total de %d paciente(s)", unidade2);
  printf("\nUnidade 3 possui um total de %d paciente(s)", unidade3);
  printf("\n\nMedia de pacientes por unidade: %.2f paciente(s)", (float)soma / 3);
  printf("\n\n===============================================================\n");
}

void unidadeQueMaisAtende()
{

  int i;
  ArrayDeConsultas consultas = recuperarConsultas();

  int unidade1 = 0, unidade2 = 0, unidade3 = 0;

  for (i = 0; i < consultas.used; i++)
  {
    if (consultas.arrayDeConsultas[i].unidade == 1)
    {
      unidade1++;
    }
    else if (consultas.arrayDeConsultas[i].unidade == 2)
    {
      unidade2++;
    }
    else
    {
      unidade3++;
    }
  }

  system("cls");
  printf("\n\n================ Unidade que mais atende ================\n");
  if (unidade1 > unidade2 && unidade1 > unidade3)
  {
    printf("\n A unidade que mais atende e a unidade 1. Com um total de %d consultas realizadas", unidade1);
  }
  else if (unidade2 > unidade1 && unidade2 > unidade3)
  {
    printf("\n A unidade que mais atende e a unidade 2. Com um total de %d consultas realizadas", unidade2);
  }
  else if (unidade3 > unidade1 && unidade3 > unidade2)
  {
    printf("\n A unidade que mais atende e a unidade 3. Com um total de %d consultas realizadas", unidade3);
  }
  else
  {
    printf("\nHouve um empate, sendo assim, segue os numeros de consultas realizadas das tres unidades: ");
    printf("\n\nUnidade 1 atendeu um total de %d consultas", unidade1);
    printf("\nUnidade 2 atendeu um total de %d consultas", unidade2);
    printf("\nUnidade 3 atendeu um total de %d consultas", unidade3);
  }
  printf("\n\n===============================================================\n");
}

void totalizacaoDiariaMensal()
{
  int i;
  struct tm *data_atual;
  time_t atual = time(NULL);
  data_atual = localtime(&atual);
  data_atual->tm_mon += 1;
  data_atual->tm_year += 1900;

  ArrayDeConsultas consultas = recuperarConsultas();

  float diaria1 = 0, diaria2 = 0, diaria3 = 0;
  float mensal1 = 0, mensal2 = 0, mensal3 = 0;

  for (i = 0; i < consultas.used; i++)
  {
    if (consultas.arrayDeConsultas[i].unidade == 1)
    {
      if (consultas.arrayDeConsultas[i].data.mes == data_atual->tm_mon && consultas.arrayDeConsultas[i].data.ano == data_atual->tm_year)
      {
        mensal1 += consultas.arrayDeConsultas[i].preco;
      }
      if (consultas.arrayDeConsultas[i].data.dia == data_atual->tm_mday && consultas.arrayDeConsultas[i].data.mes == data_atual->tm_mon && consultas.arrayDeConsultas[i].data.ano == data_atual->tm_year)
      {
        diaria1 += consultas.arrayDeConsultas[i].preco;
      }
    }
    else if (consultas.arrayDeConsultas[i].unidade == 2)
    {
      if (consultas.arrayDeConsultas[i].data.mes == data_atual->tm_mon && consultas.arrayDeConsultas[i].data.ano == data_atual->tm_year)
      {
        mensal2 += consultas.arrayDeConsultas[i].preco;
      }
      if (consultas.arrayDeConsultas[i].data.dia == data_atual->tm_mday && consultas.arrayDeConsultas[i].data.mes == data_atual->tm_mon && consultas.arrayDeConsultas[i].data.ano == data_atual->tm_year)
      {
        diaria2 += consultas.arrayDeConsultas[i].preco;
      }
    }
    else if (consultas.arrayDeConsultas[i].unidade == 3)
    {
      if (consultas.arrayDeConsultas[i].data.mes == data_atual->tm_mon && consultas.arrayDeConsultas[i].data.ano == data_atual->tm_year)
      {
        mensal3 += consultas.arrayDeConsultas[i].preco;
      }
      if (consultas.arrayDeConsultas[i].data.dia == data_atual->tm_mday && consultas.arrayDeConsultas[i].data.mes == data_atual->tm_mon && consultas.arrayDeConsultas[i].data.ano == data_atual->tm_year)
      {
        diaria3 += consultas.arrayDeConsultas[i].preco;
      }
    }
  }

  system("cls");
  printf("\n\n================ Faturamento diario ================\n");
  printf("\nUnidade 1 teve um faturamento diario de R$ %.2f", diaria1);
  printf("\nUnidade 2 teve um faturamento diario de R$ %.2f", diaria2);
  printf("\nUnidade 3 teve um faturamento diario de R$ %.2f", diaria3);
  printf("\n\n======================================================\n");
  printf("\n\n================ Faturamento mensal ================\n");
  printf("\nUnidade 1 teve um faturamento mensal de R$ %.2f", mensal1);
  printf("\nUnidade 2 teve um faturamento mensal de R$ %.2f", mensal2);
  printf("\nUnidade 3 teve um faturamento mensal de R$ %.2f", mensal3);
  printf("\n\n======================================================\n");
}

void feedbacksPorUnidade()
{
  int i;
  ArrayDeFeedbacks feedbacks = recuperarFeedbacks();
  int otimo1 = 0, otimo2 = 0, otimo3 = 0;
  int medio1 = 0, medio2 = 0, medio3 = 0;
  int ruim1 = 0, ruim2 = 0, ruim3 = 0;

  for (i = 0; i < feedbacks.used; i++)
  {
    if (feedbacks.arrayDeFeedbacks[i].unidade == 1)
    {
      if (feedbacks.arrayDeFeedbacks[i].avaliacao == 1)
      {
        otimo1++;
      }
      else if (feedbacks.arrayDeFeedbacks[i].avaliacao == 2)
      {
        medio1++;
      }
      else if (feedbacks.arrayDeFeedbacks[i].avaliacao == 3)
      {
        ruim1++;
      }
    }
    else if (feedbacks.arrayDeFeedbacks[i].unidade == 2)
    {
      if (feedbacks.arrayDeFeedbacks[i].avaliacao == 1)
      {
        otimo2++;
      }
      else if (feedbacks.arrayDeFeedbacks[i].avaliacao == 2)
      {
        medio2++;
      }
      else if (feedbacks.arrayDeFeedbacks[i].avaliacao == 3)
      {
        ruim2++;
      }
    }
    else if (feedbacks.arrayDeFeedbacks[i].unidade == 3)
    {
      if (feedbacks.arrayDeFeedbacks[i].avaliacao == 1)
      {
        otimo3++;
      }
      else if (feedbacks.arrayDeFeedbacks[i].avaliacao == 2)
      {
        medio3++;
      }
      else if (feedbacks.arrayDeFeedbacks[i].avaliacao == 3)
      {
        ruim3++;
      }
    }
  }

  system("cls");
  printf("\n\n================ Feedbacks por unidade de rede ================\n");
  printf("\n\n----------------------------- Unidade 1 ------------------------------");
  printf("\n%d pacientes acharam um otimo atendimento", otimo1);
  printf("\n%d pacientes acharam o atendimento medio", medio1);
  printf("\n%d pacientes nao gostaram de seus atendimentos", ruim1);
  printf("\n----------------------------------------------------------------------\n\n");
  printf("\n\n----------------------------- Unidade 2 ------------------------------");
  printf("\n%d pacientes acharam um otimo atendimento", otimo2);
  printf("\n%d pacientes acharam o atendimento medio", medio2);
  printf("\n%d pacientes nao gostaram de seus atendimentos", ruim2);
  printf("\n----------------------------------------------------------------------\n\n");
  printf("\n\n----------------------------- Unidade 3 ------------------------------");
  printf("\n%d pacientes acharam um otimo atendimento", otimo3);
  printf("\n%d pacientes acharam o atendimento medio", medio3);
  printf("\n%d pacientes nao gostaram de seus atendimentos", ruim3);
  printf("\n----------------------------------------------------------------------\n\n");
  printf("\n\n======================================================\n");
}

int RelatorioScreen()
{
  int option;

  if (recuperarUnidadeAtual() != 4)
  {
    system("cls");
    printf("\n\n==================================================\n\n");
    printf("Ops! voce nao tem permissao para acessar essa funcionalidade!");
    printf("\n\n==================================================\n\n");
    return;
  }

  do
  {
    system("cls");
    printf("\n\n================ Relatorios ================\n");
    printf("\n[1] - Pacientes por unidade");
    printf("\n[2] - Unidade que mais atende");
    printf("\n[3] - Totalizacao diaria e mensal por unidade");
    printf("\n[4] - Feedbacks por unidade");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch (option)
    {
    case 0:
      return 0;
      break;
    case 1:
      pacientesPorUnidade();
      break;
    case 2:
      unidadeQueMaisAtende();
      break;
    case 3:
      totalizacaoDiariaMensal();
      break;
    case 4:
      feedbacksPorUnidade();
      break;
    default:
      printf("Opcao invalida!!");
    }
    printf("\n\n");
    system("pause");

  } while (true);
}