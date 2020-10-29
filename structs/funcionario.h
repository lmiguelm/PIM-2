typedef struct {
  char nome[100];
  char email[100];
  char senha[100];
  char cpf[11];
  char sobrenome[100];
} Funcionario;

typedef struct {
  Funcionario *arrayDeFuncionarios;
  size_t used;
  size_t size;
} ArrayDeFuncionarios;