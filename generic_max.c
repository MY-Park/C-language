//
//  generic_max.c
//  Test01
//
//  Created by 박민영 on 04/11/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 10

int main(){
    char type[SIZE];
    int row, col;
    
    fgets(type, SIZE, stdin);
    scanf("%d %d", &row, &col);
    
    if(!strcmp(type, "String")){
        
    }else if(!strcmp(type, "Integer")){
        
    }else if(!strcmp(type, "Double")){
        
    }
    
    
    return 0;
}
