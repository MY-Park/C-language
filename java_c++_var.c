//
//  java_c++_var.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int c_style(char []);
int j_style(char []);
void to_c_style(char []);
void to_j_style(char []);
void trim(char []);

int main(){
    char str[300];
    
    while(fgets(str, 300, stdin) != NULL){
        trim(str);
        
        if(c_style(str)){
            to_j_style(str);
        }else if(j_style(str)){
            to_c_style(str);
        }else
            printf("Error!\n");
    }
    
    return 0;
}

int c_style(char str[]){
    if(str[0] == '_') return 0;
    
    for(int i=0; i<strlen(str); i++){
        if(isupper(str[i])) return 0;
        else if(str[i] == '_' && (str[i+1] == '_' || str[i+1] == '\n' || str[i+1] == EOF || str[i+1] == '\0')) return 0;
    }
    return 1;
}

int j_style(char str[]){
    if(isupper(str[0])) return 0;
    
    for(int i=0; i<strlen(str); i++){
        if(str[i] == '_') return 0;
    }
    return 1;
}

void to_c_style(char str[]){
    for(int i=0; i<strlen(str); i++){
        if(isupper(str[i])) printf("_%c",tolower(str[i]));
        else putchar(str[i]);
    }
    putchar('\n');
}

void to_j_style(char str[]){
    for(int i=0; i<strlen(str); i++){
        if(str[i] == '_'){
            printf("%c",toupper(str[i+1]));
            i++;
        }else putchar(str[i]);
    }
    putchar('\n');
}

void trim(char str[]){
    int i = (int)strlen(str);
    for(; i>0; i--){
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != EOF && str[i] != '\0') break;
    }
    str[i+1] = '\0';
}
