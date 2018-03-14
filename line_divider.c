//
//  line_divider.c
//  Test01
//
//  Created by 박민영 on 14/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#define SIZE 1000

int main(){
    int pnt = 0;
    char str[SIZE];
    int IN;
    int LINEIN;
    
    while(fgets(str, SIZE, stdin) != NULL){
        IN = 1;
        pnt = 0;
        LINEIN = 1;
        
        while(IN){
            for(int i=0; i<20; i++){
                if(str[pnt + i] == '\n'){
                    for(int j=0; j<i+1; j++){
                        putchar(str[pnt + j]);
                    }
                    putchar('\n');
                    pnt += i + 1;
                    IN = 0;
                    LINEIN = 0;
                    break;
                }
            }
            if(!LINEIN) continue;
            
            if(str[pnt + 20] == ' '){
                for(int i=0; i<20; i++) putchar(str[pnt + i]);
                putchar('\n');
                pnt += 21;
            }else if(str[pnt + 19] == ' '){
                for(int i=0; i<19; i++) putchar(str[pnt + i]);
                putchar('\n');
                pnt += 20;
            }else if(str[pnt + 18] == ' '){
                for(int i=0; i<18; i++) putchar(str[pnt + i]);
                putchar('\n');
                pnt += 19;
            }else{
                for(int i=0; i<19; i++) putchar(str[pnt + i]);
                putchar('-');
                putchar('\n');
                pnt += 19;
            }
        }
    }
    return 0;
}

