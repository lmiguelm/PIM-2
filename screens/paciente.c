#include "../headers/paciente.h"

int PacienteScreen() {
  int option;

  system("cls");
  printf("\n\n================ Pacientes ================\n");
  printf("\n[1] - Cadastrar novo paciente");
  printf("\n[2] - Agendar conculta");
  printf("\n[3] - Cancelar consulta");

  printf("\n\n[0] - Voltar");
  printf("\n\n==================================================\n\n");

  printf("Digite: ");
  scanf("%d", &option);

  switch(option) {
      case 0: return 0;
              break;
      case 1: printf("cadastrar paciente");
              break;
      case 2: printf("agendar consulta");
              break;
      case 3: printf("cancelar consulta");
              break;
    }
}