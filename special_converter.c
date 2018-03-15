//
//  special_converer.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    char ch;
    
    while((ch = getchar())!=EOF){
        if(ch == '\n') printf("%s","\\n");
        else if(ch == '\t') printf("%s","\\t");
        else if(ch == '\b') printf("%s","\\b");
        else putchar(ch);
    }
    return 0;
}
