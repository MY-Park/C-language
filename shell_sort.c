//
//  shell_sort.c
//  Test01
//
//  Created by 박민영 on 04/16/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 1024

int arr[SIZE];

void shell_sort(int arr[], int n){
    int gap, j, i, temp;
    
    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            for(j = i-gap; j>=0 && arr[j] > arr[j+gap]; j-=gap){
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
        }
    }
}

int main(){
    int N;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    
    shell_sort(arr, N);
    
    for(int i=0; i<N; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
