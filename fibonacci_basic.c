//
//  fibonacci_basic.c
//  Test01
//
//  Created by 박민영 on 04/09/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int fibo[41];

int main(){
    int lim, idx;
    scanf("%d", &lim);
    fibo[0] = 0;
    fibo[1] = 1;
    
    idx = 1;
    
    while(idx <= lim){
        idx++;
        fibo[idx] = fibo[idx-1] + fibo[idx-2];
    }
    
    printf("%d", fibo[lim]);
}
