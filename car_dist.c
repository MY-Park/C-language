//
//  car_dist.c
//  Test01
//
//  Created by 박민영 on 26/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024

int main(){
    char str[SIZE];
    char temp[100];
    
    int hour, min, sec, temp_hour, temp_min, temp_sec;
    double dist, speed, time_gap;
    
    dist = speed = 0;
    
    hour = min = sec = 0;
    
    int len;
    
    while(fgets(str, SIZE, stdin) != NULL){
        time_gap = 0;
        
        len = (int)strlen(str);
        temp[0] = str[0];
        temp[1] = str[1];
        temp[2] = '\0';
        
        temp_hour = atoi(temp);
        
        temp[0] = str[3];
        temp[1] = str[4];
        temp[2] = '\0';
        
        temp_min = atoi(temp);
        
        temp[0] = str[6];
        temp[1] = str[7];
        temp[2] = '\0';
        
        temp_sec = atoi(temp);
        
        
        if(temp_sec >= sec){
            time_gap += (temp_sec - sec) * 1.0 / 3600;
        }else if(temp_sec < sec){
            temp_min--;
            temp_sec += 60;
            time_gap += (temp_sec - sec) * 1.0 / 3600;
        }
        
        if(temp_min >= min){
            time_gap += (temp_min - min) * 1.0 / 60;
        }else if(temp_min < min){
            temp_hour--;
            temp_min += 60;
            time_gap += (temp_min - min) * 1.0 / 60;
        }
        
        time_gap += temp_hour - hour;
        dist += time_gap * speed;
        
        if(str[8] != '\n' && str[8] != EOF){
            for(int i=9;i<len;i++){
                if(str[i] == '\n'|| str[i] == EOF){
                    temp[i-9] = '\0';
                    speed = atof(temp);
                    break;
                }else{
                    temp[i-9] = str[i];
                }
            }
        }else{
            for(int i=0; i<8; i++) putchar(str[i]);
            printf(" %.2f km\n",dist);
        }
        
        hour = temp_hour;
        min = temp_min;
        sec = temp_sec;
    }
    return 0;
}
