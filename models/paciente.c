void initArrayPaciente(ArrayDePacientes *a)
{
  a->arrayDePacientes = malloc(1 * sizeof(Paciente)); // ALOCANDO ESPAÇO NA MEMÓRIA PARA O VALOR INICIAL DO ARRAY
  a->used = 0;                                        // SETANDO O VALOR DO TAMANHO USADO
  a->size = 1;                                        // SETANDO O TAMANHO ALOCADO
}

void insertArrayPaciente(ArrayDePacientes *a, Paciente element)
{
  if (a->used == a->size)
  {                                                                                 // VERIFICA SE O TAMANHO QUE ESTA SENDO USADO É IGUAL AO TAMANHO ALOCADO
    a->size *= 2;                                                                   // DUPLICANDO O TAMANHO
    a->arrayDePacientes = realloc(a->arrayDePacientes, a->size * sizeof(Paciente)); // REALOCANDO O TAMANHO PARA O DOBRO DO ANTERIOR
  }
  a->arrayDePacientes[a->used++] = element; // INSERINDO O ELEMENTO NO ARRAY
}

void freeArrayPaciente(ArrayDePacientes *a)
{
  // LIMPANDO
  free(a->arrayDePacientes);
  a->arrayDePacientes = NULL;
  a->used = a->size = 0;
}

int salvarPaciente(Paciente paciente)
{
  FILE *ponteiro_qtd;                                               // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/pacientes/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE PACIENTES NO MODO DE LEITURA

  FILE *ponteiro_arq;                                              // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/pacientes/pacientes.txt", "a"); // APONTANDO PARA O ARQUIVO  PACIENTES NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if (ponteiro_arq == NULL || ponteiro_qtd == NULL)
  { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  }

  // RECUPERANDO UNIDADE ATUAL
  int unidade = recuperarUnidadeAtual();

  // SALVANDO UM NOVO PACIENTE
  fprintf(ponteiro_arq, "%d %s %s %s %s %d \n", unidade, paciente.nome, paciente.sobrenome, paciente.cpf, paciente.sexo, paciente.idade);
  fclose(ponteiro_arq);

  // INCREMENTANDO O NUMERO DE PACIENTES DE 1 EM 1
  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade);                          // LENDO O ARQUIVO DE QUANTIDADE DE PACIENTES E ARMAZENANDO O VALOR NA VARIAVEL 'QUANTIDADE'
  ponteiro_qtd = fopen("./database/pacientes/quantidade.txt", "w"); // APONTANDO PARA O MESMO ARQUIVO DE QUANTIDADE, MAS COM O MODO DE ESCRITA, AONDE ELE SOBRESCREVE O VALOR JÁ EXISTENTE POR UM NOVO
  fprintf(ponteiro_qtd, "%d", quantidade + 1);                      // SALVANDO O NOVO VALOR NO ARQUIVO
  fclose(ponteiro_qtd);

  // LIMPANDO PONTEIRO
  free(ponteiro_qtd);
  free(ponteiro_arq);

  return 0; // RETORNO CASO TUDO TENHA OCORRIDO COMO ESPERADO
}

ArrayDePacientes recuperarPacientes()
{
  FILE *ponteiro_arq, *ponteiro_qtd; // CRIANDO PONTEIRO FILE

  ponteiro_arq = fopen("./database/pacientes/pacientes.txt", "r");  // APONTANDO PARA O ARQUIVO DE PACIENTES NO MODO DE LEITURA
  ponteiro_qtd = fopen("./database/pacientes/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE PACIENTES NO MODO DE LEITURA

  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // RECUPERANDO A QUANTIDADE DE PACIENTES EXISTENTES

  Paciente paciente;             // STRUCT DE PACIENTE
  ArrayDePacientes pacientes;    // ARRAY DINAMICO DE PACIENTES
  initArrayPaciente(&pacientes); // INICIANDO O ARRAY EM 1

  // RECUPERANDO UNIDADE ATUAL
  int unidade = recuperarUnidadeAtual();
  int i;
  for (i = 0; i < quantidade; i++)
  { // PERCORRENDO DE 0 ATÉ A QUANTIDADE DE PACIENTES
    // LENDO OS DADOS DOS PACIENTES..
    fscanf(ponteiro_arq, "%d %s %s %s %s %d", &paciente.unidade, &paciente.nome, &paciente.sobrenome, &paciente.cpf, &paciente.sexo, &paciente.idade);

    if (paciente.unidade == unidade || unidade == 4)
    {
      // INSERINDO CADA PACIENTE EM UMA POSIÇÃO DO ARRAY DINÂMICO
      insertArrayPaciente(&pacientes, paciente);
    }
  }

  // LIMPANDO PONTEIRO
  free(ponteiro_arq);
  free(ponteiro_qtd);

  return pacientes;
}

int verificarCPF(char cpf[20])
{
  ArrayDePacientes pacientes = recuperarPacientes();
  int unidade = recuperarUnidadeAtual();
  int i;
  for (i = 0; i < pacientes.used; i++)
  {
    if (unidade == pacientes.arrayDePacientes[i].unidade && strcmp(pacientes.arrayDePacientes[i].cpf, cpf) == 0)
    {
      return 0;
    }
  }
  return 1;
}
