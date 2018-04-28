//
//  lottery.c
//  Test01
//
//  Created by 박민영 on 28/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int num[50] = {0};
    int N, j;
    char in[20];
    char temp[3];
    int res;
    
    while(1){
        scanf("%d", &N);
        if(!N) break;
        getchar();
        res = 1;
        for(; N > 0; N--){
            fgets(in, 20, stdin);
            j = 0;
            for(int i=0; i<strlen(in); i++){
                if((temp[j] = in[i]) == ' '|| in[i] == '\n' || in[i] == '\0'){
                    temp[j] = '\0';
                    num[atoi(temp)]++;
                    j = 0;
                }else j++;
            }
        }
        
        for(int i=1; i<50; i++){
            if(num[i] == 0 && res) {
                printf("No\n");
                res = 0;
            }else if(!res){
                num[i] = 0;
            }else{
                num[i] = 0;
            }
        }
        if(res) printf("Yes\n");
        
    }
    return 0;
}
