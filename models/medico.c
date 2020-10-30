void initArrayMedico(ArrayDeMedicos *a) {
  a->arrayDeMedicos = malloc(1 * sizeof(Medico));
  a->used = 0;
  a->size = 1;
}

void insertArrayMedico(ArrayDeMedicos *a, Medico element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->arrayDeMedicos = realloc(a->arrayDeMedicos, a->size * sizeof(Medico));
  }
  a->arrayDeMedicos[a->used++] = element;
}

void FreeArrayMedico(ArrayDeMedicos *a) {
  free(a->arrayDeMedicos);
  a->arrayDeMedicos = NULL;
  a->used = a->size = 0;
}

int salvarMedico(Medico medico) {
  FILE *ponteiro_qtd; // CRIANDO PONTEIRO FILE
  ponteiro_qtd = fopen("./database/medicos/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE PACIENTES NO MODO DE LEITURA
 
  FILE *ponteiro_arq; // CRIANDO PONTEIRO FILE
  ponteiro_arq = fopen("./database/medicos/medicos.txt", "a");// APONTANDO PARA O ARQUIVO  PACIENTES NO MODO APPEND, ONDE ADICIONARÁ UMA NOVA LINHA NO CONTEUDO JÁ EXISTENTE

  if(ponteiro_arq == NULL || ponteiro_qtd == NULL) { // VERIFICANDO SE OS PONTEIROS NÃO APONTARAM PARA OS ARQUIVOS
    printf("Erro na arbertura do arquivo");
    return 1; // CASO NÃO, RETORNA 1 COMO ERRO
  } 

  // SALVANDO UM NOVO PACIENTE
  fprintf(ponteiro_arq, "%s %s %s %d \n", medico.nome, medico.sobrenome, medico.especialidade, medico.crm);
  fclose(ponteiro_arq);

  // INCREMENTANDO O NUMERO DE PACIENTES DE 1 EM 1
  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // LENDO O ARQUIVO DE QUANTIDADE DE PACIENTES E ARMAZENANDO O VALOR NA VARIAVEL 'QUANTIDADE'
  ponteiro_qtd = fopen("./database/medicos/quantidade.txt", "w"); // APONTANDO PARA O MESMO ARQUIVO DE QUANTIDADE, MAS COM O MODO DE ESCRITA, AONDE ELE SOBRESCREVE O VALOR JÁ EXISTENTE POR UM NOVO
  fprintf(ponteiro_qtd, "%d", quantidade+1); // SALVANDO O NOVO VALOR NO ARQUIVO
  fclose(ponteiro_qtd);

  return 0; // RETORNO CASO TUDO TENHA OCORRIDO COMO ESPERADO
}

ArrayDeMedicos recuperarMedicos() {
  FILE *ponteiro_arq, *ponteiro_qtd; // CRIANDO PONTEIRO FILE

  ponteiro_arq = fopen("./database/medicos/medicos.txt", "r"); // APONTANDO PARA O ARQUIVO DE PACIENTES NO MODO DE LEITURA
  ponteiro_qtd = fopen("./database/medicos/quantidade.txt", "r"); // APONTANDO PARA O ARQUIVO DE QUANTIDADE DE PACIENTES NO MODO DE LEITURA

  int quantidade;
  fscanf(ponteiro_qtd, "%d", &quantidade); // RECUPERANDO A QUANTIDADE DE PACIENTES EXISTENTES

  Medico medico; // STRUCT DE PACIENTE
  ArrayDeMedicos medicos; // ARRAY DINAMICO DE PACIENTES
  initArrayMedico(&medicos); // INICIANDO O ARRAY EM 1

  for(int i = 0; i < quantidade; i++) { // PERCORRENDO DE 0 ATÉ A QUANTIDADE DE PACIENTES
    // LENDO OS DADOS DOS PACIENTES..
    fscanf(ponteiro_arq, "%s %s %s %d", &medico.nome, &medico.sobrenome, &medico.especialidade, &medico.crm);
    // INSERINDO CADA PACIENTE EM UMA POSIÇÃO DO ARRAY DINÂMICO
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