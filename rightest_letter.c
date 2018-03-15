//
//  rightest_letter.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(){
    char str[SIZE];
    char ch;
    int check = 0;
    int len, right = 0;
    
    ch = getchar();
    getchar();
    
    //if(ch >= 'a' && ch <= 'z') ch -= 32;
    
    fgets(str, SIZE, stdin);
    
    len = (int)strlen(str);
    
    for(int i=0; i<len-1; i++){
        if(str[i] == ch){
            right = i;
            check = 1;
        }
    }
    if(right == 0 && !check) printf("null");
    else printf("%d",right);
    
    return 0;
}
