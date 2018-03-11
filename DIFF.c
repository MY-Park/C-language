//
//  DIFF.c
//  Test01
//
//  Created by 박민영 on 11/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int max(int num1, int num2);
int min(int num1, int num2);

int main(){
    char arr1[1000][1000];
    char arr2[1000][1000];
    int max_num, min_num;
    
    int N, first, second;
    scanf("%d\n",&N);
    
    for(int i=0; i<N; i++){
        scanf("%d %d\n", &first, &second);
        for(int j=0; j<first; j++){
            fgets(arr1[j], 1000, stdin);
        }
        for(int j=0; j<second; j++){
            fgets(arr2[j], 1000, stdin);
        }
        max_num = max(first, second);
        min_num = min(first, second);
        
        for(int i=0; i<min_num; i++){
            if(strcmp(arr1[i], arr2[i]) != 0){
                printf("%d\n",++i);
                break;
            }else{
                if(i==min_num - 1){
                    if(first == second){
                        printf("%d\n", -1);
                        break;
                    }else{
                        i = i + 2;
                        printf("%d\n", i);
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}

int max(int num1, int num2){
    int result;
    if(num1 >= num2) result = num1;
    else result = num2;
    
    return result;
}

int min(int num1, int num2){
    int result;
    if(num1 <= num2) result = num1;
    else result = num2;
    
    return result;
}
