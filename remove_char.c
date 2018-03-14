//
//  remove_char.c
//  Test01
//
//  Created by 박민영 on 14/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 1024

int main(){
    char s1[SIZE];
    char s2[SIZE];
    int len;
    
    fgets(s1, SIZE, stdin);
    fgets(s2, SIZE, stdin);
    
    len = (int)strlen(s1);
    
    for(int i=0; i<len; i++){
        if (strchr(s2,s1[i]) == NULL){
            putchar(s1[i]);
        }
    }
    
    return 0;
}
