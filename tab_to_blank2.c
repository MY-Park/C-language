//
//  tab_to_blank2.c
//  Test01
//
//  Created by 박민영 on 19/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    char ch;
    int cnt = 0;
    int quo = 0;
    int mul = 0;
    
    while((ch=getchar())!=EOF){
        if(ch == '\n'){
            cnt = 0;
            putchar(ch);
            continue;
        }
        
        if(ch != '\t'){
            cnt++;
            putchar(ch);
        }else{
            quo = cnt / 4;
            mul = (quo + 1) * 4;
            for(; cnt < mul; cnt++){
                putchar(' ');
            }
            
        }
    }
    return 0;
}


