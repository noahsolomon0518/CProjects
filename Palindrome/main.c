#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *generateRandText(int nLetters);
char *findPalindrome(char *letters);

int main()
{
    char *letters = generateRandText(100000);
    findPalindrome(letters);





    return 0;
}



/*
void fileContent(){
    char firstLine[50];
    FILE *fp = fopen("palindrome.txt", "r");
    fgets(firstLine, 50, fp);
    printf(firstLine);
    fclose(fp);


}*/



char *generateRandText(int nLetters){
    char *letters = malloc(2*nLetters*sizeof(char));
    char tmpStr[2];
    for(int i = 0; i<nLetters; i++){
        tmpStr[0] = rand()%(122-97)+97;
        tmpStr[1] = '\0';
        strcat(letters, &tmpStr);
    }
    tmpStr[0] = 3;
    tmpStr[1] = '\0';
    strncat(letters, &tmpStr,1);


    //fileContent();

    return letters;

}



char *findPalindrome(char *letters){
    int i = 0;
    char *pRight;
    char *pLeft;
    char curWord[100];
    int topZ = 1;
    while((*(letters+i))!=0){
        int z = 0;
        pRight = letters + i+1;
        pLeft = letters + i-1;
        while(*pLeft==*pRight){
            pLeft -=1;
            pRight +=1;
            z+=1;
        }
        if(z>=topZ){
            for(int q = i-z; q<i+z+1;q++){
                printf("%c", *(letters+q));
            }
            topZ=z;
        printf("\n");
        }


        i+=1;


    }

}




