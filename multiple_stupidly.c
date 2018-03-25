//
//  multiple_stupidly.c
//  Test01
//
//  Created by 박민영 on 24/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 30

int main(){
    int num_1[SIZE] = {0};
    int num_2[SIZE] = {0};
    
    int len_1, len_2, len, i, ans = 0;

    char str[SIZE];
    
    fgets(str, SIZE, stdin);
    len = (int)strlen(str);
    
    for(i=0; i<len; i++){
        if(str[i] == ' ') break;
        else num_1[i] = str[i]-'0';
    }
    len_1 = i;
    i++;
    
    for(;i<len;i++){
        if(str[i] == '\n' || str[i] == EOF) break;
        else num_2[i-len_1] = str[i] - '0';
    }
    len_2 = i;
    
    for(i=0; i<len_1; i++){
        for(int j=0; j<len_2; j++){
            ans += num_1[i] * num_2[j];
        }
    }
    
    printf("%d",ans);
    return 0;
}
