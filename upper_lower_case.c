//
//  upper_lower_case.c
//  Test01
//
//  Created by 박민영 on 16/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024

int main(){
    char str[SIZE];
    char uplow[6];
    char out[SIZE];
    
    while(fgets(str, SIZE, stdin) != NULL){
        memcpy(uplow, &str, 5);
        uplow[5] = '\0';
        memcpy(out, &str[6], strlen(str)-5);
        out[strlen(str)-4] = '\0';
        
        if(strcmp(uplow, "upper") == 0){
            for(int i=0; i<strlen(out); i++){
                putchar(toupper(out[i]));
            }
        }else if(strcmp(uplow, "lower") == 0){
            for(int i=0; i<strlen(out); i++){
                putchar(tolower(out[i]));
            }
        }
    }
    return 0;
}
