//
//  main.c
//  Test
//
//  Created by 박민영 on 10/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SAVE 100000

int main() {
    // insert code here...
    
    char buffer[MAX_SAVE];
    
    char ch;
    
    int i=0, j, k, l;
    int formlen = 0;
    char var[MAX_SAVE];
    char input[MAX_SAVE];
    
    int d_val, o_val, c_val, u_val;
    double f_val, e_val;
    char x_val, X_val;
    
    int sfin, seof = 0;
    
    ch = getchar();
    
    while(ch != EOF){
        
        l = 0;
        ch = getchar();
        if(ch == EOF) seof = 1;
        sfin = 0;
        while(ch != '\n' && ch != EOF && seof != 1 && ch != '\0'){
            if(ch == '\"'){
                sfin = 1;
                formlen = i;
                buffer[i] = ch;
                ch = getchar(); // remove white space
                if(ch == EOF){
                    seof = 1;
                    break;
                }
                if (ch != '\n'){
                    ch = getchar();
                    if(ch == EOF){
                        seof = 1;
                        break;
                    }
                }
            }else{
                if(sfin){
                    var[l] = ch;
                    ch = getchar();
                    if(ch == EOF){
                        seof = 1;
                        break;
                    }
                    l++;
                }else{
                    buffer[i] = ch;
                    ch = getchar();
                    if(ch == EOF){
                        seof = 1;
                        break;
                    }
                    i++;
                }
            }
        }
        var[l] = '\0';
        sfin = 0;
        l = 0;
        i = 0;
        
        char str[2];
        
        for(j=0; j<formlen; j++){
            if(buffer[j] == '%' && buffer[j+1] != '%'){
                str[0] = '%';
                str[1] = buffer[j+1];
                
                k = 0;
                while(var[l] != ' ' && var[l] != '\n' && var[l] != '\0'){
                    input[k] = var[l];
                    l++;
                    k++;
                }
                l++;
                input[k] = '\0';
                
                if(str[1] == 'd'){
                    d_val = atoi(input);
                    printf(str, d_val);
                }else if(str[1] == 'f'){
                    f_val = atof(input);
                    printf(str, f_val);
                }else if(str[1] == 'x'){
                    x_val = input[0];
                    printf(str, x_val);
                }else if(str[1] == 'X'){
                    X_val = input[0];
                    printf(str, X_val);
                }else if(str[1] == 'o'){
                    o_val = atoi(input);
                    printf(str, o_val);
                }else if(str[1] == 'c'){
                    c_val = atoi(input);
                    printf(str, c_val);
                }else if(str[1] == 'e'){
                    e_val = atof(input);
                    printf(str, e_val);
                }else if(str[1] == 'u'){
                    u_val = atoi(input);
                    printf(str, u_val);
                }else{
                    printf(str, input);
                }
                j++;
            }
            else{
                putchar(buffer[j]);
            }
        }
        printf("\n");
        
        if(seof == 1) break;
        if((ch=getchar())!=EOF) continue;
        else break;

    }
    return 0;
}
