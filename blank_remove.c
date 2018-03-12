//
//  blank_remove.c
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
    int sublen = 0;
    
    while(fgets(buffer, sizeof(buffer), stdin)){
        len = (int)strlen(buffer);
        for(int i=0; i<len; i++){
            buf = buffer[i];
            if(buf != ' ' && buf != '\n' && buf != '\r' && buf != '\t'){
                sublen = i;
            }
        }
        if(sublen != 0){
            for(int i=0; i<=sublen; i++){
                putchar(buffer[i]);
            }
            putchar('\n');
        }
        sublen = 0;
    }

    return 0;
}
