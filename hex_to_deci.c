//
//  hex_to_deci.c
//  Test01
//
//  Created by 박민영 on 14/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024

int main(){
    int n, len, deci;
    scanf("%d\n",&n);
    char str[SIZE];
    char num;
    int loop;
    
    for(int i=0; i<n; i++){
        fgets(str, SIZE, stdin);
        len = (int)strlen(str);
        deci = loop = 0;
        
        if(str[0] != '0' || (str[1] != 'x' && str[1] != 'X')){
            printf("null\n");
            continue;
        }
        
        for(int j=2; j<len-1; j++){
            num = str[j];
            if((num >= '0' && num <= '9') || (num >= 'a' && num <= 'f') || (num >= 'A' && num <= 'F')){
                continue;
            }else{
                printf("null\n");
                loop = 1;
                break;
            }
        }
        if(loop) continue;
        
        deci = (int)strtol(str, NULL, 16);
        printf("%d\n",deci);
    }
    return 0;
}
