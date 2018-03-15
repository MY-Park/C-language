//
//  first_occurrence.c
//  Test01
//
//  Created by 박민영 on 14/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    char s1[100];
    char s2[50];
    int len;
    
    fgets(s1, 100, stdin);
    fgets(s2, 50, stdin);
    
    len = (int)strlen(s1);
    
    for(int i=0; i<len-1; i++){
        if(strchr(s2,s1[i])!=NULL){
            printf("%d",i);
            return 0;
        }
    }
    printf("%d",-1);
    return 0;
}

