//
//  WCSPC_2015B.c
//  Test01
//
//  Created by 박민영 on 05/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[100001] = {0};

int main(){
    int cnt = 0;
    
    while(1){
        char *sp;
        sp = (char*)malloc(sizeof(char) * 250);
        
        if(fgets(sp, 250, stdin)==NULL)
            break;
        
        char *np, *cp;
        np = (char*)malloc(sizeof(char) * 5);
        
        int len = (int)strlen(sp);
        
        cp = np;
        int sum = 0;
        
        for(int i=0; i<len; i++){
            if(*sp == ' ' || i == len - 1){
                *cp = '\0';
                ++sp;
                sum += atoi(np);
                cp = np;
                
                if(i == len-1){
                    if(++num[sum] == 1)
                        cnt++;
                }
            }else{
                *cp++ = *sp++;
            }
        }
    }
    
    printf("%d", cnt);
}
