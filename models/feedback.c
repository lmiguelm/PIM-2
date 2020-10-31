void initArrayFeedbacks(ArrayDeFeedbacks *a) {
  a->arrayDeFeedbacks = malloc(1 * sizeof(Feedback)); // ALOCANDO ESPAÇO NA MEMÓRIA PARA O VALOR INICIAL DO ARRAY
  a->used = 0; // SETANDO O VALOR DO TAMANHO USADO
  a->size = 1; // SETANDO O TAMANHO ALOCADO
}

void insertArrayFeedbacks(ArrayDeFeedbacks *a, Feedback element) {
  if (a->used == a->size) { // VERIFICA SE O TAMANHO QUE ESTA SENDO USADO É IGUAL AO TAMANHO ALOCADO
    a->size *= 2; // DUPLICANDO O TAMANHO
    a->arrayDeFeedbacks = realloc(a->arrayDeFeedbacks, a->size * sizeof(Feedback)); // REALOCANDO O TAMANHO PARA O DOBRO DO ANTERIOR
  }
  a->arrayDeFeedbacks[a->used++] = element; // INSERINDO O ELEMENTO NO ARRAY
}

void FreeArrayFeedbacks(ArrayDeFeedbacks *a) {
  // LIMPANDO
  free(a->arrayDeFeedbacks);
  a->arrayDeFeedbacks = NULL;
  a->used = a->size = 0;
}

int salvarFeedback(Feedback feedback) {
  FILE *ponteiro_qtd; // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/feedbacks/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE FUNCIONARIOS NO MODO DE LEITURA
 
  FILE *ponteiro_arq; // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/feedbacks/feedbacks.txt", "a");// APONTANDO PARA O ARQUIVO  FUNCIONARIOS NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if(ponteiro_arq == NULL || ponteiro_qtd == NULL) { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  } 

  fprintf(ponteiro_arq, "%d %s\n", feedback.avaliacao, feedback.mensagem);
  fclose(ponteiro_arq);

  // INCREMENTANDO O NUMERO DE FUNCIONARIOS DE 1 EM 1
  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // LENDO O ARQUIVO DE QUANTIDADE DE FUNCIONARIOS E ARMAZENANDO O VALOR NA VARIAVEL 'QUANTIDADE'
  ponteiro_qtd = fopen("./database/feedbacks/quantidade.txt", "w"); // APONTANDO PARA O MESMO ARQUIVO DE QUANTIDADE, MAS COM O MODO DE ESCRITA, AONDE ELE SOBRESCREVE O VALOR JÁ EXISTENTE POR UM NOVO
  fprintf(ponteiro_qtd, "%d", quantidade+1); // SALVANDO O NOVO VALOR NO ARQUIVO
  fclose(ponteiro_qtd);

  // LIMPANDO PONTEIRO
  free(ponteiro_qtd);
  free(ponteiro_arq);

  return 0; // RETORNO CASO TUDO TENHA OCORRIDO COMO ESPERADO
}

ArrayDeFeedbacks recuperarFeedbacks() {
  FILE *ponteiro_arq, *ponteiro_qtd; // CRIANDO PONTEIRO FILE

  ponteiro_arq = fopen("./database/feedbacks/feedbacks.txt", "r"); // APONTANDO PARA O ARQUIVO DE FUNCIONARIOS NO MODO DE LEITURA
  ponteiro_qtd = fopen("./database/feedbacks/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE FUNCIONARIOS NO MODO DE LEITURA

  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // RECUPERANDO A QUANTIDADE DE FUNCIONARIOS EXISTENTES

  Feedback feedback; // STRUCT DE FUNCIONARIO
  ArrayDeFeedbacks feedbacks; // ARRAY DINAMICO DE FUNCIONARIOS
  initArrayFeedbacks(&feedbacks); // INICIANDO O ARRAY EM 1

  for(int i = 0; i < quantidade; i++) { // PERCORRENDO DE 0 ATÉ A QUANTIDADE DE FUNCIONARIOS
    // LENDO OS DADOS DOS FUNCIONARIOS..
    fscanf(ponteiro_arq, "%d %s", &feedback.avaliacao, &feedback.mensagem);
    // INSERINDO CADA FUNCIONARIO EM UMA POSIÇÃO DO ARRAY DINÂMICO
    insertArrayFeedbacks(&feedbacks,feedback);
  }

  // LIMPANDO PONTEIRO
  free(ponteiro_arq);
  free(ponteiro_qtd);

  return feedbacks;
}

void listarFeedbacks(ArrayDeFeedbacks array) {
  for(int i = 0; i < array.used; i++) {
    printf("\n--------------------------------------------------");
    printf("\nAvaliacao: %d", array.arrayDeFeedbacks[i].avaliacao);
    printf("\nMensagem: %s", array.arrayDeFeedbacks[i].mensagem);
    printf("\n--------------------------------------------------\n");
  }
  FreeArrayFeedbacks(&array);
}