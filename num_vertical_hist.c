//
//  num_vertical_hist.c
//  Test01
//
//  Created by 박민영 on 11/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int num[10] = {0};
    char ch;
    int max_val = 0;
    
    while((ch=getchar())!=EOF){
        if(ch >= '0' && ch <= '9'){
            num[ch-'0']++;
            if (max_val < num[ch-'0']){
                max_val = num[ch-'0'];
            }
        }
    }
    
    for(int i=max_val; i>0; i--){
        for(int j=0; j<10; j++){
            if(num[j] >= i){
                putchar('*');
            }else putchar(' ');
        }
        putchar('\n');
    }
    printf("----------\n0123456789");
}
