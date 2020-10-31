#include "../headers/feedback.h"
#include "../util/bool.h"
#include "../models/feedback.c"

void FeedbackScreen(){

    Feedback feedback;

    do {

        system("cls");
        printf("\n\n================ Painel de Feedbacks ================\n");
        printf("\n[1] - Otimo");
        printf("\n[2] - Mediano");
        printf("\n[3] - Ruim");
        printf("\n\n[0] - Voltar");
        printf("\n\n==================================================\n\n");

        printf("Digite uma opcao: ");
        fflush(stdin);
        scanf("%d", &feedback.avaliacao);
        
        system("cls");
        if(feedback.avaliacao == 1){
            printf("Digite sua mensagem: ");
            fflush(stdin);
            gets(feedback.mensagem);

            if(salvarFeedback(feedback) == 0) { 
                system("cls");
                printf("\n\n==================================================\n");
                printf("feedback cadastrado com sucesso!");
                printf("\n\n==================================================\n\n");
                return;
            } else {
                system("cls");
                printf("\n\n==================================================\n");
                printf("Ops! Nao conseguimos realizar seu cadastro. Tente novamente");
                printf("\n\n==================================================\n\n");
                system("pause");
            }

        }else if(feedback.avaliacao == 2){  
            printf("Digite sua mensagem: ");
            fflush(stdin);
            gets(feedback.mensagem);

            if(salvarFeedback(feedback) == 0) { 
                system("cls");
                printf("\n\n==================================================\n");
                printf("feedback cadastrado com sucesso!");
                printf("\n\n==================================================\n\n");
                return;
            } else {
                system("cls");
                printf("\n\n==================================================\n");
                printf("Ops! Nao conseguimos realizar seu cadastro. Tente novamente");
                printf("\n\n==================================================\n\n");
                system("pause");
            }
        }else if(feedback.avaliacao == 3){
            printf("Digite sua mensagem: ");
            fflush(stdin);
            gets(feedback.mensagem);

            if(salvarFeedback(feedback) == 0) { 
                system("cls");
                printf("\n\n==================================================\n");
                printf("feedback cadastrado com sucesso!");
                printf("\n\n==================================================\n\n");
                return;
            } else {
                system("cls");
                printf("\n\n==================================================\n");
                printf("Ops! Nao conseguimos realizar seu cadastro. Tente novamente");
                printf("\n\n==================================================\n\n");
                system("pause");
            }

        }else if(feedback.avaliacao == 0){
            return;
        }

        system("cls");
        // printf("\n\n==================================================\n");
        // printf("Feedback realizado com sucesso!!");
        // printf("\n\n==================================================\n\n");

        // return 0;

    } while(true);
}