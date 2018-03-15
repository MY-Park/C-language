//
//  special_converer2.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    char ch;
    char str[SIZE];
    int len;
    
    fgets(str, SIZE, stdin);
    len = (int)strlen(str);
    
    for(int i=0; i<len; i++){
        if(str[i] == '\\'){
            if(str[i+1] == 't'){
                putchar('\t');
                i++;
            }else if(str[i+1] == 'n'){
                putchar('\n');
                i++;
            }else if(str[i+1] == 'b'){
                putchar('\b');
                i++;
            }else{
                putchar(str[i]);
            }
        }else{
            putchar(str[i]);
        }
    }
    return 0;
}
