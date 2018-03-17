//
//  int_read.c
//  Test01
//
//  Created by 박민영 on 16/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    int N, i = 0;
    scanf("%d\n", &N);
    
    char str[SIZE];
    char ans[SIZE];
    
    while((fgets(str, SIZE, stdin) != NULL) && i < N){
        if(strlen(str) == 1 || !(str[1] >= '0' && str[1] <= '9')) continue;
        
        if(str[0] == '-'){
            printf("%s",str);
        }else{
            memcpy(ans, &str[1], strlen(str)-1);
            printf("%s", ans);
        }
        
        i++;
    }
    
    return 0;
}
