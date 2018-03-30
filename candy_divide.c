//
//  chicken_rabbit_legs.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int candy[105];
    int half_candy[105];
    
    int N, round;
    int SAME_TRUE, odd;
    
    while(1){
        SAME_TRUE = 1;
        odd = 0;
        
        scanf("%d",&N);
        getchar();
        round = 0;
        
        if(!N) return 0;
        
        for(int i=0; i<N; i++){
            scanf("%d",&candy[i]);
            
            if(candy[i] % 2 == 1){
                candy[i]++;
                odd = 1;
            }
            if(i > 0){
                SAME_TRUE *= (candy[i] == candy[i-1] * 2);
            }
            half_candy[i] = candy[i] / 2;
            candy[i] /= 2;
        }
        
        SAME_TRUE *= (candy[0] == candy[N-1]);
        
        if(SAME_TRUE){
            if(odd) round++;
            printf("%d %d\n", round, candy[0] * 2);
            continue;
        }
        
        while(1){
            SAME_TRUE = 1;
            round++;
            
            for(int i=0; i<N-1; i++){
                candy[i+1] += half_candy[i];
                if(candy[i+1] % 2 == 1) candy[i+1]++;
                
                if(i == 0) ;
                else SAME_TRUE *= (candy[i] == candy[i+1]);
            }
            
            candy[0] += half_candy[N-1];
            if(candy[0] % 2 == 1) candy[0]++;
            
            SAME_TRUE *= (candy[0] == candy[N-1]);
            
            if(SAME_TRUE && (candy[0] % 2 == 0)){
                printf("%d %d\n", round, candy[0]);
                break;
            }
            
            for(int i=0; i<N; i++){
                half_candy[i] = candy[i] / 2;
                candy[i] /= 2;
            }
        }
        
    }
    
    return 0;
}

