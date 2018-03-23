//
//  binary_add.c
//  Test01
//
//  Created by 박민영 on 23/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

int main(){
    int N;
    scanf("%d\n", &N);
    
    int len, j, carry;
    int max_len = 0;
    
    char str[SIZE];
    char * ptr;
    int printIn;

    int zeroIn;
    
    for(int i=1; i<=N; i++){
        
        int num_1[SIZE] = {0};
        int num_2[SIZE] = {0};
        zeroIn = 0;
        
        carry = 0;
        printIn = 0;
        fgets(str, SIZE, stdin);
        
        ptr = strtok(str, " ");
        len = (int)strlen(ptr);
        max_len = len;
        
        if(len == 1 && ptr[0]=='0'){
            len = 0;
            zeroIn = 1;
        }
        
        for(j=len-1; j>=0; j--){
            if(ptr[len-j-1] == '1' ) num_1[SIZE-1-j] = 1;
            else num_1[SIZE-1-j] = 0;
        }
        
        ptr = strtok(NULL, "\n");
        len = (int)strlen(ptr);
        
        if(len > max_len) max_len = len;
        
        if(len == 1 && ptr[0]=='0'){
            len = 0;
            if(zeroIn){
                printf("%d %d\n", i, 0);
                continue;
            }
        }
        for(j=len-1; j>=0; j--){
            if(ptr[len-j-1] == '1' ) num_2[SIZE-1-j] = 1;
            else num_2[SIZE-1-j] = 0;
        }
        
        for(j=0; j<=max_len+1; j++){
            num_1[SIZE-1-j] += carry;
            carry = (num_1[SIZE-1-j] + num_2[SIZE-1-j]) / 2;
            num_1[SIZE-1-j] = (num_1[SIZE-1-j] + num_2[SIZE-1-j]) % 2;
        }
        
        printf("%d ",i);
        for(j = max_len + 1; j >= 0; j--){
            if(printIn){
                putchar('0'+num_1[SIZE-1-j]);
            }else if(!printIn){
                if(num_1[SIZE-1-j] != 0){
                    putchar('1');
                    printIn = 1;
                }
            }
        }
        putchar('\n');
    }
    
    return 0;
}
