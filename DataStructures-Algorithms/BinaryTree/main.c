#include <stdio.h>
#include <stdlib.h>



typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct Tree{
    struct Node *root;
} Tree;

void insertNode(Node *parent, Node *child);
void addNode(Tree *tree1, int num);
void traversal(Tree *tree1);
void printInOrder(Node *node1);
void search(Tree *tree1, int num);

int main()
{
    Tree tree1;
    tree1.root = NULL;
    addNode(&tree1, 10);
    addNode(&tree1, 16);
    addNode(&tree1, 9);
    addNode(&tree1, 11);
    addNode(&tree1, 199);
    addNode(&tree1, 2);
    traversal(&tree1);
    search(&tree1, 90);

    search(&tree1, 199);

    search(&tree1, 16);

    search(&tree1, 2);



    return 0;
}



void addNode(Tree *tree1, int num){
    Node *tmp = malloc(sizeof(Node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = num;

    if(tree1->root==NULL){
        tree1->root = tmp;
    }else{
        //recursively insert Node
        printf("[INSERT NUMBER]: %d\n\n", tmp->data);
        insertNode(tree1->root, tmp);
    }

}



void insertNode(Node *parent, Node *child){
    if(parent->data > child->data){
        if(parent->left == NULL){
            parent->left = child;
        }else{
            insertNode(parent->left, child);
        }
    }else{
        if(parent->right == NULL){
            parent->right = child;
        }else{
            insertNode(parent->right, child);
        }
    }

}


void traversal(Tree *tree1){
    printf("[TREE TRAVERSAL]: ");
    Node *tmp = tree1->root;
    printInOrder(tmp);
    printf("\n\n");
}



void printInOrder(Node *node1){
    if(node1==NULL){
        return;
    }

    printInOrder(node1->left);

    printf("%d --- ", node1->data);

    printInOrder(node1->right);



}



void search(Tree *tree1, int num){
    Node *tmp = tree1->root;
    while(tmp->right!=NULL || tmp->left!=NULL){
        if(num < tmp->data){
            tmp = tmp->left;
        }else{
            tmp = tmp->right;
        }
    }
    if(tmp->data == num){
        printf("[TREE SEARCH]: Found %d\n\n", num);
    }else{
        printf("[TREE SEARCH]: %d not found\n\n");
    }
}

