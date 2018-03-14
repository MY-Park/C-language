//
//  blank_to_tab.c
//  Test01
//
//  Created by 박민영 on 13/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    
    char buffer[4];
    char ch;
    int input = 0;
    int lastch = 0;
    
    while((ch=getchar())!=EOF){
        input++;
        if(ch == '\n'){
            buffer[input-1] = '\0';
            printf("%s\n",buffer);
            input = lastch = 0;
        }else if(ch == '\t'){
            buffer[input-1] = '\0';
            for(int i=0; i<lastch; i++){
                putchar(buffer[i]);
            }
            putchar('\t');
            input = lastch = 0;
        }else{
            if(input % 4 == 0){
                if(ch == ' '){
                    for(int i=0; i<lastch; i++){
                        putchar(buffer[i]);
                    }
                    putchar('\t');
                    input = lastch = 0;
                }else{
                    buffer[input-1] = ch;
                    printf("%s",buffer);
                    input = lastch = 0;
                }
            }else{
                buffer[input-1] = ch;
                if(ch != ' ') lastch = input;
            }
        }
    }
return 0;
}
