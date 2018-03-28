//
//  can_he_go_home.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#define SIZE 1523

int main(){
    int N;
    int input;
    int gap;
    
    while(1){
        scanf("%d",&N);
        if(N == 0) break;
        
        int arr[SIZE] = {0};
        
        arr[0] = 1;
        
        for(int i=0; i<N; i++){
            scanf("%d",&input);
            arr[input]++;
        }
        
        gap = 0;
        
        for(int i=0; i<SIZE-1; i++){
            if(arr[i]==0){
                gap++;
                if(gap >= 200){
                    printf("IMPOSSIBLE\n");
                    break;
                }
            }
            if(i == SIZE-2){
                printf("POSSIBLE\n");
            }else if(arr[i]!=0) gap = 0;
        }
    }
    return 0;
}
