//
//  str_func_ternary.c
//  Test01
//
//  Created by 박민영 on 19/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000

int main(){
    char str[SIZE];
    char input[SIZE];
    
    fgets(str, SIZE, stdin);
    
    char func[10];
    
    int len;
    int num = 0;
    int str_in_idx;
    int firstIn;
    char str_in[SIZE];
    int res = 0;
    
    while(fgets(input, SIZE, stdin) != NULL){
        strncpy(func, input, 7);
        len = (int)strlen(input);

        firstIn = 1;
        str_in_idx = 0;
        
        for(int i=8; i<len; i++){
            if(input[i] == ' '){
                firstIn = 0;
                str_in[str_in_idx] = '\0';
                num = atoi(str_in);
                str_in_idx = 0;
            }else if(input[i] == '\n'){
                str_in[str_in_idx] = '\0';
            }else if(firstIn){
                str_in[str_in_idx] = input[i];
                str_in_idx++;
            }else if(!firstIn){
                str_in[str_in_idx] = input[i];
                str_in_idx++;
            }
        }
        
        if(!strcmp(func, "strncpy")){
            strncpy(str, str_in, num);
        }else if(!strcmp(func, "strncat")){
            strncat(str, str_in, num);
        }else if(!strcmp(func, "strncmp")){
            res = strncmp(str, str_in, num);
            if (res > 0) res = 1;
            else if(res == 0) res = 0;
            else if(res < 0) res = -1;
        }
    }
    
    printf("%d",res);
    return 0;
}
