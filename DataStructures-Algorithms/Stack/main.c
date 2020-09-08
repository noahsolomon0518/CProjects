#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    char name[10];
    struct person *next;
} person;


typedef struct stack{
    struct person *head;
} stack;

person pop(stack *stack1);
void iterateStack(stack *stack1);
void push(stack *stack1, char name[]);

int main()
{
    stack stack1;
    stack1.head = NULL;

    push(&stack1, "Noah");

    push(&stack1, "Matt");

    push(&stack1, "Anna");

    iterateStack(&stack1);

    pop(&stack1);

    iterateStack(&stack1);



    return 0;
}




void push(stack *stack1, char name[]){
    person *tmp = malloc(sizeof(person));
    strcpy(tmp->name,name);


    if(stack1->head==NULL){
        stack1->head = tmp;
        tmp->next = NULL;
    }

    else{
        person *tmp2= stack1->head;
        while(tmp2->next!=NULL){
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp;
        tmp->next = NULL;
    }

    printf("[PUSH]: %s \n\n", name);

}


void iterateStack(stack *stack1){
    person *tmp =  stack1->head;
    printf("[CURRENT STACK]: ");
    while(tmp!=NULL){
        printf("%s", tmp->name);
        if(tmp->next!=NULL){
            printf(" --> ");
        }else{
            printf("\n\n");
        }
        tmp = tmp->next;
    }
}



person pop(stack *stack1){

    person *tmp = stack1->head;
    person popPerson;
    person *tmp2;
    while((tmp->next)->next!=NULL){
        tmp = tmp->next;
    }
    tmp2 = tmp->next;
    popPerson = *(tmp->next);
    tmp->next = NULL;
    free(tmp2);
    printf("[POP]: %s \n\n", popPerson.name);
    return popPerson;
}
