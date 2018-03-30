//
//  candy_divide.c
//  Test01
//
//  Created by 박민영 on 29/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int N;
    int candy[200];
    int SAME = 0;
    
    while(1){
        scanf("%d",&N);
        if(N == 0) return 0;
        
        
        for(int i=0; i<N; i++){
            scanf("%d",&candy[i]);
        }
        while(1){
            for(int i=0; i<N; i++){
                candy[i] /= 2;
            }
            
            for(int i=0; i<N-1; i++){
                candy[i+1] += candy[i];
                if(candy[i+1] % 2 == 1) candy[i+1]++;
                
                if(i!=0){
                    if(candy[i])
                }
            }
            candy[0] += candy[N-1];
            if(candy[0] % 2 == 1) candy[0]++;
        }
    }
    
    return 0;
}
