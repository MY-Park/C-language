//
//  math_func.c
//  Test01
//
//  Created by 박민영 on 16/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024
#define PI 3.14159265

int main(){
    char str[SIZE];
    char func[3];
    int len, j = 0;
    char val_1[5], val_2[5];
    double ans = 0;
    
    int next = 0;
    
    while(fgets(str, SIZE, stdin) != NULL){
        len = (int)strlen(str);
        
        for(int i=0; i<3; i++) func[i] = str[i];
        
        if(strcmp(func,"sin") == 0){
            for(int i=4; i<len-1; i++){
                val_1[i-4] = str[i];
                if(i == len-2) val_1[i-3] = '\0';
            }
            ans = sin(atoi(val_1) * PI / 180);
            
        }else if(strcmp(func,"exp") == 0){
            for(int i=4; i<len-1; i++){
                val_1[i-4] = str[i];
                if(i == len-2) val_1[i-3] = '\0';
            }
            ans = exp(atoi(val_1));
        }else if(strcmp(func, "pow") == 0){
            for(int i=4; i<len-1; i++){
                if(str[i] == ' '){
                    val_1[i-4] = '\0';
                    next = 1;
                    continue;
                }
                if(!next){
                    val_1[i-4] = str[i];
                }else{
                    val_2[j] = str[i];
                    j++;
                    if(i == len-2) val_2[j] = '\0';
                }
            }
            next = j = 0;
            ans = pow(atoi(val_1), atoi(val_2));
        }
        printf("%.6f\n",ans);
    }
    
    return 0;
}
