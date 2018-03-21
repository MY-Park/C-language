//
//  reverse_polish_calculator_var.c
//  Test01
//
//  Created by 박민영 on 21/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000

int main(){
    double alphabet[26];
    char in[4];
    char str[SIZE];
    int len;
    
    for(int i=0; i<26; i++){
        fgets(str, SIZE, stdin);
        len = (int)strlen(str);
        for(int j=0; j<len; j++){
            if(str[j+2] == '\n') {
                in[j] = '\0';
                break;
            }
            in[j] = str[j+2];
        }
        
        alphabet[i] = atof(in);
    }

    fgets(str, SIZE, stdin);
    
    double num[100]; //number stack
    int num_idx = 0;
    char op;
    
    double num_1, num_2;
    int numIn = 0;
    
    len = (int)strlen(str);
    
    for(int i=0; i<len; i++){
        if(str[i] >= 'a' &&  str[i] <= 'z'){
            num[num_idx] = alphabet[str[i]-'a'];
            num_idx++;
            numIn = 1;
        }else if(str[i] == ' ' && numIn){
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
                default:
                    break;
            }
        }
    }
    
    printf("%.6f", num[0]);
    
    return 0;
}
