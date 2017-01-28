#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windef.h>

struct BSTNode{
    struct BSTNode*  leftChild;
    struct BSTNode*  rightChild;
    int data;
};

int findMin(struct BSTNode *node) {
    int min= node->data;
    if(node->leftChild != NULL) {
        min = min(min, findMin(node->leftChild));
    }
    if(node->rightChild != NULL) {
        min = min(min, findMin(node->rightChild));
    }
    return min;
}
struct BSTNode* Search(struct BSTNode* root, int data){
    if(root->data==data) return root;
    else if(data<=root->data) return Search(root->leftChild,data);
    else return Search(root->rightChild,data);
}
struct BSTNode* Delete(struct BSTNode* root, int data){
    if(root==NULL) return root;
    else if(data<root->data) root->leftChild=Delete(root->leftChild,data);
    else if(data>root->data) root->rightChild=Delete(root->rightChild,data);
    else{ // we have found the root to be deleted

        if(root->leftChild==NULL&&root->rightChild==NULL){
            free(root);
            root=NULL;
        }
        else if(root->leftChild==NULL){
            struct BSTNode* temp = root;
            root=root->rightChild;
            free(temp);
        }
        else if(root->rightChild==NULL){
            struct BSTNode* temp = root;
            root=root->leftChild;
            free(temp);
        }
        else{
            /* Algorithm to delete node having two children
             * - Find Minimum element in right subtree (Using) or Maximum element in left subtree both can replace the node to be deleted.
               - copy the value in targetted node
               - Delete duplicate from right subtree
             */
            struct BSTNode* temp = Search(root,findMin(root->rightChild));
            root->data=temp->data;
            root->rightChild=Delete(root->rightChild,temp->data);
        }
    }
    return root;

}

struct BSTNode* GetNewNode(int data){

    struct BSTNode* newNode = malloc(sizeof(struct BSTNode));
    newNode->data =data;
    newNode->leftChild=newNode->rightChild=NULL;
    return newNode;
}

struct BSTNode* Insert(struct BSTNode* root, int data){
    if(root==NULL){
        root=GetNewNode(data);
        return root;
    }
    else if(data<=root->data){
        root->leftChild=Insert(root->leftChild,data);
    }
    else {
        root->rightChild=Insert(root->rightChild,data);
    }

    return root;
}
/*
int FindMax(struct BSTNode* root){

    if(root->rightChild==NULL){
        // printf("TREE IS EMPTY\n");
        return root->data;
    }
    struct BSTNode* current = root;
    while(current->rightChild!=NULL){
        current=current->rightChild;
    }
    return current->data;
    //return FindMaxIterative(root->rightChild);
}
int FindMin(struct BSTNode* root){

    if(root->leftChild==NULL){
        // printf("TREE IS EMPTY\n");
        return root->data;
    }
    struct BSTNode* current = root;
    while(current->leftChild!=NULL){
        current=current->leftChild;
    }
    return current->data;
    //return FindMaxIterative(root->rightChild);
}
*/
int FindHeight(struct BSTNode* root){
    if(root==NULL){
        return -1;
    }
    return max(FindHeight(root->leftChild),FindHeight(root->rightChild))+1;
}

void preOrderTraversal(struct BSTNode* root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);
}

void InOrderTraversal(struct BSTNode* root){
    if(root==NULL)
        return;
    InOrderTraversal(root->leftChild);
    printf("%d ",root->data);
    InOrderTraversal(root->rightChild);
}

bool checkSameTree(struct BSTNode* root1, struct BSTNode* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    else if(root1!=NULL&&root2!=NULL){
        if(root1->data==root2->data){
            return true;
        }
        checkSameTree(root1->leftChild,root2->leftChild);
        checkSameTree(root1->rightChild,root2->rightChild);
    }
    return false;
}


bool IsBinarySearchTree(struct BSTNode* root);
//Inorder traversal of a BST always yields a sorted order

int main() {
    struct BSTNode* root = NULL; //Creating an empty tree
    root = Insert(root,15);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,5);
    root = Insert(root,12);
    root = Insert(root,35);
    root = Insert(root,20);
//    printf("%d\n",FindMaxIterative(root));
//
//    if(Search(root,8)){
//        printf("Present\n");
//    }
//
//    printf("%d",FindHeight(root));
    preOrderTraversal(root);
    Delete(root,15);
    printf("\n");
    InOrderTraversal(root);
}