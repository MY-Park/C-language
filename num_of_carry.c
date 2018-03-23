//
//  num_of_carry.c
//  Test01
//
//  Created by 박민영 on 24/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

int main(){
    
    int len, j, carry;
    int max_len = 0;
    
    char str[SIZE];
    char * ptr;
    int printIn;

    int zeroIn;
    int num_of_carry;
    
    while(1){
        
        printIn = 0;
        int num_1[SIZE] = {0};
        int num_2[SIZE] = {0};
        zeroIn = 0;
        
        carry = 0;
        num_of_carry = 0;
        
        fgets(str, SIZE, stdin);
        
        ptr = strtok(str, " ");
        len = (int)strlen(ptr);
        max_len = len;
        
        if(len == 1 && ptr[0]=='0'){
            len = 0;
            zeroIn = 1;
        }
        
        for(j=len-1; j>=0; j--){
            num_1[SIZE-1-j] = ptr[len-j-1]-'0';
        }
        
        ptr = strtok(NULL, "\n");
        len = (int)strlen(ptr);
        
        if(len > max_len) max_len = len;
        
        if(len == 1 && ptr[0]=='0'){
            len = 0;
            if(zeroIn){
                return 0;
            }
        }
        for(j=len-1; j>=0; j--){
            num_2[SIZE-1-j] = ptr[len-j-1]-'0';
        }
        
        for(j=0; j<=max_len+1; j++){
            num_1[SIZE-1-j] += carry;
            carry = (num_1[SIZE-1-j] + num_2[SIZE-1-j]) / 10;
            if(carry == 1) num_of_carry++;
            num_1[SIZE-1-j] = (num_1[SIZE-1-j] + num_2[SIZE-1-j]) % 10;
        }
        
        if(num_of_carry == 0) printf("No carry operation.\n");
        else if(num_of_carry == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",num_of_carry);
    }
    
    return 0;
}
