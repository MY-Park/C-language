//
//  mind_reader.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int n0, n4, T = 0;
    
    while(1){
        T++;
        
        scanf("%d", &n0);
        if(!n0) break;
        printf("%d. ", T);
        
        if(n0 % 2){
            n4 = (n0 - 1) / 2;
            printf("odd %d\n", n4);
        }else{
            n4 = n0 / 2;
            printf("even %d\n", n4);
        }
        
    }
    return 0;
}
