//
//  game_combination.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int factorial(int);
int combin(int, int);

int main(){
    int sc1, sc2, sum;
    
    while(1){
        scanf("%d %d", &sc1, &sc2);
        if(sc1 == -1 && sc2 == -1) break;
        
        sum = sc1 + sc2;
        
        if(combin(sum, sc1) == sum) printf("%d+%d=%d\n",sc1,sc2,sum);
        else printf("%d+%d!=%d\n",sc1,sc2,sum);
    }
    return 0;
}
int factorial(int n){
    int fac = 1;
    for(; n>0; n--)
        fac *= n;
    return fac;
}

int combin(int sum, int sel){
    return factorial(sum) / (factorial(sel) * factorial(sum-sel));
}
