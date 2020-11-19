typedef struct
{
  int unidade;
  char nome[100];
  char sobrenome[100];
  char sexo[20];
  int idade;
  char cpf[14];
} Paciente;

typedef struct
{
  Paciente *arrayDePacientes;
  size_t used;
  size_t size;
} ArrayDePacientes;