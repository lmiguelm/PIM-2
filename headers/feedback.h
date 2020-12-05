#include "../structs/feedback.h"
void FeedbackScreen();

int salvarFeedback(Feedback element);
ArrayDeFeedbacks recuperarFeedbacks();
void listarFeedbacks(ArrayDeFeedbacks a);

void initArrayFeedbacks(ArrayDeFeedbacks *a);
void insertArrayFeedbacks(ArrayDeFeedbacks *a, Feedback element);
void FreeArrayFeedbacks(ArrayDeFeedbacks *a);