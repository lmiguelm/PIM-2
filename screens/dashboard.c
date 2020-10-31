#include "../headers/dashboard.h"
#include "./paciente.c"
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
    printf("\n[1] - Cadastro de Pacientes");
    printf("\n[2] - Listar Pacientes");
    printf("\n\n[3] - Cadastro de Funcionarios");
    printf("\n[4] - Listar Funcionarios");
    printf("\n\n[5] - Cadastro de Medicos");
    printf("\n[6] - Listar Medicos");
    printf("\n\n[7] - Cadastro de Feedbacks");
    printf("\n[8] - Listar Feedbacks");
    printf("\n\n[9] - Relatorios");

    printf("\n\n[0] - Sair");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

		if(option == 1) {
      PacienteScreen();
    } else if (option == 2) {

      system("cls");
      printf("\n\n================ Pacientes Cadastrados ================\n");
      listarPacientes(recuperarPacientes());
      printf("\n\n======================================================\n\n");

    } else if (option == 3) {
      FuncionarioScreen();
    } else if (option == 4) {

      system("cls");
      printf("\n\n================ Funcionarios Cadastrados ================\n");
      listarFuncionarios(recuperarFuncionarios());
      printf("\n\n======================================================\n\n");

    } else if (option == 5) {
      MedicoScreen();
    } else if (option == 6) {

      system("cls");
      printf("\n\n================ Medicos Cadastrados ================\n");
      listarMedicos(recuperarMedicos());
      printf("\n\n======================================================\n\n");

    } else if (option == 7) {
      FeedbackScreen();
    } else if (option == 8) {
      system("cls");
      printf("\n\n================ Feedbacks Cadastrados ================\n");
      listarFeedbacks(recuperarFeedbacks());
      printf("\n\n======================================================\n\n");
    } else if (option == 9) {
      RelatorioScreen();
    } else if (option == 0) {
      exit(0);
    } else {
      printf("Opcao invalida!");
    }

    printf("\n\n");
    system("pause");

  } while (true);
}