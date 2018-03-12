//
//  num_vertical_hist.c
//  Test01
//
//  Created by 박민영 on 11/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(){
    char str[1024];
    char short_str[1024][1024];
    int i = 0;
    int len = 0;
    
    while(fgets(str, sizeof(str), stdin)){
        len = (int)strlen(str) - 1;
        if (len < 32){
            strcpy(short_str[i], str);
            i++;
        }
    }
    
    for(int j=0; j<i; j++){
        printf("%s", short_str[j]);
    }
    
    return 0;
}
