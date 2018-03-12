//
//  str_reverse.c
//  Test01
//
//  Created by 박민영 on 11/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){

    char buffer[1024];
    int len = 0;
    char buf = 0;
    
    while(fgets(buffer, sizeof(buffer), stdin)){
        len = (int)strlen(buffer);
        for(int i = len-2; i >=0; i--){
            putchar(buffer[i]);
        }
        putchar('\n');
    }

    return 0;
}
