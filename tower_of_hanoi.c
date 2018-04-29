//
//  tower_of_hanoi.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int i, res = 1;
    scanf("%d",&i);
    
    for(int j=0; j<i; j++)
        res *= 2;
    printf("%d", res-1);
    return 0;
}
