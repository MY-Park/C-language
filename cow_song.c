//
//  cow_song.c
//  Test01
//
//  Created by 박민영 on 04/09/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#define SIZE 1024

int arr[SIZE];
int init = 3;
int len[30];

int find_k(int input){
    int k = 0;

    len[k] = init;
    k++;
    
    while(input > len[k - 1]){
        len[k] = len[k - 1] * 2 + k + 3;
        k++;
    }
    
    return k;
}

char find(int k, int input){
    if(input <= len[k-1]) return find(k-1, input);
    else if(input == len[k-1] + 1) return 'm';
    else if(input <= len[k-1] + k + 3) return 'o';
    else return find(k-1, input - (len[k-1] + k + 3));
}

int main(){
    int input;
    scanf("%d", &input);
    
    putchar(find(find_k(input), input));
    
    return 0;
}

