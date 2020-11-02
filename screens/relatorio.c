#include "../headers/relatorio.h"
#include "../util/bool.h"

void pacientesPorUnidade() {
  ArrayDePacientes pacientes = recuperarPacientes();
  int unidade1 = 0, unidade2 = 0, unidade3 = 0;

  for(int i = 0; i < pacientes.used; i++) {
    if(pacientes.arrayDePacientes[i].unidade == 1) {
      unidade1++;
    } else if(pacientes.arrayDePacientes[i].unidade == 2) {
      unidade2++;
    } else {
      unidade3++;
    }
  }
  system("cls");
  printf("\n\n================ Pacientes por unidade de rede ================\n");
  printf("\nUnidade 1 possui um total de %d paciente(s)", unidade1);
  printf("\nUnidade 2 possui um total de %d paciente(s)", unidade2);
  printf("\nUnidade 3 possui um total de %d paciente(s)", unidade3);
  printf("\n\n===============================================================\n");
  
}

void unidadeQueMaisAtende() {
  printf("Unidade que mais atende");
}

void totalizacaoDiariaMensal() {

}

int RelatorioScreen() {
  int option;

  if(recuperarUnidadeAtual() != 4) {
    system("cls");
    printf("\n\n==================================================\n\n");
    printf("Ops! voce nao tem permissao para acessar essa funcionalidade!");
    printf("\n\n==================================================\n\n");
    return;
  }

  do {
    system("cls");
    printf("\n\n================ Relatorios ================\n");
    printf("\n[1] - Pacientes por unidade");
    printf("\n[2] - Unidade que mais atende");
    printf("\n[3] - Totalizacao diaria e mensal por unidade");
    printf("\n\n[0] - Voltar");
    printf("\n\n==================================================\n\n");

    printf("Digite: ");
    scanf("%d", &option);

    switch(option) {
      case 0: return 0;
              break;
      case 1: pacientesPorUnidade();
              break;
      case 2: unidadeQueMaisAtende();
              break;
      case 3: totalizacaoDiariaMensal();
              break;
      default: printf("Opcao invalida!!");
    }
    printf("\n\n");
    system("pause");

  } while(true);
}