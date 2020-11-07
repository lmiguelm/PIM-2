typedef struct {
  int dia;
  int mes;
  int ano;
  int hora;
  int minutos;
} Data;

typedef struct {
  int id;
  int unidade;
  int crm;
  char cpf[100];
  float preco;
  Data data;
} Consulta;

typedef struct {
  Consulta *arrayDeConsultas;
  size_t used;
  size_t size;
} ArrayDeConsultas;