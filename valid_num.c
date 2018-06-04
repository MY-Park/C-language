//
//  valid_num.c
//  Test01
//
//  Created by 박민영 on 04/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void valid_check(char *s){
    int sum = 0;
    int temp_num;
    int len;
    char *sc = s;
    
    if(*sc == '4' || *sc == '5' || *sc == '6'){
    }else if(*sc == '3' && *(sc++) == '7'){
    }else{
        printf("Invalid\n");
        return;
    }
    for(len = 0; *sc != '\0'; sc++, len++)
        ;
    
    len--;
    if(len < 13 || len > 16){
        printf("Invalid\n");
        return;
    }

    int round = 0;
    for(sc = sc - 2; sc != s -1 ; sc--){
        round++;
        
        if(round % 2)
            sum += *sc - '0';
        else{
            temp_num = (*sc - '0') * 2;
            sum += temp_num % 10;
            sum += temp_num / 10;
        }
    }
    if(!(sum % 10)) printf("Valid\n");
    else printf("Invalid\n");
}

int main(){
    
    int t;
    scanf("%d", &t);
    getchar();
    
    for(int i = 0; i<t; i++){
        char *s;
        s = (char*)malloc(sizeof(char) * 21);
        fgets(s, 20, stdin);
        valid_check(s);
        free(s);
    }
}
