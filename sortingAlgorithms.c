//
// Created by ARPIT JOHRI on 10-10-2016.
//
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int A[], int n){
    for (int i = 0; i <n; ++i) {
        int iMin = i;
        for (int j = i+1; j <n; ++j) {
            if (A[j] < A[iMin]){
                iMin=j;
            }
        }
        int temp = A[i];
        A[i]=A[iMin];
        A[iMin]=temp;
    }
}

void BubbleSort(int A[], int n){
    for (int i = 0; i <n; ++i) {
        for (int j = i+1; j <n; ++j) {
            if(A[i]>A[j]){
                int temp = A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
}

void InsertionSort(int A[], int n){
    for (int i = 1; i <n; ++i) { // starting from second element(or first in UNSORTED) compare it with every element of SORTED REGION(Starting with single element array as it is already sorted)
        int temp = A[i];
        int j = i-1;
        while (j>=0&&A[j]>temp){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

void Merge(int left[],int nL,int right[],int nR,int A[]){
    int i=0,j=0,k=0;

    while (i<nL&&j<nR){
        if(left[i]<=right[j]){
            A[k] = left[i];
            i=i+1;
        }
        else{
            A[k] = right[j];
            j=j+1;
        }
        k=k+1;
    }

    while(i<nL){
        A[k]=left[i];
        i=i+1;
        k=k+1;
    }

    while (j<nR){
        A[k]=right[j];
        j=j+1;
        k=k+1;
    }


}
void MergeSort(int A[], int n){

    if(n<2)
        return;
    int mid = n/2;
    int left[mid];
    int right[n-mid];

    for (int i = 0; i <mid; ++i) {
        left[i]=A[i];
    }
    for (int i = mid; i <n; ++i) {
        right[i-mid]=A[i];
    }
    int nL = sizeof(left)/ sizeof(left[0]);
    int nR = sizeof(right)/ sizeof(right[0]);
    MergeSort(left,nL);
    MergeSort(right,nR);
    Merge(left,nL,right,nR,A);
}

int Partition(int *A, int start, int end){
    int pivot = A[end]; // Taking last element as pivot
    int pIndex = start; // And starting with first element as our partition index
    for (int i = start; i <end; ++i) {  // looping over the array from start and checking if element in consideration is less than the pivot or not if it is,Swap it.
        if(A[i]<=pivot){
            int temp = A[i];  // swap with partition index element if element is lesser than pivot
            A[i] = A[pIndex];
            A[pIndex]=temp;
            pIndex=pIndex+1;
        }
    }
    int temp = A[pIndex]; // And then at last swap the element present under partition Index with the pivot resulting in a fully partitioned array as per the pIndex.
    A[pIndex] = A[end];
    A[end]=temp;
    return pIndex;
}
void QuickSort(int *A, int start, int end){
    if(start<end){
        int pIndex = Partition(A,start,end); // Partitioning the array according to a pivot such that all the elements on the left side of it are less than and elements greater than it are on right.
        QuickSort(A,start,pIndex-1);
        QuickSort(A,pIndex+1,end);
    }
}


int main(){

    int A[] ={3,7,5,10,2,9,6,11,1,8,4};
    int n = sizeof(A)/ sizeof(A[0]);
    //printf("%d\n", sizeof(A));
    //SelectionSort(A,n);
    //BubbleSort(A,n);
    //InsertionSort(A,n);
    //MergeSort(A,n);
    QuickSort(A,0,n-1);
    for (int i = 0; i <n; ++i) {
        printf("%d ",A[i]);
    }

}

