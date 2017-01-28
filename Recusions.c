//
// Created by ARPIT JOHRI on 10-10-2016.
//

#include <stdio.h>


int Factorial(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return n*Factorial(n-1);
}

int euclid_gcd_recursive(int a ,int b){
    return b==0?a:euclid_gcd_recursive(b,a%b);
}

/*
 * THIS GROWS EXPONENTIALLY
 */
int rFib(int n){
    if(n<=1)
        return n;
    else
        return rFib(n-1)+rFib(n-2);
}

int main(){

    int n;
    scanf("%d",&n);

    printf("%d",rFib(n));

}