void initArrayMedico(ArrayDeMedicos *a) {
  a->arrayDeMedicos = malloc(1 * sizeof(Medico));
  a->used = 0;
  a->size = 1;
}

void insertArrayMedico(ArrayDeMedicos *a, Medico element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->arrayDeMedicos = realloc(a->arrayDeMedicos, a->size * sizeof(Medico));
  }
  a->arrayDeMedicos[a->used++] = element;
}

void FreeArrayMedico(ArrayDeMedicos *a) {
  free(a->arrayDeMedicos);
  a->arrayDeMedicos = NULL;
  a->used = a->size = 0;
}