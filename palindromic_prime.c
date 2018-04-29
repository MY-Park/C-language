//
//  palindromic_prime.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int rev_int(int);
int isprime(int);
int ispalin(int);

int main(){
    int num, M, t;
    scanf("%d",&t);
    
    for(; t>0; t--){
        scanf("%d",&M);
        num = 0;
        
        for(int i=2; i<=M; i++)
            if(ispalin(i) && isprime(i)) num++;
        
        printf("%d\n", num);
    }
    
    return 0;
}

int rev_int(int n){
    int rev = 0;
    do{
        rev = rev * 10 + n % 10;
    }while((n /= 10) != 0);
    
    return rev;
}

int isprime(int n){
    if(n == 2) return 1;
    if(n == 1) return 0;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int ispalin(int n){
    if(n == rev_int(n)) return 1;
    else return 0;
}
