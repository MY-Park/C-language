//
//  GCD.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int gcd(int, int);

int main(){
    int t, n1, n2;
    scanf("%d",&t);
    
    for(; t > 0; t--){
        scanf("%d %d", &n1, &n2);
        printf("%d\n", gcd(n1, n2));
    }
    return 0;
}

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
