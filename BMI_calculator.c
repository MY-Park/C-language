//
//  BMI_calculator.c
//  Test01
//
//  Created by 박민영 on 28/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(){
    
    double W;
    double H;
    double BMI;
    
    scanf("%lf\n%lf", &W, &H);
    
    W *= 0.45359237;
    H *= 0.0254;
    
    BMI = (int)((W / pow(H,2)) * 100) / 100.0;
    
    printf("%.2lf", BMI);
    
    return 0;
}
