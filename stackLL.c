//
// Created by ARPIT JOHRI on 01-11-2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

bool isEmpty(struct Node* top){
    if(top==NULL) return true;
    return false;
}

void Push(int x){
    struct Node* temp = malloc(sizeof(struct Node*));
    temp->data=x;
    temp->link=top;
    top=temp;
}

void Pop(){
    struct Node* temp;
    if(isEmpty(top)) return;
    temp=top;
    top=top->link;
    free(temp);
}



int main(){
    Push(2);
    Push(5);
    Push(7);
    Pop();
    while(top!=NULL){
        printf("%d\n",top->data);
        top=top->link;
    }
    printf(isEmpty(top)?"true":"false");
    printf("%d",top->data);
}