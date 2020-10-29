#include "../headers/dashboard.h"
#include "./paciente.c"
#include "./funcionario.c"
#include "./feedbacks.c"
#include "./relatorio.c"
#include "./medico.c"
#include "../util/bool.h"

void DashboardScreen() {

	int option;

  Paciente paciente;
  ArrayDePacientes pacientes;
  initArrayPaciente(&pacientes);

  Medico medico;
	ArrayDeMedicos medicos;
  initArrayMedico(&medicos);

  do {
    system("cls");
    printf("\n\n================ Painel de controle ================\n");
    printf("\n[1] - Cadastro de Pacientes");
    printf("\n[2] - Cadastro de Funcionarios");
    printf("\n[3] - Cadastro de Medicos");
    printf("\n[4] - Cadastro de Feedbacks");
    printf("\n[5] - Relatorios");

    printf("\n\n[0] - Sair");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

		if(option == 1) {
      paciente = PacienteScreen();
      insertArrayPaciente(&pacientes, paciente);
    } else if(option == 2) {
			medico = MedicoScreen();
      insertArrayMedico(&medicos, medico);
    } else if(option == 3) {
			medico = MedicoScreen();
      insertArrayMedico(&medicos, medico);
    } else if(option == 4) {
			printf("Feedbacks...");
    } else if(option == 5) {
			printf("Relatorios...");
		} else if(option == 0){
			printf("hushuashuahsudh");
		} else {
			printf("Opcao invalida!");
		}


		// APENAS PARA TESTAR SE REALMENTE SALVOU NO PONTEIRO...
    for(int i = 0; i < medicos.used; i++) {
      printf("\nnome: %s\n", medicos.arrayDeMedicos[i].nome);
      printf("\nsobrenome: %s\n", medicos.arrayDeMedicos[i].sobrenome);
      printf("\nespecialidade: %s\n", medicos.arrayDeMedicos[i].especialidade);
      printf("\ncrm: %d\n", medicos.arrayDeMedicos[i].crm);
      printf("\n");
    }

    printf("\n\n");
    system("pause");

  } while (true);
}