//
//  class_classify.c
//  Test01
//
//  Created by 박민영 on 16/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 10000

int main(){
    char str[SIZE];
    int idx, j;
    int cmtIn = 0;
    
    while(fgets(str, SIZE, stdin)!=NULL){
        idx = 0;
        
        while(1){
            char word[SIZE];
            word[0] = '\0';

            j = 0;
            for(; j<strlen(str);){
                if((strlen(word) != 0) && (str[idx] == ' ' || str[idx] == '\n')){
                    word[j] = '\0';
                    idx++;
                    break;
                }else if(strlen(word) == 0 && str[idx] == '\n') break;
                else{
                    if(strlen(word) == 0 && str[idx] == ' '){
                        idx++;
                        continue;
                    }
                    word[j] = str[idx];
                    j++;
                    idx++;
                }
            }
            
            if(strlen(word) == 0) break;
            
            if(word[0] == '_' && !cmtIn){
                printf("%s", "id");
                if(str[idx-1] == ' ') putchar(' ');
                
            }else if(word[0] == '\'' && word[2] == '\'' && !cmtIn){
                printf("%s", "char");
                if(str[idx-1] == ' ') putchar(' ');
                
            }else if(word[0] == '/' && word[1] == '*' && !cmtIn){
                printf("%s", "comment");
                cmtIn = 1;
            }else if(word[0] == '*' && word[1] == '/' && cmtIn){
                if(str[idx-1] == ' ') putchar(' ');
                cmtIn = 0;
            }else if(!cmtIn){
                printf("%s", "normal");
                if(str[idx-1] == ' ') putchar(' ');
            }
            
            if(str[idx-1] == '\n') {
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}
