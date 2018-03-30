//
//  twin_prime_nums.c
//  Test01
//
//  Created by 박민영 on 30/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    int N, M, temp, cnt, k;
    scanf("%d",&N);
    
    for(int i = 0; i < N; i++){
        scanf("%d",&M);
        cnt = 0;
        
        int nums[10100] = {0};
        
        nums[0] = nums[1] = -1;
        
        for(int j = 2; j <= sqrt(M); j++){
            if(nums[j] < 0) continue;
            else{
                temp = 2 * j;
                while(temp <= M){
                    if(nums[temp] < 0) ;
                    else if(temp % j == 0) nums[temp]--;
                    temp += j;
                }
            }
        }
        
        for(int j = 2; j <= M-2; j++){
            if(!nums[j] && !nums[j+2]){
                cnt++;
            }
        }
        printf("%d\n",cnt);
        
        
    }
    
    return 0;
}

