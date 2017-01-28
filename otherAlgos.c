//
// Created by ARPIT JOHRI on 21-10-2016.
//


/***************mostly ITERATIVE ONES***********************************/

#include <stdio.h>

int euclid_gcd(int a, int b){
    while (b!=0){
        int remainder = a%b;
        a=b;
        b=remainder;
    }
    return a;
}

//better n runs fast
int iFib(int n){
    if(n<=1)
        return n;
    int F1 = 0,F;
    int F2 = 1;
    for (int i = 2; i <=n; ++i) {
        F= F1+F2;
        F1=F2;
        F2=F;
    }

    return F;
}


void sieve(int primes[],int n){

    for (int i = 0; i <=n; ++i) {
        primes[i]=1;
    }
    primes[0]=0;
    primes[1]=0;
    for (int j = 2; j <=n; ++j) {
        if(primes[j]==1){
            for (int i = 2; j*i<=n; ++i) {
                primes[j*i]=0;
            }
        }
    }
}

int main(){
    int n=10;
    int primes[n+1];
    sieve(primes,n);
    for (int i = 0; i <=10; i++ ) {
        printf("%d ",primes[i]);
    }
}