//
//  name_dictionary.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150000

int main(){
    
    char *dic[SIZE];
    int N, dic_idx = 0;
    int str_idx;
    int name_idx;
    int strIn;
    
    scanf("%d",&N);
    getchar();
    char str[250];
    char name[250];
    
    for(int i=0; i<SIZE; i++){
        if((dic[i] = malloc(sizeof(char) * 250)) == NULL){
            printf("unable to allocate memory\n");
            return -1;
        }
    }
    
    for(int i=0; i<N; i++){
        fgets(str, 250, stdin);
        str_idx = name_idx = 0;
        strIn = 1;
        while(strIn){
            while(str[str_idx] != ' ' && str[str_idx] != '\n'){
                name[name_idx] = str[str_idx];
                str_idx++;
                name_idx++;
            }
            if(str[str_idx] == '\n') strIn = 0;
            
            name[name_idx] = '\0';
            str_idx++;
            name_idx = 0;
            
            strcpy(dic[dic_idx], name);
            dic_idx++;
        }
    }
    
    while(fgets(str, 250, stdin) != NULL){
        str[strlen(str)-1] = '\0';
        for(int i=0; i<dic_idx; i++){
            if(!strcmp(dic[i], str)){
                printf("yes\n");
                break;
            }else if(i == dic_idx-1) printf("no\n");
        }
        
    }
    
    return 0;
}
