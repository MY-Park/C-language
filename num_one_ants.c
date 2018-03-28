//
//  num_one_ants.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000

int main(){
    char str[10];
    int len;
    int divider;
    int dividend;
    int i;
    
    while(fgets(str, 10, stdin) != NULL){
        
        len = (int)strlen(str);
        divider = atoi(str);
        
        dividend = 0;
        i = 0;
        while(i < SIZE){
            while((dividend = dividend * 10 + 1) < divider)
                i++;
            
            i++;
            dividend = dividend % divider;
            if (dividend == 0) break;
        }
        printf("%d\n",i);
    }
    return 0;
}
