//
//  B-numbering.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#define SIZE 1024

int main(){
    
    int N, B, n;
    int arr[SIZE];
    char ch;
    
    scanf("%d %d",&N, &B);
    
    for(int i=0; i<N; i++){
        scanf("%d",&n);
        int j=0;
        if(n == 0){
            putchar('0');
            putchar('\n');
            continue;
        }
        while(n != 0){
            arr[j] = n % B;
            j++;
            n /= B;
        }
        j--;
        for(int k=j; k>=0; k--){
            if(arr[k] >= 10){
                ch = 'A' + arr[k] - 10;
            }else{
                ch = '0' + arr[k];
            }
            putchar(ch);
        }
        putchar('\n');
    }
    return 0;
}
