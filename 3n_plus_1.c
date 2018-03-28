//
//  3n_plus_1.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(){
    
    char str[SIZE];
    char input[SIZE];
    
    int i, input_idx;
    int in_p, in_q, p,q,temp;
    int res;
    int step;
    int max_step = 0;
    
    while(fgets(str, SIZE, stdin) != NULL){
        input_idx = 0;
        
        for(i=0; i<SIZE; i++){
            if(str[i] == ' ') break;
            else{
                input[input_idx] = str[i];
                input_idx++;
            }
        }
        input[input_idx] = '\0';
        in_p = atoi(input);
        
        input_idx = 0;
        for(i++; i<SIZE; i++){
            if(str[i] == '\n' || str[i] == EOF){
                break;
            }else{
                input[input_idx] = str[i];
                input_idx++;
            }
        }
        input[input_idx] = '\0';
        in_q = atoi(input);
        
        if(in_p > in_q){
            p = in_q;
            q = in_p;
        }else{
            p = in_p;
            q = in_q;
        }
        max_step = 0;
        
        for(i=p; i<=q; i++){
            res = i;
            step = 0;
            while(1){
                step++;
                if(res == 1) break;
                else if(res % 2 == 1) res = 3 * res + 1;
                else if(res % 2 == 0) res /= 2;
            }
            if(step > max_step) max_step = step;
        }
        
        printf("%d %d %d\n", in_p, in_q, max_step);
    }
    return 0;
}
