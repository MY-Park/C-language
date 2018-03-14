//
//  remove_comment.c
//  Test01
//
//  Created by 박민영 on 14/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    int quoIN = 0;
    int cmtIN = 0;
    int len = 0;
    
    char str[SIZE][SIZE];
    
    int strNum = 0;
    while(fgets(str[strNum], SIZE, stdin) != NULL){
        strNum++;
    }
    
    for(int i=0; i<strNum; i++){
        len = (int)strlen(str[i]);
        
        for(int j=0; j<len; j++){
            if(str[i][j] == '\"' && !quoIN && !cmtIN){
                quoIN = 1;
            }else if(str[i][j] == '\"' && quoIN && !cmtIN){
                quoIN = 0;
            }else if(j == len-1){
                continue;
            }else if(str[i][j] == '/' && str[i][j+1] == '*' && !cmtIN && !quoIN){
                cmtIN = 1;
            }else if(str[i][j] == '*' && str[i][j+1] == '/' && cmtIN && !quoIN ){
                cmtIN = 0;
                j++;
                continue;
            }
            
            if(!cmtIN) putchar(str[i][j]);
        }
        putchar('\n');
    }
    
    return 0;
}
