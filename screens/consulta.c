#include "../headers/consulta.h"
#include "../models/consulta.c"
#include "../util/bool.h"

void cadastrarConsulta() {
  system("cls");

  Consulta consulta;
  int flag = true;
  
  do {
    printf("Informe a CRM do medico: ");
    fflush(stdin);
    scanf("%d", &consulta.crm);
    system("cls");

    if(verificarCRM(consulta.crm) == 1) {
      printf("\n\n========================================================================\n\n");
      printf("\nCRM nao encontrado!");
      printf("\n\n========================================================================\n\n");
      system("pause");
      system("cls");
    } else {
     flag = false;
    }

  } while(flag);

  
  flag = true;
  do {
    printf("Informe a data da consulta(dd/mm/aaaa hh:mm): ");
    scanf("%d/%d/%d %d:%d", &consulta.data.dia, &consulta.data.mes, &consulta.data.ano, &consulta.data.hora, &consulta.data.minutos);
    fflush(stdin);

    if(verificarHorario(consulta.crm, consulta.data) == 1) {
      printf("\n\n========================================================================\n\n");
      printf("\nHorario indisponivel");
      printf("\n\n========================================================================\n\n");
      system("pause");
      system("cls");
    } else {
     flag = false;
    }
  } while (flag);

  flag = true;
  do {
    printf("Informe o CPF do paciente: ");
    fflush(stdin);
    gets(consulta.cpf);

    if(verificarCPF(consulta.cpf) == 1) {
      printf("\n\n========================================================================\n\n");
      printf("\nCPF nao encontrado!");
      printf("\n\n========================================================================\n\n");
      system("pause");
      system("cls");
    } else {
     flag = false;
    }
  } while(flag);

  printf("Informe o Preco: ");
  fflush(stdin);
  scanf("%f", &consulta.preco);
  system("cls");

  if(salvarConsulta(consulta) == 0) {
    printf("\n\n==================================================\n");
    printf("Consulta de salva com sucesso!");
    printf("\n\n==================================================\n\n");
    return;
  } else {
    printf("\n\n==================================================\n");
    printf("Ops! Nao conseguimos realizar sua consulta. Tente novamente");
    printf("\n\n==================================================\n\n");
    system("pause");
  }
}

void ConsultaScreen() {
  int option;

  do {  
    system("cls");
    printf("\n\n==================== Consultas ===================\n");
    printf("\n[1] - Nova Consulta");
    printf("\n[2] - Cancelar Consulta");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    fflush(stdin);
    scanf("%d", &option);

    switch(option) {
      case 1: cadastrarConsulta();
              break;
      case 2: printf("ok2");
              break;
      case 0: return;
              break;
      default: printf("Opcao invalida!");
    }
    system("pause");
  } while (true);
}