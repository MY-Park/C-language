//
//  WCSPC_2015D.c
//  Test01
//
//  Created by 박민영 on 05/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15000
#define ARR_SIZE 1000

int main(){
    
    int ori_freq[27] = {0};
    int freq[27] = {0};
    int enc[27] = {0};
    
    char temp;
    char *sp;
    int lines = 0;
    
    char *spa[ARR_SIZE];
    
    for(int i=0; i<ARR_SIZE; i++){
        spa[i] = (char*)malloc(sizeof(char) * SIZE);
    }
    
    for(int i=0; i<26; i++){
        scanf("%c %d\n", &temp, &ori_freq[i]);
    }
    int i = 0;
    
    while(fgets(spa[i], SIZE, stdin) != NULL){
        lines++;
        
        sp = spa[i];
        
        while(1){
            if(*sp == '\n' || *sp == '\0' || *sp == '\r'){
                ++i;
                break;
            }
            if(*sp >= 'a' && *sp <= 'z'){
                ++freq[*sp - 'a'];
            }
            sp++;
        }
    }
    
    for(int i=0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(freq[i] == 0) break;
            
            if(freq[i] == ori_freq[j]){
                enc[i] = i - j;
                break;
            }
        }
    }
    
    for(int i=0; i < lines; i++){
        for(sp = spa[i]; *sp != '\n' && *sp != '\0' && *sp != '\r'; ++sp){
            if(*sp >= 'a' && *sp <= 'z')
                putchar(*sp - enc[*sp - 'a']);
            else putchar(*sp);
        }
        putchar('\n');
    }
    
    return 0;
}
