//
//  fibonacci.c
//  Test01
//
//  Created by 박민영 on 22/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(){
    int carry = 0;
    int k;
    
    int num[2][SIZE] = {0};
    int N;
    int printIn = 0;
    scanf("%d",&N);
    
    if(N == 1 || N == 2) {
        printf("%d",1);
        return 0;
    }
    
    num[0][0] = num[1][0] = 1;
    
    for(int i=3; i<=N; i++){
        if(i % 2 == 1){
            for(int j=0; j<SIZE; j++){
                num[0][j] += carry;
                carry = (num[0][j] + num[1][j]) / 10;
                num[0][j] = (num[0][j] + num[1][j]) % 10;
            }
        }else{
            for(int j=0; j<SIZE; j++){
                num[1][j] += carry;
                carry = (num[0][j] + num[1][j]) / 10;
                num[1][j] = (num[0][j] + num[1][j]) % 10;
            }
        }
    }
    
    if(N % 2 == 0){
        k = 1;
    }else k = 0;
    
    for(int i=SIZE-1; i>=0; i--){
        if(num[k][i]!=0 && !printIn){
            printIn = 1;
            putchar('0'+num[k][i]);
            continue;
        }
        else if(printIn){
            putchar('0'+num[k][i]);
        }
    }
    
    return 0;
}

