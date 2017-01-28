//
// Created by ARPIT JOHRI on 14-11-2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5

int stack[size];
int top=-1;

void Push(int item){
    if(top==size-1){
        printf("FULL\n");
        return;
    }
    top++;
    stack[top]=item;
}

bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

void Pop(){
    if(isEmpty()){
        printf("EMPTY\n");
        return;
    }
    top--;
}

int Top(){
    return stack[top];
}

void Print(){
    for(int i=0; i<=top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){

    Push(3);
    Push(5);
    Push(7);
    Push(9);
    Push(11);
    Print();
    Push(13);
    Pop();
    Print();
    printf("%d",Top());

}