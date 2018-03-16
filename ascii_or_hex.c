//
//  ascii_or_hex.c
//  Test01
//
//  Created by 박민영 on 16/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1024

int main(){
    char str[SIZE];
    int len;
    
    while(fgets(str, SIZE, stdin) != NULL){
        len = (int)strlen(str);
        for(int i=0; i<len; i++){
            if(isascii(str[i])) putchar(str[i]);
            else{
                printf("%02X ", str[i] & 0xFF);
            }
        }
    }
    return 0;
}
