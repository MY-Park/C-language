//
//  coupled_operator.c
//  Test01
//
//  Created by 박민영 on 14/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    int N = 10;
    scanf("%d",&N);
    getchar();
    char str[SIZE];
    int len = 0;
    
    int paren;
    int brak;
    int brace;
    
    for(int i=0; i<N; i++){
        fgets(str, SIZE, stdin);
        len = (int)strlen(str);
        paren = brak = brace = 0;
        
        for(int j=0; j<len; j++){
            switch (str[j]) {
                case '(':
                    paren++;
                    break;
                case ')':
                    paren--;
                    break;
                case '[':
                    brak++;
                    break;
                case ']':
                    brak--;
                    break;
                case '{':
                    brace++;
                    break;
                case '}':
                    brace--;
                    break;
                default:
                    break;
            }
            if(paren < 0 || brak < 0 || brace < 0){
                printf("%c\n",'N');
                break;
            }else if(j == len-1) {
                if(paren == 0 && brak == 0 && brace == 0) printf("%c\n",'Y');
                else printf("%c\n",'N');
            }
        }
    }
    return 0;
}
