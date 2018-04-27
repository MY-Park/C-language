//
//  major_grade.c
//  Test01
//
//  Created by 박민영 on 27/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
    char input[3];
    
    fgets(input, 3, stdin);
    
    switch(input[0]){
        case 'C':
            printf("Computer Science ");
            break;
        case 'M':
            printf("Mathematics ");
            break;
        case 'I':
            printf("Information Technology ");
            break;
        default:
            printf("None ");
    }
    
    switch (input[1]) {
        case '1':
            printf("Freshman");
            break;
        case '2':
            printf("Sophomore");
            break;
        case '3':
            printf("Junior");
            break;
        case '4':
            printf("Senior");
            break;
        default:
            printf("None");
            break;
    }
    
    
    return 0;
}

