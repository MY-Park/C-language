//
//  date_day.c
//  Test01
//
//  Created by 박민영 on 27/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    int year, m, q;
    int h, j, k;
    
    char day[10];
    
    scanf("%d\n%d\n%d",&year, &m, &q);
    
    if(m < 3){
        m += 12;
        year--;
    }
    k = year % 100;
    j = year / 100;
    
    h = (q + (26 * (m + 1)) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    
    switch(h){
        case 0 :
            strcpy(day, "Saturday");
            break;
        case 1 :
            strcpy(day, "Sunday");
            break;
        case 2 :
            strcpy(day, "Monday");
            break;
        case 3 :
            strcpy(day, "Tuesday");
            break;
        case 4 :
            strcpy(day, "Wednesday");
            break;
        case 5 :
            strcpy(day, "Thursday");
            break;
        case 6 :
            strcpy(day, "Friday");
            break;
        default:
            strcpy(day, "None");
    }
    
    printf("%s",day);
    return 0;
}

