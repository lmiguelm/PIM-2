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