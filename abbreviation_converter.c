//
//  abbreviation_converter.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    char str[SIZE][SIZE];
    int len, i;
    int check;
    int idx = 0;
    
    while(fgets(str[idx], SIZE, stdin)!=NULL){
        idx++;
    }
    for(int k=0; k<idx; k++){
        len = (int)strlen(str[k]);
        for(i=0; i<len-2; i++){
            check = 0;
            if(str[k][i] >= 'A' && str[k][i] <= 'Z' && str[k][i+1] == '-' && str[k][i+2] >= str[k][i] && str[k][i+2] <= 'Z'){
                check = 1;
            }else if(str[k][i] >= '0' && str[k][i] <= '9' && str[k][i+1] == '-' && str[k][i+2] >= str[k][i] && str[k][i+2] <= '9'){
                check = 1;
            }else if(str[k][i] >= 'a' && str[k][i] <= 'z' && str[k][i+1] == '-' && str[k][i+2] >= str[k][i] && str[k][i+2] <= 'z'){
                check = 1;
            }
            
            if(check){
                for(char j=str[k][i]; j<=str[k][i+2]; j++) putchar(j);
                i = i + 2;
            }else{
                putchar(str[k][i]);
            }
        }
        for(;i<len;i++) putchar(str[k][i]);
    }
    return 0;
}
