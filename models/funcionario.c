void initArrayFuncionario(ArrayDeFuncionarios *a) {
  a->arrayDeFuncionarios = malloc(1 * sizeof(Funcionario));
  a->used = 0;
  a->size = 1;
}

void insertArrayFuncionario(ArrayDeFuncionarios *a, Funcionario element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->arrayDeFuncionarios = realloc(a->arrayDeFuncionarios, a->size * sizeof(Funcionario));
  }
  a->arrayDeFuncionarios[a->used++] = element;
}

void FreeArrayFuncionario(ArrayDeFuncionarios *a) {
  free(a->arrayDeFuncionarios);
  a->arrayDeFuncionarios = NULL;
  a->used = a->size = 0;
}