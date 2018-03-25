//
//  over_avg.c
//  Test01
//
//  Created by 박민영 on 25/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024

int main(){
    int num_of_class;
    scanf("%d\n",&num_of_class);
    
    int num_of_stu, temp_idx, score_idx;
    int firstIn;
    
    double avg, res;
    int score[SIZE];
    
    char str[SIZE];
    char temp[5];
    
    for(int i=0; i<num_of_class; i++){
        fgets(str, SIZE, stdin);
        avg = firstIn = score_idx = temp_idx = num_of_stu = res = 0;
        
        for(int j=0; j<strlen(str); j++){
            if(str[j] == ' ' || str[j] == '\n'){
                temp[temp_idx] = '\0';
                temp_idx = 0;
                if(!firstIn){
                    num_of_stu = atoi(temp);
                    firstIn = 1;
                    continue;
                }else{
                    score[score_idx] = atoi(temp);
                    score_idx++;
                    if(str[j] == '\n'){
                        for(int k=0; k<num_of_stu; k++){
                            avg += score[k];
                        }
                        avg /= 1.0*num_of_stu;
                        
                        for(int k=0; k<num_of_stu; k++){
                            res += score[k] > avg;
                        }
                        res /= 1.0*num_of_stu;
                        printf("%.3f%%\n", res * 100);
                    }
                }
            }else{
                temp[temp_idx] = str[j];
                temp_idx++;
            }
        }
        
    }
    return 0;
}
