//
//  final_score.c
//  Test01
//
//  Created by 박민영 on 27/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int sum, diff;
    double A, B;
    for(int i=0; i<N; i++){
        scanf("%d %d", &sum, &diff);
        A = (sum + diff)*1.0 / 2;
        B = (sum - diff)*1.0 / 2;
        
        if(A < 0 || B < 0 || A != (int)A || B != (int)B) printf("impossible\n");
        else printf("%.0f %.0f\n",A,B);
    }
    return 0;
}
