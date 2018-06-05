//
//  WCSPC_2015A.c
//  Test01
//
//  Created by 박민영 on 05/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

void combi3(int *ip){
    int cnt = 0;
    for(int x = 1; x < *ip; x++){
        for(int y = x + 1; y < *ip; y++){
            for(int z = y + 1; z < *ip; z++){
                if(x + y + z == *ip){
                    printf("%d %d %d\n", x, y, z);
                    ++cnt;
                }
            }
        }
    }
    if(!cnt)
        printf("NULL\n");
}
int main(){
    
    int N, input;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &input);
        combi3(&input);
    }
    
}
