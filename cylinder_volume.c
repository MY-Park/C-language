//
//  cylinder_volume.c
//  Test01
//
//  Created by 박민영 on 27/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(){
    double R, L;
    
    scanf("%lf\n%lf",&R,&L);
    
    double A = floor((R * R * PI) * 10)/10.0;
    double V = floor((R * R * PI * L) * 10) / 10.0;
    
    printf("%.1f\n%.1f",A,V);
    
    return 0;
}
