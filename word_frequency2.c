//
//  word_frequency2.c
//  Test01
//
//  Created by 박민영 on 18/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 10000

struct Word{
    char name[100];
    int freq;
};

struct Word w[SIZE];

int main(){
    char str[SIZE];
    char inWord[100];
    struct Word tempWord;
    
    struct Word temp_w[1000];
    int temp_w_idx = 0;
    
    int max_idx = 0;
    
    int len, str_idx, j, w_idx = 0;
    int strIn = 1;
    int cmtLine = 0;
    int cmtIn = 0;
    int temp_idx = 0;
    int max_freq = 0;
    
    while(fgets(str, 1024, stdin) != NULL){
        str_idx = 0;
        len = (int)strlen(str);
        cmtIn = cmtLine = 0;
        strIn = 1;
        
        while(strIn){
            inWord[0] = '\0';
            j = 0;
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
            
            if(w_idx == 0){
                strcpy(w[w_idx].name, inWord);
                w[w_idx].freq = 1;
                max_freq = 1;
                w_idx++;
                continue;
            }
            
            for(int i=0; i<w_idx; i++){
                if(!strcmp(w[i].name, inWord)){
                    w[i].freq++;
                    if(w[i].freq > max_freq) max_freq = w[i].freq;
                    break;
                }else if(i == w_idx - 1){
                    strcpy(w[w_idx].name, inWord);
                    w[w_idx].freq = 1;
                    w_idx++;
                    break;
                }
            }
        }
    }
    
    for(int i=max_freq; i>=1; i--){
        for(int j=0; j<w_idx; j++){
            if(w[j].freq == i){
                strcpy(temp_w[temp_w_idx].name, w[j].name);
                temp_w[temp_w_idx].freq = w[j].freq;
                temp_idx = temp_w_idx;
                temp_w_idx++;
                while(1){
                    if(temp_idx == 0) break;
                    else if(strcmp(temp_w[temp_idx].name, temp_w[(temp_idx - 1) / 2].name) < 0){
                        strcpy(tempWord.name, temp_w[(temp_idx - 1) / 2].name);
                        tempWord.freq = temp_w[(temp_idx - 1) / 2].freq;
                        
                        strcpy(temp_w[(temp_idx - 1) / 2].name, temp_w[temp_idx].name);
                        temp_w[(temp_idx - 1) / 2].freq = temp_w[temp_idx].freq;
                        
                        strcpy(temp_w[temp_idx].name, tempWord.name);
                        temp_w[temp_idx].freq = tempWord.freq;
                        
                        temp_idx = (temp_idx - 1) / 2;
                    }else break;
                }
            }
        }
        
        while(temp_w_idx > 0){
            if(temp_w_idx == 1){
                printf("%s %d\n", temp_w[0].name, temp_w[0].freq);
                temp_w_idx--;
                break;
            }
            
            printf("%s %d\n", temp_w[0].name, temp_w[0].freq);
            strcpy(temp_w[0].name, temp_w[temp_w_idx-1].name);
            temp_w[0].freq = temp_w[temp_w_idx-1].freq; // move last node to root node.
            temp_w_idx--;
            
            temp_idx = 0;
            
            while(1){
                if(temp_idx * 2 + 1 >= temp_w_idx) break;
                else if(temp_idx * 2 + 2 >= temp_w_idx) max_idx = temp_idx * 2 + 1;
                else if(strcmp(temp_w[temp_idx * 2 + 1].name, temp_w[temp_idx * 2 + 2].name) > 0){
                    max_idx = temp_idx * 2 + 2;
                }else max_idx = temp_idx * 2 + 1;
                
                if(strcmp(temp_w[temp_idx].name, temp_w[max_idx].name) > 0){
                    strcpy(tempWord.name, temp_w[max_idx].name);
                    tempWord.freq = temp_w[max_idx].freq;
                    
                    strcpy(temp_w[max_idx].name, temp_w[temp_idx].name);
                    temp_w[max_idx].freq = temp_w[temp_idx].freq;
                    
                    strcpy(temp_w[temp_idx].name, tempWord.name);
                    temp_w[temp_idx].freq = tempWord.freq;
                    
                    temp_idx = max_idx;
                }else break;
            }
        }
    }
    
    return 0;
}
