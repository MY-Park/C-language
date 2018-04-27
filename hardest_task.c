//
//  hardest_task.c
//  Test01
//
//  Created by 박민영 on 04/09/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#define SIZE 2048

int arr[SIZE];
int hard_arr[SIZE][SIZE][SIZE] = {0};

int hardest(int str, int end, int k){
    
    if(hard_arr[k][str][end] != 0) return hard_arr[k][str][end];
    
    if(str + 1 == end){
        if(arr[str] <= arr[end]){
            hard_arr[k][str][end] = arr[str] * (k + 1) + arr[end] * (k + 2);
            return arr[str] * (k + 1) + arr[end] * (k + 2);
        }
        else{
            hard_arr[k][str][end] = arr[str] * (k + 2) + arr[end] * (k + 1);
            return arr[str] * (k + 2) + arr[end] * (k + 1);
        }
    }
    else{
        int m,n;
        if(hard_arr[k+1][str][end-1] != 0) m = hard_arr[k+1][str][end-1] + arr[end] * (k + 1);
        else {
            m = hardest(str, end-1, k + 1);
            hard_arr[k+1][str][end-1] = m;
            m += arr[end] * (k + 1);
        }
        
        if(hard_arr[k+1][str+1][end] != 0) n = hard_arr[k+1][str+1][end] + arr[str] * (k + 1);
        else{
            n = hardest(str + 1, end, k + 1);
            hard_arr[k+1][str+1][end] = n;
            n += arr[str] * (k + 1);
        }
        
        if(m >= n) return m;
        else return n;
    }
}

int main(){

    int N;
    int str_idx = 0;
    int end_idx;
    
    scanf("%d", &N);
    end_idx = N - 1;
    
    for(int i=0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    if(N == 1) printf("%d", arr[0]);
    else printf("%d", hardest(str_idx, end_idx, 0));
    
    return 0;
}
