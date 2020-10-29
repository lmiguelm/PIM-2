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

		// FALTA AS OUTRAS OPÇÕES ....
    if(option == 1) {
      paciente = PacienteScreen();
      insertArrayPaciente(&pacientes, paciente);
    }


		// APENAS PARA TESTAR SE REALMENTE SALVOU NO PONTEIRO...
    for(int i = 0; i < pacientes.used; i++) {
      printf("\nnome: %s\n", pacientes.arrayDePacientes[i].nome);
      printf("\nsobrenome: %s\n", pacientes.arrayDePacientes[i].sobrenome);
      printf("\nsexo: %s\n", pacientes.arrayDePacientes[i].sexo);
      printf("\ncpf: %s\n", pacientes.arrayDePacientes[i].cpf);
      printf("\nidade: %d\n", pacientes.arrayDePacientes[i].idade);
      printf("\n");
    }

    printf("\n\n");
    system("pause");

  } while (true);
}