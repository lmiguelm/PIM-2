typedef struct {
  int unidade;
  char nome[100];
  char sobrenome[100];
  char especialidade[200];
  int crm;
} Medico;

typedef struct {
  Medico *arrayDeMedicos;
  size_t used;
  size_t size;
} ArrayDeMedicos;