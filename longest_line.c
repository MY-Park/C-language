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
    char max_str[1024];
    int len = 0;
    int max_len = 0;
    
    while(fgets(str, sizeof(str), stdin)){
        len = (int)strlen(str);
        if(max_len < len){
            strcpy(max_str, str);
            max_len = len;
        }
    }
    printf("%d\n%s",max_len-1,max_str);
    
    return 0;
}
