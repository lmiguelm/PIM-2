#include "../headers/dashboard.h"
#include "./funcionario.c"
#include "./feedbacks.c"

void DashboardScreen() {

  int option;

  do {
    system("cls");
    printf("\n\n================ Painel de controle ================\n");
    printf("\n[1] - Tela de Pacientes");
    printf("\n[2] - Tela de Funcionarios");
    printf("\n[3] - Tela de Medicos");
    printf("\n[4] - Tela de Feedbacks");
    printf("\n[5] - Tela de Relatorios");

    printf("\n\n[0] - Sair");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch(option) {
      case 0: exit(0);
              break;
      case 1: printf("pacientes");
              break;
      case 2: CadastroFuncionario();
              break;
      case 3: printf("medicos");
              break;
      case 4: Feedbacks();
              break;
      case 5: printf("relatorios");
              break;
      default: printf("Opcao invalida!!");
    }
    printf("\n\n");
    system("pause");

  } while (1 == 1);
}