//
//  valid_password.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int t, valid, num;
    char pwd[101];
    
    scanf("%d",&t);
    getchar();
    
    for(; t > 0; t--){
        valid = 1;
        num = 0;
        
        fgets(pwd, 101, stdin);
        if(strlen(pwd)-1 < 8){
            valid *= 0;
        }
        else{
            for(int i=0; i<strlen(pwd)-1; i++){
                if(!isalnum(pwd[i]))
                    valid *= 0;
                else if(isdigit(pwd[i]))
                    num++;
            }
            
            if(num < 2) valid *= 0;
        }
        
        if(valid) printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
