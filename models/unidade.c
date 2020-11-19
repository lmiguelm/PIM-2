#include "../headers/unidade.h"

int salvarUnidadeAtual(int unidade) {
  FILE *ponteiro_arq;
  ponteiro_arq = fopen("./database/unidade_atual.txt", "w");

  if(ponteiro_arq == NULL ) {
    printf("Erro na arbertura do arquivo");
    return 1; 
  }  

  fprintf(ponteiro_arq, "%d", unidade);
  fclose(ponteiro_arq);

  free(ponteiro_arq);
  return 0;
}

int recuperarUnidadeAtual() {
  FILE *ponteiro_arq;
  ponteiro_arq = fopen("./database/unidade_atual.txt", "r");
  int unidade;
  fscanf(ponteiro_arq, "%d", &unidade);
  return unidade;
}