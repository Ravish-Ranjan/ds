#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Node{
    int value;
    struct Node* left ;
    struct Node* right;
};

struct Tree{
    struct Node* root;
};

struct Tree* t;

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

char* inorder(struct Node* root){
    if (root == NULL){
        return "\0";
    }
    char* pre = inorder(root->left);
    char* post = inorder(root->right);
    strcat(pre,root->value);
    strcat(pre,post);

    return pre;
}

void insert(int value){
    struct Node* newNode = createNode(value);
    if (t->root == NULL){
        t->root = newNode;
        return;
    }
    struct Node* r = t->root;
    while (r != NULL){
        if (value < r->value){
            r = r->left;
        } else if (value > r->value){
            r = r->right;
        }
    }
    r = newNode;
}

int main(){
    t = (struct Tree*)malloc(sizeof(struct Tree));
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    free(t);
    return 0;
}