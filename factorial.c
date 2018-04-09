//
//  factorial.c
//  Test01
//
//  Created by 박민영 on 04/09/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int a;
    long long int ans = 1;
    
    scanf("%d", &a);
    
    if(a == 0) {
        printf("1");
        return 0;
    }
    while(a != 1){
        ans *= a;
        a--;
    }
    
    printf("%lld", ans);
    return 0;
}
