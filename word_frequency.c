//
//  word_frequency.c
//  Test01
//
//  Created by 박민영 on 18/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 10000

struct Word{
    char name[7];
    int freq;
};

int main(){
    struct Word w[SIZE];
    char str[1024];
    char inWord[1024];
    struct Word tempWord;
    
    int max_idx = 0;
    
    int len, str_idx, j, w_idx = 0;
    int strIn = 1;
    int cmtLine = 0;
    int cmtIn = 0;
    int temp_idx = 0;
    
    while(fgets(str, 1024, stdin) != NULL){
        str_idx = 0;
        len = (int)strlen(str);
        cmtIn = cmtLine = 0;
        strIn = 1;
        
        while(strIn){
            inWord[0] = '\0';
            j = 0;
            for(; str_idx<len; str_idx++){
                if(j == 6){
                    inWord[j] = '\0';
                    while(str[str_idx] != ' ' && str[str_idx] != '\n'){
                        str_idx++;
                    }
                    break;
                }
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
                w_idx++;
                continue;
            }
            
            for(int i=0; i<w_idx; i++){
                if(!strcmp(w[i].name, inWord)){
                    w[i].freq++;
                    break;
                }else if(i == w_idx - 1){
                    strcpy(w[w_idx].name, inWord);
                    w[w_idx].freq = 1;
                    temp_idx = w_idx;
                    w_idx++;
                    while(1){
                        if(temp_idx == 0){
                            break;
                        }else if(strcmp(w[temp_idx].name, w[(temp_idx - 1) / 2].name) < 0){ // if the node is former in order than the parent,
                            strcpy(tempWord.name, w[(temp_idx - 1) / 2].name);
                            tempWord.freq = w[(temp_idx - 1) / 2].freq;
                            
                            strcpy(w[(temp_idx - 1) / 2].name, w[temp_idx].name);
                            w[(temp_idx - 1) / 2].freq = w[temp_idx].freq;
                            
                            strcpy(w[temp_idx].name, tempWord.name);
                            w[temp_idx].freq = tempWord.freq;
                            
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
            printf("%s %d\n", w[0].name, w[0].freq);
            w_idx--;
            break;
        }
        
        printf("%s %d\n", w[0].name, w[0].freq);
        strcpy(w[0].name, w[w_idx-1].name);
        w[0].freq = w[w_idx-1].freq; // move last node to root node.
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
                tempWord.freq = w[max_idx].freq;
                
                strcpy(w[max_idx].name, w[temp_idx].name);
                w[max_idx].freq = w[temp_idx].freq;
                
                strcpy(w[temp_idx].name, tempWord.name);
                w[temp_idx].freq = tempWord.freq;
                
                temp_idx = max_idx;
            }else break;
        }
    }
    
    
    return 0;
}
