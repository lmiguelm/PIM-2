typedef struct{
    int unidade;
    int avaliacao;
    char mensagem[500];
}Feedback;

typedef struct {
  Feedback *arrayDeFeedbacks;
  size_t used;
  size_t size;
} ArrayDeFeedbacks;