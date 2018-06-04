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

void isbn_printer(char *s){
    int last = 0;
    char *sc = s;

    for(int i = 1; i < 10 ; sc++, i++){
        putchar(*sc);
        last += i * ((*sc)-'0');
    }
    
    last = last % 11;
    if(last == 10) putchar('X');
    else printf("%d",last);
}

int main(){
    
    char *s;
    s = (char*)malloc(sizeof(char) * 15);
    fgets(s, 15, stdin);
    isbn_printer(s);
    free(s);
}
