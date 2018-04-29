//
//  most_freq_int.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

struct Num{
    int num;
    int freq;
    int init;
};

struct Num arr[1024];

int main(){
    
    for(int i=0; i<1024; i++) arr[i].init = 0;
    
    int N, in, j, n, i = 0;
    int max_freq = 0, max_val = 0;
    
    scanf("%d",&N);
    
    for(; N>0; N--){
        scanf("%d", &in);
        n = i;
        for(j = 0; j <= n; j++){
            if(arr[j].num == in && arr[j].init){
                arr[j].freq++;
                break;
            }else if(j == i){
                arr[j].num = in;
                arr[j].freq = 1;
                arr[j].init = 1;
                i++;
            }
        }
        if(arr[j].freq > max_freq){
            max_freq = arr[j].freq;
            max_val = arr[j].num;
        }
    }
    
    printf("%d\n%d", max_val, max_freq);
    return 0;
}
