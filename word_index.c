//
//  word_index.c
//  Test01
//
//  Created by 박민영 on 18/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10000

struct Word{
    char name[100];
    int line[100];
    int line_idx;
};

int main(){
    
    char *discard_words[] = {"the", "of", "and", "to", "a", "in", "is", "you", "are", "for"};
    
    struct Word w[SIZE];
    char str[1024];
    char inWord[1024];
    struct Word tempWord;
    char discard_check_word[1024];
    
    int max_idx = 0;
    
    int len, str_idx, j, w_idx = 0;
    int strIn = 1;
    int cmtLine = 0;
    int cmtIn = 0;
    int temp_idx = 0;
    int line = 0;
    int discard = 0;
    int line_idx = 0;
    
    while(fgets(str, 1024, stdin) != NULL){
        line++;
        str_idx = 0;
        len = (int)strlen(str);
        cmtIn = cmtLine = 0;
        strIn = 1;
        
        while(strIn){
            inWord[0] = '\0';
            j = discard = 0;
            for(; str_idx<len; str_idx++){

                if(str[str_idx] == ' ' && cmtIn) continue;

                if(str[str_idx] == ' ' || str[str_idx] == '\n'){
                    inWord[j] = '\0';
                    break;
                }
                else if(str[str_idx] == '/' && str[str_idx+1] == '/' ){
                    cmtLine = 1;
                    break;
                }
                else if(str[str_idx] == '/' && str[str_idx + 1] == '*' && !cmtIn){
                    cmtIn = 1;
                    str_idx = str_idx + 2;
                }
                else if(str[str_idx] == '*' && str[str_idx + 1] == '/' && cmtIn){
                    cmtIn = 0;
                    str_idx = str_idx + 2;
                }
                else if(!cmtIn){
                    inWord[j] = str[str_idx];
                    j++;
                }
            }
            str_idx++;
            
            if(cmtLine == 1) break;
            else if(strlen(inWord) == 0 && str_idx > len) break;
            else if(strlen(inWord) == 0) continue;
            else if(str[str_idx-1] == '\n') strIn = 0;
            
            for(int i=0; i<strlen(inWord); i++){
                discard_check_word[i] = tolower(inWord[i]);
            }
            discard_check_word[strlen(inWord)] = '\0';
            
            for(int i=0; i<10; i++){
                if(!strcmp(discard_check_word, discard_words[i])){
                    discard = 1;
                    break;
                }
            }
            if(discard == 1) continue;
            
            if(w_idx == 0){
                strcpy(w[w_idx].name, inWord);
                line_idx = w[w_idx].line_idx;
                w[w_idx].line[line_idx] = line;
                w[w_idx].line_idx++;
                w_idx++;
                continue;
            }
            
            for(int i=0; i<w_idx; i++){
                if(!strcmp(w[i].name, inWord)){
                    if(w[i].line[w[i].line_idx - 1] == line) break;
                    
                    w[i].line[w[i].line_idx] = line;
                    w[i].line_idx++;
                    break;
                }else if(i == w_idx - 1){
                    strcpy(w[w_idx].name, inWord);
                    w[w_idx].line[0] = line;
                    w[w_idx].line_idx++;
                    
                    temp_idx = w_idx;
                    w_idx++;
                    while(1){
                        if(temp_idx == 0){
                            break;
                        }else if(strcmp(w[temp_idx].name, w[(temp_idx - 1) / 2].name) < 0){ // if the node is former in order than the parent,
                            strcpy(tempWord.name, w[(temp_idx - 1) / 2].name);
                            memcpy(tempWord.line, w[(temp_idx - 1) / 2].line, 100);
                            tempWord.line_idx = w[(temp_idx - 1) / 2].line_idx;
                            
                            strcpy(w[(temp_idx - 1) / 2].name, w[temp_idx].name);
                            memcpy(w[(temp_idx - 1) / 2].line, w[temp_idx].line, 100);
                            w[(temp_idx - 1) / 2].line_idx = w[temp_idx].line_idx;
                            
                            strcpy(w[temp_idx].name, tempWord.name);
                            memcpy(w[temp_idx].line, tempWord.line, 100);
                            w[temp_idx].line_idx = tempWord.line_idx;
                            
                            temp_idx = (temp_idx - 1) / 2;
                        }else break;
                    }
                    break;
                }
            }
        }
    }

    while(w_idx > 0){
        if(w_idx == 1){
            printf("%s ", w[0].name);
            for(int i=0; i<w[0].line_idx; i++){
                if(i == w[0].line_idx - 1) printf("%d\n", w[0].line[i]);
                else printf("%d ", w[0].line[i]);
            }
            w_idx--;
            break;
        }
        
        printf("%s ", w[0].name);
        
        for(int i=0; i<w[0].line_idx; i++){
            if(i == w[0].line_idx - 1) printf("%d\n", w[0].line[i]);
            else printf("%d ", w[0].line[i]);
        }
        
        strcpy(w[0].name, w[w_idx-1].name);
        memcpy(w[0].line, w[w_idx-1].line, 100); // move last node to root node.
        w[0].line_idx = w[w_idx-1].line_idx;
        w_idx--;
        
        temp_idx = 0;
        
        while(1){
            if(temp_idx * 2 + 1 >= w_idx) break;
            else if(temp_idx * 2 + 2 >= w_idx) max_idx = temp_idx * 2 + 1;
            else if(strcmp(w[temp_idx * 2 + 1].name, w[temp_idx * 2 + 2].name) > 0){
                max_idx = temp_idx * 2 + 2;
            }else max_idx = temp_idx * 2 + 1;
            
            if(strcmp(w[temp_idx].name, w[max_idx].name) > 0){
                strcpy(tempWord.name, w[max_idx].name);
                memcpy(tempWord.line, w[max_idx].line, 100);
                tempWord.line_idx = w[max_idx].line_idx;
                
                strcpy(w[max_idx].name, w[temp_idx].name);
                memcpy(w[max_idx].line, w[temp_idx].line, 100);
                w[max_idx].line_idx = w[temp_idx].line_idx;
                
                strcpy(w[temp_idx].name, tempWord.name);
                memcpy(w[temp_idx].line, tempWord.line, 100);
                w[temp_idx].line_idx = tempWord.line_idx;
                
                temp_idx = max_idx;
            }else break;
        }
    }
    return 0;
}
