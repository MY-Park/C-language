//
//  tri_num_sum.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int tri_w_sum(int);

int main(){
    int t, n;
    scanf("%d",&t);
    
    for(int i=1; i <= t; i++){
        scanf("%d", &n);
        printf("%d %d %d\n", i, n, tri_w_sum(n));
    }
    
    return 0;
}

int tri_w_sum(int n){
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += i * (i+1) * (i+2) / 2;
    
    return sum;
}
