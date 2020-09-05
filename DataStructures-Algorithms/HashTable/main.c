#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define getName(var)  #var
#define TABLEL 1000


typedef struct keyPair{
    char key[100];
    char element[100];
} keyPair;



void addKeyPair(keyPair *hashTable, char key[], char element[]);
int hashFunction(keyPair *hashTable,keyPair keyElementPair);
void searchKey(keyPair *hashTable, char key[]);

int main()
{
    keyPair hashTable[TABLEL] = {0};



    addKeyPair(hashTable , "Noah", "Solomon" );
    addKeyPair(hashTable , "haoN", "Solomon" );
    addKeyPair(hashTable , "Cats", "Dogs" );
    addKeyPair(hashTable , "Lily", "Cat" );
    addKeyPair(hashTable , "Jackson", "Cat" );
    addKeyPair(hashTable , "Missy", "Dog" );




    searchKey(hashTable, "Noah");
    searchKey(hashTable, "haoN");
    searchKey(hashTable, "Cats");
    searchKey(hashTable, "Cdats");



    return 0;
}


void addKeyPair(keyPair *hashTable, char key[], char element[]){
    printf("[ADDED ELEMENT]: Key--->%s    Value--->%s \n", key, element);
    keyPair tmp;
    strcpy(tmp.key, key);
    strcpy(tmp.element, element);
    int index = hashFunction(hashTable,tmp);
    strcpy((hashTable+index)->key, key);
    strcpy((hashTable+index)->element, element);



}



int hashFunction(keyPair *hashTable, keyPair keyElementPair){
    int hashVal = 0;
    for(int i = 0; i<strlen(keyElementPair.key); i++){
        hashVal += *(keyElementPair.key+i);
    }
    hashVal = hashVal*7%TABLEL;
    int linearProb = 0;
    int isEmpty = strcmp(hashTable+hashVal+linearProb,"");

    while(isEmpty!=0){
        linearProb+=1;
        isEmpty = strcmp(hashTable+hashVal+linearProb,"");
    }
    printf("Index = %d\n\n", hashVal+linearProb);


    return hashVal+linearProb;
}



void searchKey(keyPair *hashTable, char key[]){
    int hashVal =  0;
    for(int i = 0; i<strlen(key); i++){
        hashVal += key[i];
    }
    hashVal = hashVal*7%TABLEL;

    if(*(hashTable+hashVal)->key!=0){
        int offset = 0;
        int isKey = strcmp(key, (hashTable+hashVal+offset)->key);
        while(isKey!=0){
            offset+=1;
            isKey = strcmp(key, (hashTable+hashVal+offset)->key);
        }
        printf("[SEARCH KEY]:Index:%d    Key:%s    Value:%s \n\n",hashVal+offset, (hashTable+hashVal+offset)->key,(hashTable+hashVal+offset)->element);

    }else{
        printf("[ERROR]: %s is an invalid key\n\n", key);
    }


}













