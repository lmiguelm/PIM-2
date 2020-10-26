#include "../headers/models/funcionarios.h"

int salvarFuncionario(char nome[100], char sobrenome[100], char cpf[11], char email[100], char senha[100]) {
  FILE *ponteiro_arq;

  ponteiro_arq = fopen("./database/funcionarios.txt", "a");

  if(ponteiro_arq == NULL) {
    printf("Erro na arbertura do arquivo");
    return 1;
  } 

  fprintf(ponteiro_arq, "nome: %s, sobrenome: %s, cpf: %s, email: %s, senha: %s \n", nome, sobrenome, cpf, email, senha);
  fclose(ponteiro_arq);
  return 0;
}