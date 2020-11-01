void initArrayFuncionario(ArrayDeFuncionarios *a) {
  a->arrayDeFuncionarios = malloc(1 * sizeof(Funcionario)); // ALOCANDO ESPAÇO NA MEMÓRIA PARA O VALOR INICIAL DO ARRAY
  a->used = 0; // SETANDO O VALOR DO TAMANHO USADO
  a->size = 1; // SETANDO O TAMANHO ALOCADO
}

void insertArrayFuncionario(ArrayDeFuncionarios *a, Funcionario element) {
  if (a->used == a->size) { // VERIFICA SE O TAMANHO QUE ESTA SENDO USADO É IGUAL AO TAMANHO ALOCADO
    a->size *= 2; // DUPLICANDO O TAMANHO
    a->arrayDeFuncionarios = realloc(a->arrayDeFuncionarios, a->size * sizeof(Funcionario)); // REALOCANDO O TAMANHO PARA O DOBRO DO ANTERIOR
  }
  a->arrayDeFuncionarios[a->used++] = element; // INSERINDO O ELEMENTO NO ARRAY
}

void FreeArrayFuncionario(ArrayDeFuncionarios *a) {
  // LIMPANDO
  free(a->arrayDeFuncionarios);
  a->arrayDeFuncionarios = NULL;
  a->used = a->size = 0;
}

int salvarFuncionario(Funcionario funcionario) {
  FILE *ponteiro_qtd; // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/funcionarios/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE FUNCIONARIOS NO MODO DE LEITURA
  
  FILE *ponteiro_arq; // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/funcionarios/funcionarios.txt", "a");// APONTANDO PARA O ARQUIVO  FUNCIONARIOS NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if(ponteiro_arq == NULL || ponteiro_qtd == NULL) { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  } 

  // RECUPERANDO UNIDADE ATUAL
  int unidade = recuperarUnidadeAtual();

  // SALVANDO UM NOVO FUNCIONARIO
  fprintf(ponteiro_arq, "%d %s %s %s %s %s \n", unidade, funcionario.nome, funcionario.sobrenome, funcionario.cpf, funcionario.email, funcionario.senha);
  fclose(ponteiro_arq);

  // INCREMENTANDO O NUMERO DE FUNCIONARIOS DE 1 EM 1
  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // LENDO O ARQUIVO DE QUANTIDADE DE FUNCIONARIOS E ARMAZENANDO O VALOR NA VARIAVEL 'QUANTIDADE'
  ponteiro_qtd = fopen("./database/funcionarios/quantidade.txt", "w"); // APONTANDO PARA O MESMO ARQUIVO DE QUANTIDADE, MAS COM O MODO DE ESCRITA, AONDE ELE SOBRESCREVE O VALOR JÁ EXISTENTE POR UM NOVO
  fprintf(ponteiro_qtd, "%d", quantidade+1); // SALVANDO O NOVO VALOR NO ARQUIVO
  fclose(ponteiro_qtd);

  // LIMPANDO PONTEIRO
  free(ponteiro_qtd);
  free(ponteiro_arq);

  return 0; // RETORNO CASO TUDO TENHA OCORRIDO COMO ESPERADO
}

ArrayDeFuncionarios recuperarFuncionarios() {
  FILE *ponteiro_arq, *ponteiro_qtd; // CRIANDO PONTEIRO FILE

  ponteiro_arq = fopen("./database/funcionarios/funcionarios.txt", "r"); // APONTANDO PARA O ARQUIVO DE FUNCIONARIOS NO MODO DE LEITURA
  ponteiro_qtd = fopen("./database/funcionarios/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE FUNCIONARIOS NO MODO DE LEITURA

  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // RECUPERANDO A QUANTIDADE DE FUNCIONARIOS EXISTENTES

  Funcionario funcionario; // STRUCT DE FUNCIONARIO
  ArrayDeFuncionarios funcionarios; // ARRAY DINAMICO DE FUNCIONARIOS
  initArrayFuncionario(&funcionarios); // INICIANDO O ARRAY EM 1

  // RECUPERANDO UNIDADE ATUAL
  int unidade = recuperarUnidadeAtual();

  for(int i = 0; i < quantidade; i++) { // PERCORRENDO DE 0 ATÉ A QUANTIDADE DE FUNCIONARIOS
    // LENDO OS DADOS DOS FUNCIONARIOS..
    fscanf(ponteiro_arq, "%d %s %s %s %s %s", &funcionario.unidade, &funcionario.nome, &funcionario.sobrenome, &funcionario.cpf, &funcionario.email, &funcionario.senha);

    if(funcionario.unidade == unidade) {
      // INSERINDO CADA FUNCIONARIO EM UMA POSIÇÃO DO ARRAY DINÂMICO
      insertArrayFuncionario(&funcionarios, funcionario);
    }
  }

  // LIMPANDO PONTEIRO
  free(ponteiro_arq);
  free(ponteiro_qtd);

  return funcionarios;
}

int validarLogin(char email[100], char senha[100]) {
  ArrayDeFuncionarios f = recuperarFuncionarios();
  int unidade = recuperarUnidadeAtual();
  
  for(int i = 0; i < f.used; i++) {
    if (strcmp(email, f.arrayDeFuncionarios[i].email) == 0 && strcmp(senha, f.arrayDeFuncionarios[i].senha) == 0 && f.arrayDeFuncionarios[i].unidade == unidade) {
      return 0;
    }
  }
  return 1;
}