//
//  atof_func.c
//  Test01
//
//  Created by 박민영 on 16/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define SIZE 1024

int main(){
    int N;
    scanf("%d\n",&N);
    char str[SIZE];
    double ans;
    
    for(int i=0; i<N; i++){
        fgets(str, SIZE, stdin);
        ans = atof(str);
        printf("%.7g\n", ans);
    }
    return 0;
}
