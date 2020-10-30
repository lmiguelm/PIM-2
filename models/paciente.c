void initArrayPaciente(ArrayDePacientes *a) {
  a->arrayDePacientes = malloc(1 * sizeof(Paciente));
  a->used = 0;
  a->size = 1;
}

void insertArrayPaciente(ArrayDePacientes *a, Paciente element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->arrayDePacientes = realloc(a->arrayDePacientes, a->size * sizeof(Paciente));
  }
  a->arrayDePacientes[a->used++] = element;
}

void freeArrayPaciente(ArrayDePacientes *a) {
  free(a->arrayDePacientes);
  a->arrayDePacientes = NULL;
  a->used = a->size = 0;
}

int salvarPaciente(Paciente paciente) {
  FILE *ponteiro_arq;

  ponteiro_arq = fopen("./database/pacientes.txt", "a");

  if(ponteiro_arq == NULL) {
    printf("Erro na arbertura do arquivo");
    return 1;
  } 

  fprintf(ponteiro_arq, "nome: %s, sobrenome: %s, cpf: %s, sexo: %s, idade: %d \n", paciente.nome, paciente.sobrenome, paciente.cpf, paciente.sexo, paciente.idade);
  fclose(ponteiro_arq);
  return 0;
}