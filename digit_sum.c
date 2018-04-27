//
//  digit_sum.c
//  Test01
//
//  Created by 박민영 on 27/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int N, sum = 0;
    
    scanf("%d",&N);
    
    while(N != 0){
        sum += N % 10;
        N /= 10;
    }
    
    printf("%d",sum);
    
    return 0;
}

