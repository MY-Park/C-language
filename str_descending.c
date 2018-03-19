//
//  str_descending.c
//  Test01
//
//  Created by 박민영 on 19/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024

int main(){
    char str[SIZE];
    int str_idx;
    char ch;
    char temp;
    
    int fileIn = 1;
    int len;
    
    while(fileIn){
        str_idx = 0;
        while((ch = getchar()) != EOF){
            if(ch == '\n') break;
            else{
                str[str_idx] = ch;
                str_idx++;
            }
        }
        str[str_idx] = '\0';
        
        if(ch == EOF) fileIn = 0;
        
        len = (int)strlen(str);
        for(int i=0; i<len-1; i++){
            for(int j=0; j<len-i-1; j++){
                if(tolower(str[j]) < tolower(str[j+1])){
                    temp = str[j+1];
                    str[j+1] = str[j];
                    str[j] = temp;
                }else if(tolower(str[j]) == tolower(str[j+1])){
                    if(str[j] < str[j+1]){
                        temp = str[j+1];
                        str[j+1] = str[j];
                        str[j] = temp;
                    }
                }
            }
        }
        
        printf("%s\n",str);
        
    }
    
    
    
    return 0;
}
