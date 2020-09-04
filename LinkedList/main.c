#include <stdio.h>
#include <stdlib.h>

struct person  {
    int age;
    struct person *next;
    char *name;
};

struct person *showLinkedList(struct person *head);
struct person *intializeLinkedList(struct person *pPeople, int size);
struct person * getIndex(struct person *head, int index);


int main()


{
    struct person Noah;
    struct person Matt;
    struct person Anna;
    Noah.age = 21;
    Matt.age = 23;
    Anna.age = 18;
    Noah.name = "Noah";
    Anna.name = "Anna";
    Matt.name = "Matt";
    struct person allPeople[3] = {Noah,Matt,Anna};
    struct person *head = intializeLinkedList(allPeople,3);
    showLinkedList(head);
    getIndex(head, 2);
    getIndex(head, 3);
    getIndex(head, 0);


    struct person Lily;
    Lily.name = "Lily";
    Lily.age = 15;
    insertAfter(getIndex(head, 0), &Lily);

    showLinkedList(head);


    printf("\n");



    return 0;
}




struct person *intializeLinkedList(struct person *pPeople, int size){
    printf("INTIALIZATION\n");
    for(int i = 0; i<size;i++){
        if(i<(size-1)){
            (pPeople+i)->next = (pPeople+i+1);
            printf("%s is %d years old. Next is %s\n", (pPeople+i)->name, (pPeople+i)->age, ((pPeople+i)->next)->name);
        }
        if(i==(size-1)){
            (pPeople+i)->next = NULL;
            printf("%s is %d years old. Next is %s\n", (pPeople+i)->name, (pPeople+i)->age, ((pPeople+i)->next));

        }
    }

    return pPeople;

}



struct person *showLinkedList(struct person *head){
    printf("\n\nLINKED LIST\n");
    struct person *tmp = head;
    int i = 0;
    while(tmp!=NULL){
        printf("[index %d]:%s --- %d \n", i,tmp->name, tmp->age);
        tmp = tmp->next;
        i+=1;
    }
}


struct person * getIndex(struct person *head, int index){
    struct person *tmp = head;
    for(int i = 0; i<index; i++){
        if(tmp->next){
            tmp = tmp->next;
        }else{
            tmp = NULL;
        }
    }

    printf("\n\nGet index %d: ", index);

    if(tmp){
        printf("%s --- %d", tmp->name,tmp->age);
    }else{
        printf("[ERROR] -> Index out of range");
    }
    return tmp;
}



void insertAfter(struct person *precedingPerson, struct person *newPerson){
    newPerson->next = precedingPerson->next;
    precedingPerson->next = newPerson;
}












