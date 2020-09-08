#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person{
    char name[20];
    struct person *next;
};

struct queue{
    struct person *head;
};

void enqueue(struct queue *queue1, char name[]);
void iterateQueue(struct queue *queue1);
struct person *dequeue(struct queue *queue1);

int main()
{

    struct queue queue1;
    queue1.head = NULL;


    enqueue(&queue1, "Noah");
    enqueue(&queue1, "Matt");
    enqueue(&queue1, "Anna");

    iterateQueue(&queue1);

    dequeue(&queue1);

    iterateQueue(&queue1);

    enqueue(&queue1, "Lily");

    enqueue(&queue1, "Jackson");

    iterateQueue(&queue1);

    dequeue(&queue1);

    dequeue(&queue1);

    iterateQueue(&queue1);




    return 0;
}


void enqueue(struct queue *queue1, char name[]){
    struct person *tmp = malloc(sizeof(struct person));
    strcpy(tmp->name,name);
    //If queue empty
    if(queue1->head==0){
        tmp->next = NULL;
    }
    else{
        tmp->next = queue1->head;

    }

    queue1->head = tmp;

}



struct person *dequeue(struct queue *queue1){
    struct person *tmp = queue1->head;

    while((tmp->next)->next!=NULL){
        tmp = tmp->next;
    }
    printf("[DEQUEUE]: %s \n\n", (tmp->next)->name);
    free((tmp->next)->next);
    tmp->next = NULL;
}




void iterateQueue(struct queue *queue1){
    printf("[CURRENT QUEUE]: ");
    struct person *tmp = queue1->head;
    while(tmp->next!=0){
        printf("%s --> ", tmp->name);
        tmp = tmp->next;
    }
    printf("%s\n\n", tmp->name);
}


