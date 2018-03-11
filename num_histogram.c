//
//  num_histogram.c
//  Test01
//
//  Created by 박민영 on 11/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    char ch;
    int num[10] = {0};
    
    while((ch = getchar()) != EOF){
        if(ch >= '0' && ch <= '9'){
            num[ch-'0'] ++;
        }
    }
    
    for(int i=0; i<10; i++){
        printf("%d: ",i);
        for(int j=0; j<num[i]; j++){
            putchar('*');
        }
        printf("\n");
    }
    return 0;
}
