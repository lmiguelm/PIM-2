#include "../headers/relatorio.h"
#include "../util/bool.h"

void pacientesPorUnidade() {
  printf("Pacientes por unidade");
}

void unidadeQueMaisAtende() {
  printf("Unidade que mais atende");
}

void totalizacaoDiariaMensal() {

}

int RelatorioScreen() {
  int option;

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