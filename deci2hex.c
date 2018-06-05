//
//  deci2hex.c
//  Test01
//
//  Created by 박민영 on 05/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

void deci2hex(int *ip){
    printf("%x", *ip);
}
int main(){
    int d;
    scanf("%d",&d);
    deci2hex(&d);
    return 0;
}
