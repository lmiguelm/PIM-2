#include "../headers/feedbacks.h"

int Feedbacks(){

    char feedback[300];
    int option;

    do {
        system("cls");
        printf("\n\n================ Feedbacks ================\n");
        
        printf("Digite seu feedback: ");
        fflush(stdin);
        gets(feedback);
        printf("\n==================================================\n");

        system("cls");
        printf("\n\n==================================================\n");
        printf("Feedback realizado com sucesso!!");
        printf("\n\n==================================================\n\n");

        return 0;

    } while(1==1);
}
