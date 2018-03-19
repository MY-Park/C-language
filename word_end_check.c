//
//  word_end_check.c
//  Test01
//
//  Created by 박민영 on 19/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    char ch;
    scanf("%c\n",&ch);
    
    char str[SIZE];
    fgets(str, SIZE, stdin);
    int len = (int)strlen(str);
    
    if(ch == str[len-2]) putchar('1');
    else putchar('0');
    
    return 0;
}
