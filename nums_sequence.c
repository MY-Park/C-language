//
//  nums_sequence.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int n1, n2, n3, next;
    
    while(1){
        scanf("%d %d %d", &n1, &n2, &n3);
        if(n1 == 0 && n2 == 0 && n3 == 0) break;
        
        if((n1 + n3) == 2 * n2){
            next = n3 + (n3 - n2);
            printf("AP %d\n", next);
        }else{
            if(n2 == 0 && n3 == 0){
                next = 0;
            }else
                next = n3 * (n3 / n2);
            printf("GP %d\n", next);
        }
    }
    return 0;
}
