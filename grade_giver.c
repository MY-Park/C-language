//
//  grade_giver.c
//  Test01
//
//  Created by 박민영 on 27/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int grade[150];
    int max = 0;
    
    int N;
    
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d", &grade[i]);
        max = (max < grade[i]) ? grade[i] : max;
    }
    
    for(int i=0; i<N; i++){
        if(grade[i] >= max - 10) printf("A\n");
        else if(grade[i] >= max - 20) printf("B\n");
        else if(grade[i] >= max - 30) printf("C\n");
        else if(grade[i] >= max - 40) printf("D\n");
        else printf("F\n");
    }
    return 0;
}
