//
//  reverse_num.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverse(char []);

int main(){
    int t;
    char str[10];
    
    scanf("%d\n", &t);
    for(; t>0; t--){
        fgets(str, 10, stdin);
        reverse(str);
        printf("%s", str);
    }
    return 0;
}

void reverse(char str[]){
    int i = 0, j = (int)strlen(str) - 2, temp;
    
    for(; i < j; i++, j--){
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}
