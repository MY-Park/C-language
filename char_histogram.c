//
//  num_vertical_hist.c
//  Test01
//
//  Created by 박민영 on 11/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){

    int arr[94] = {0};
    char ch;
    int max_val = 0;
    
    while((ch=getchar())!=EOF){
        if(ch >= '!' && ch <= '~'){
            arr[ch-'!']++;
        }
    }
    
    for(int i='!'; i<='~'; i++){
        printf("%c: ",i);
        for(int j=0; j<arr[i-'!']; j++){
            putchar('*');
        }
        putchar('\n');
    }
    
    return 0;
}
