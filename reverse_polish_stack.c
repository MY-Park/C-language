//
//  reverse_polish_stack.c
//  Test01
//
//  Created by 박민영 on 21/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[200];
    fgets(str, 200, stdin);
    
    int num[100]; //number stack
    int num_idx = 0;
    char op;
    
    int num_1, num_2;
    
    char temp_num[100];
    int temp_num_idx = 0;
    int numIn = 0;
    
    int temp = 0;
    
    int len = (int)strlen(str);
    
    int printIn = 0;
    
    for(int i=0; i<len; i++){
        if(str[i] >= '0' &&  str[i] <= '9'){
            temp_num[temp_num_idx] = str[i];
            temp_num_idx++;
            numIn = 1;
        }else if(str[i] == ' ' && numIn){
            temp_num[temp_num_idx] = '\0';
            num[num_idx] = atoi(temp_num);
            num_idx++;
            temp_num_idx = 0;
            numIn = 0;
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'){
            op = str[i];
            num_2 = num[--num_idx];
            num_1 = num[num_idx-1];
            
            switch (op) {
                case '+':
                    num[num_idx - 1] = num_1 + num_2;
                    break;
                case '-':
                    num[num_idx - 1] = num_1 - num_2;
                    break;
                case '*':
                    num[num_idx - 1] = num_1 * num_2;
                    break;
                case '/':
                    num[num_idx - 1] = num_1 / num_2;
                    break;
                case '%':
                    num[num_idx - 1] = num_1 % num_2;
                    break;
                default:
                    break;
            }
        }else if(str[i] == '?' || str[i] == '~' || str[i] == '&'){
            op = str[i];
            
            switch (op) {
                case '?':
                    if(!printIn){
                        printIn = 1;
                        printf("%d", num[--num_idx]);
                    }else{
                        printf(" %d", num[--num_idx]);
                    }
                    break;
                case '~':
                    temp = num[num_idx - 1];
                    num[num_idx - 1] = num[num_idx - 2];
                    num[num_idx - 2] = temp;
                    break;
                case '&':
                    num[num_idx] = num[num_idx-1];
                    num_idx++;
                    break;
                default:
                    break;
            }
        }
    }
    
    return 0;
}
