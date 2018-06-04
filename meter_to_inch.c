//
//  meter_to_inch.c
//  Test01
//
//  Created by 박민영 on 04/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    double m;
    scanf("%lf", &m);
    double i = m * 39.3701;
    double f = i / 12;
    
    i = f - (int)f;
    i = i * 12;
    
    printf("%d\n%d", (int)f, (int)i);
    
    return 0;
}
