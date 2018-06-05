//
//  WCSPC_2015C.c
//  Test01
//
//  Created by 박민영 on 05/06/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(){
    int T, P;
    double x, y;
    double min_dis, temp_dis;
    int min_idx;
    
    scanf("%d %d", &T, &P);
    
    double toilet[T][2];

    for(int i = 0; i < T; i++){
        scanf("%lf %lf", &toilet[i][0], &toilet[i][1]);
    }
    
    for(int i = 0; i < P; i++){
        scanf("%lf %lf", &x, &y);
        min_dis = sqrt(pow(x - toilet[0][0], 2) + pow(y - toilet[0][1], 2));
        min_idx = 0;
        
        for(int j = 1; j < T; j++){
            if((temp_dis = sqrt(pow(x - toilet[j][0], 2) + pow(y - toilet[j][1], 2))) < min_dis){
                min_idx = j;
                min_dis = temp_dis;
            }
        }
        printf("%d %d\n", (int)toilet[min_idx][0], (int)toilet[min_idx][1]);
    }
    
    return 0;
}
