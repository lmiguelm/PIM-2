#include "../headers/screens/dashboard.h"
#include "./paciente.c"
#include "./funcionario.c"
#include "./feedbacks.c"
#include "./relatorio.c"
#include "./medico.c"

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
      case 1: PacienteScreen();
              break;
      case 2: CadastroFuncionario();
              break;
      case 3: MedicoScreen();
              break;
      case 4: FeedbackScreen();
              break;
      case 5: RelatorioScreen();
              break;
      default: printf("Opcao invalida!!");
    }
    printf("\n\n");
    system("pause");

  } while (1 == 1);
}