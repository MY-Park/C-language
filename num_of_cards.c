//
//  num_of_cards.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
int main(){
    float c;
    float n;
    int i;
    
    while(1){
        scanf("%f", &c);
        if(!c) break;
        for(i = 2, n = 0; c > n ; i++)
            n += 1.0/i;
        printf("%d card(s)\n", i-2);
    }
    return 0;
}
