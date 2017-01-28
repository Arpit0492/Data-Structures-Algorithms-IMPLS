//
// Created by ARPIT JOHRI on 11-10-2016.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; //pointer to node, stores address of the next node in list
};

struct Node* Insert(struct Node *head,int x){

    //malloc returns a pointer to the starting address of the memory block
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=head;
    head=newNode;
    return  head;
}

struct Node* InsertNth(struct Node *head, int x, int pos){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    if(pos==1){ // If we want to insert at the beginning
        newNode->next=head;
        head=newNode;
        return head;
    }
    struct Node* temp=head;
    while (pos-2>0){ // Traverse till the position one less or before where element has to be inserted
        temp=temp->next;
        pos--;
    }
    newNode->next=temp->next; //Then create links
    temp->next=newNode;

    return head;
}

struct Node* DeleteNth(struct Node *head, int pos){
    struct Node* temp1 = head;
    if(pos==1){
        head=head->next;
        free(temp1);
        return head;
    }

    while(pos-2>0){
        temp1=temp1->next; // after this loop temp1 points to our (n-1)th node
        pos--;
    }
    struct Node* temp2 = temp1->next; // temp2 points to our nth node
    temp1->next=temp1->next->next;
    free(temp2);
    return head;
}

struct Node* ReverseIterative(struct Node *head){
    struct Node *Prev, *Current, *Next;
    Current = head;
    Prev=NULL;
    while (Current!=NULL){
        Next = Current->next;
        Current->next = Prev;
        Prev = Current;
        Current = Next;
    }
    head = Prev;
    return head;
}

void ReverseRecursive(struct Node *p){
    if(p->next==NULL)
        //head=p;
        return;
    ReverseRecursive(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

int Search(struct Node* head,int x){
    if(head==NULL)
        return 0;

    int it=1;
    while (head->data!=x){
        head=head->next;
        if(head==NULL){
            return 0;
        }
        it++;
    }
    return it;
}

void PrintforR(struct Node *head){
    struct Node *temp = head;
    if(temp==NULL)
        return;
//    PrintbR(temp->next);
    printf("%d ", temp->data);
    PrintforR(temp->next);
}

void Print(struct Node *head){
    printf("List is: ");
    while (head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL; //empty list
    printf("Enter size of Linked List : ");
    int n,x;
    scanf("%d",&n);
    for (int i = 0; i <n; ++i) {
        scanf("%d",&x);
        head=Insert(head,x);
        Print(head);
        printf("\n");
    }

//    PrintforR(head);
//    head=InsertNth(head,9,1);
//    Print(head);
//    head=DeleteNth(head,5);
//    Print(head);
//    head=ReverseIterative(head);
//    Print(head);
//    printf("%d\n",Search(head,2));
}