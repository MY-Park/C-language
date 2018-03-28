//
//  overlap_checker.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#define SIZE 1000001

int main(){
    int N, M, input;
    int overlap;
    
    while(1){
        scanf("%d %d",&N, &M);
        
        overlap = 0;
        
        if(N == 0 && M == 0) break;
        int arr[SIZE] = {0};
        
        for(int i=0; i<N; i++){
            scanf("%d",&input);
            arr[input]++;
        }
        
        for(int i=0; i<M; i++){
            scanf("%d",&input);
            if(arr[input] != 0) overlap++;
        }
        printf("%d\n", overlap);
    }
    return 0;
}
