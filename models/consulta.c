void initArrayConsulta(ArrayDeConsultas *a)
{
  a->arrayDeConsultas = malloc(1 * sizeof(Consulta)); // ALOCANDO ESPAÇO NA MEMÓRIA PARA O VALOR INICIAL DO ARRAY
  a->used = 0;                                        // SETANDO O VALOR DO TAMANHO USADO
  a->size = 1;                                        // SETANDO O TAMANHO ALOCADO
}

void insertArrayConsulta(ArrayDeConsultas *a, Consulta element)
{
  if (a->used == a->size)
  {                                                                                 // VERIFICA SE O TAMANHO QUE ESTA SENDO USADO É IGUAL AO TAMANHO ALOCADO
    a->size *= 2;                                                                   // DUPLICANDO O TAMANHO
    a->arrayDeConsultas = realloc(a->arrayDeConsultas, a->size * sizeof(Consulta)); // REALOCANDO O TAMANHO PARA O DOBRO DO ANTERIOR
  }
  a->arrayDeConsultas[a->used++] = element; // INSERINDO O ELEMENTO NO ARRAY
}

void FreeArrayConsulta(ArrayDeConsultas *a)
{
  // LIMPANDO
  free(a->arrayDeConsultas);
  a->arrayDeConsultas = NULL;
  a->used = a->size = 0;
}

int salvarConsulta(Consulta consulta)
{
  FILE *ponteiro_qtd;                                               // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/consultas/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE CONSTULTAS NO MODO DE LEITURA

  FILE *ponteiro_arq;                                              // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/consultas/consultas.txt", "a"); // APONTANDO PARA O ARQUIVO  MEDICOS NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if (ponteiro_arq == NULL || ponteiro_qtd == NULL)
  { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  }

  // RECUPERANDO UNIDADE ATUAL
  int unidade = recuperarUnidadeAtual();

  // INCREMENTANDO O NUMERO DE MEDICOS DE 1 EM 1
  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade);                          // LENDO O ARQUIVO DE QUANTIDADE DE MEDICOS E ARMAZENANDO O VALOR NA VARIAVEL 'QUANTIDADE'
  ponteiro_qtd = fopen("./database/consultas/quantidade.txt", "w"); // APONTANDO PARA O MESMO ARQUIVO DE QUANTIDADE, MAS COM O MODO DE ESCRITA, AONDE ELE SOBRESCREVE O VALOR JÁ EXISTENTE POR UM NOVO
  fprintf(ponteiro_qtd, "%d", quantidade + 1);                      // SALVANDO O NOVO VALOR NO ARQUIVO
  fclose(ponteiro_qtd);

  // SALVANDO UM NOVO MEDICO
  int id = quantidade + 1;
  fprintf(ponteiro_arq, "%d %d %d %s %f %d %d %d %d %d \n", id, unidade, consulta.crm, consulta.cpf, consulta.preco, consulta.data.dia, consulta.data.mes, consulta.data.ano, consulta.data.hora, consulta.data.minutos);
  fclose(ponteiro_arq);

  // LIMPANDO PONTEIRO
  free(ponteiro_qtd);
  free(ponteiro_arq);

  return 0; // RETORNO CASO TUDO TENHA OCORRIDO COMO ESPERADO
}

ArrayDeConsultas recuperarConsultas()
{
  FILE *ponteiro_arq, *ponteiro_qtd; // CRIANDO PONTEIRO FILE

  ponteiro_arq = fopen("./database/consultas/consultas.txt", "r");  // APONTANDO PARA O ARQUIVO DE consultas NO MODO DE LEITURA
  ponteiro_qtd = fopen("./database/consultas/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE CONSULTAS NO MODO DE LEITURA

  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // RECUPERANDO A QUANTIDADE DE CONSULTAS EXISTENTES

  Consulta consulta;             // STRUCT DE CONSULTA
  ArrayDeConsultas consultas;    // ARRAY DINAMICO DE CONSULTAS
  initArrayConsulta(&consultas); // INICIANDO O ARRAY EM 1

  // RECUPERANDO UNIDADE ATUAL
  int unidade = recuperarUnidadeAtual();
  int i;
  for (i = 0; i < quantidade; i++)
  { // PERCORRENDO DE 0 ATÉ A QUANTIDADE DE CONSULTAS
    // LENDO OS DADOS DOS CONSULTAS..
    fscanf(ponteiro_arq, "%d %d %d %s %f %d %d %d %d %d", &consulta.id, &consulta.unidade, &consulta.crm, &consulta.cpf, &consulta.preco, &consulta.data.dia, &consulta.data.mes, &consulta.data.ano, &consulta.data.hora, &consulta.data.minutos);

    if (consulta.unidade == unidade || unidade == 4)
    {
      // INSERINDO CADA CONSULTA EM UMA POSIÇÃO DO ARRAY DINÂMICO
      insertArrayConsulta(&consultas, consulta);
    }
  }

  // LIMPANDO PONTEIRO
  free(ponteiro_arq);
  free(ponteiro_qtd);

  return consultas;
}

int verificarHorario(int crm, Data data)
{
  ArrayDeConsultas consultas = recuperarConsultas();
  int unidade = recuperarUnidadeAtual();
  int i;
  for (i = 0; i < consultas.used; i++)
  {
    if (
        consultas.arrayDeConsultas[i].unidade == unidade &&
        consultas.arrayDeConsultas[i].crm == crm &&
        consultas.arrayDeConsultas[i].data.dia == data.dia &&
        consultas.arrayDeConsultas[i].data.mes == data.mes &&
        consultas.arrayDeConsultas[i].data.ano == data.ano &&
        consultas.arrayDeConsultas[i].data.hora == data.hora &&
        consultas.arrayDeConsultas[i].data.minutos == data.minutos)
    {
      return 1;
    }
  }
  return 0;
}

int cancelarConsulta(int id)
{
  ArrayDeConsultas consultas = recuperarConsultas();

  FILE *ponteiro_qtd;                                               // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/consultas/quantidade.txt", "w"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE CONSTULTAS NO MODO DE LEITURA

  FILE *ponteiro_arq;                                              // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/consultas/consultas.txt", "w"); // APONTANDO PARA O ARQUIVO  MEDICOS NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if (ponteiro_arq == NULL || ponteiro_qtd == NULL)
  { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  }

  int cont = 0;
  int i;
  for (i = 0; i < consultas.used; i++)
  {
    if (consultas.arrayDeConsultas[i].id != id)
    {
      cont++;
      fprintf(ponteiro_arq, "%d %d %d %s %f %d %d %d %d %d \n", consultas.arrayDeConsultas[i].id, consultas.arrayDeConsultas[i].unidade, consultas.arrayDeConsultas[i].crm, consultas.arrayDeConsultas[i].cpf, consultas.arrayDeConsultas[i].preco, consultas.arrayDeConsultas[i].data.dia, consultas.arrayDeConsultas[i].data.mes, consultas.arrayDeConsultas[i].data.ano, consultas.arrayDeConsultas[i].data.hora, consultas.arrayDeConsultas[i].data.minutos);
    }
  }
  fprintf(ponteiro_qtd, "%d", cont);

  fclose(ponteiro_qtd);
  fclose(ponteiro_arq);
  return 0;
}
