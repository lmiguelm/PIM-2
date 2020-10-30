void initArrayMedico(ArrayDeMedicos *a) {
  a->arrayDeMedicos = malloc(1 * sizeof(Medico));  // ALOCANDO ESPAÇO NA MEMÓRIA PARA O VALOR INICIAL DO ARRAY
  a->used = 0; // SETANDO O VALOR DO TAMANHO USADO
  a->size = 1; // SETANDO O TAMANHO ALOCADO
}

void insertArrayMedico(ArrayDeMedicos *a, Medico element) {
  if (a->used == a->size) { // VERIFICA SE O TAMANHO QUE ESTA SENDO USADO É IGUAL AO TAMANHO ALOCADO
    a->size *= 2;  // DUPLICANDO O TAMANHO
    a->arrayDeMedicos = realloc(a->arrayDeMedicos, a->size * sizeof(Medico)); // REALOCANDO O TAMANHO PARA O DOBRO DO ANTERIOR
  }
  a->arrayDeMedicos[a->used++] = element; // INSERINDO O ELEMENTO NO ARRAY
}

void FreeArrayMedico(ArrayDeMedicos *a) {
  // LIMPANDO
  free(a->arrayDeMedicos);
  a->arrayDeMedicos = NULL;
  a->used = a->size = 0;
}

int salvarMedico(Medico medico) {
  FILE *ponteiro_qtd; // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/medicos/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE MEDICOS NO MODO DE LEITURA
 
  FILE *ponteiro_arq; // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/medicos/medicos.txt", "a");// APONTANDO PARA O ARQUIVO  MEDICOS NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if(ponteiro_arq == NULL || ponteiro_qtd == NULL) { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  } 

  // SALVANDO UM NOVO MEDICO
  fprintf(ponteiro_arq, "%s %s %s %d \n", medico.nome, medico.sobrenome, medico.especialidade, medico.crm);
  fclose(ponteiro_arq);

  // INCREMENTANDO O NUMERO DE MEDICOS DE 1 EM 1
  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // LENDO O ARQUIVO DE QUANTIDADE DE MEDICOS E ARMAZENANDO O VALOR NA VARIAVEL 'QUANTIDADE'
  ponteiro_qtd = fopen("./database/medicos/quantidade.txt", "w"); // APONTANDO PARA O MESMO ARQUIVO DE QUANTIDADE, MAS COM O MODO DE ESCRITA, AONDE ELE SOBRESCREVE O VALOR JÁ EXISTENTE POR UM NOVO
  fprintf(ponteiro_qtd, "%d", quantidade+1); // SALVANDO O NOVO VALOR NO ARQUIVO
  fclose(ponteiro_qtd);

  return 0; // RETORNO CASO TUDO TENHA OCORRIDO COMO ESPERADO
}

ArrayDeMedicos recuperarMedicos() {
  FILE *ponteiro_arq, *ponteiro_qtd; // CRIANDO PONTEIRO FILE

  ponteiro_arq = fopen("./database/medicos/medicos.txt", "r"); // APONTANDO PARA O ARQUIVO DE MEDICOS NO MODO DE LEITURA
  ponteiro_qtd = fopen("./database/medicos/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE MEDICOS NO MODO DE LEITURA

  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // RECUPERANDO A QUANTIDADE DE MEDICOS EXISTENTES

  Medico medico; // STRUCT DE MEDICO
  ArrayDeMedicos medicos; // ARRAY DINAMICO DE MEDICOS
  initArrayMedico(&medicos); // INICIANDO O ARRAY EM 1

  for(int i = 0; i < quantidade; i++) { // PERCORRENDO DE 0 ATÉ A QUANTIDADE DE MEDICOS
    // LENDO OS DADOS DOS MEDICOS..
    fscanf(ponteiro_arq, "%s %s %s %d", &medico.nome, &medico.sobrenome, &medico.especialidade, &medico.crm);
    // INSERINDO CADA MEDICO EM UMA POSIÇÃO DO ARRAY DINÂMICO
    insertArrayMedico(&medicos, medico);
  }

  return medicos;
}

void listarMedicos(ArrayDeMedicos array) {
  for(int i = 0; i < array.used; i++) {
    printf("\n--------------------------------------------------");
    printf("\nNome: %s", array.arrayDeMedicos[i].nome);
    printf("\nSobrenome: %s", array.arrayDeMedicos[i].sobrenome);
    printf("\nEspecialidade: %s", array.arrayDeMedicos[i].especialidade);
    printf("\nCRM: %d", array.arrayDeMedicos[i].crm);
    printf("\n--------------------------------------------------\n");
  }
}