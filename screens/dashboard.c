#include "../headers/dashboard.h"
#include "./paciente.c"
#include "./consulta.c"
#include "./funcionario.c"
#include "./feedback.c"
#include "./relatorio.c"
#include "./medico.c"
#include "../util/bool.h"

void DashboardScreen() {

	int option;

  do {
    system("cls");
    printf("\n\n================ Painel de controle ================\n");
    printf("\n[1] - Pacientes");
    printf("\n[2] - Funcionarios");
    printf("\n[3] - Medicos");
    printf("\n[4] - Feedbacks");
    printf("\n[5] - Consultas");
    printf("\n[6] - Relatorios (apenas adminstrador do sistema)");
    printf("\n\n[0] - Sair");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch(option) {
      case 1: PacienteScreen();
              break;
      case 2: FuncionarioScreen();
              break;
      case 3: MedicoScreen();
              break;
      case 4: FeedbackScreen();
              break;
      case 5: ConsultaScreen();
              break;
      case 6: RelatorioScreen();
              break;
      case 0: return;
              break;
      default: printf("Opcao invalida!");
    }
    printf("\n\n");
    system("pause");
  } while (true);
}