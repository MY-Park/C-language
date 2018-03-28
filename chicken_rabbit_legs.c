//
//  chicken_rabbit_legs.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int min, max, N, legs, a, b;
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        scanf("%d",&legs);
        b = 0;
        a = -1;
        min = max = 0;
        
        while((legs- 4 * b) / 2 >= 0){
            if(1.0 * (legs- 4 * b) / 2 == (legs- 4 * b) / 2){
                a = (legs- 4 * b) / 2;
                break;
            }else b++;
        }
        if(a == -1) {
            printf("0 0\n");
            continue;
        }
        
        max = a + b;
        
        a = 0;
        b = -1;
        while((legs - 2 * a) / 4 >= 0){
            if(1.0 * (legs - 2 * a) / 4 == (legs - 2 * a) / 4){
                b = (legs - 2 * a) / 4;
                break;
            }else a++;
        }
        
        min = a + b;
        
        printf("%d %d\n", min, max);
        
    }
    
    return 0;
}
