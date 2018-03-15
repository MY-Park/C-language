//
//  diamond_drawing.c
//  Test01
//
//  Created by 박민영 on 15/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    int H;
    int l,r,j;
    
    scanf("%d",&H);
    l = r = (H / 2) + 1;
    
    for(int i=0; i<(H / 2) + 1; i++){
        for(j=0; j<l-1; j++){
            putchar(' ');
        }
        for(; j<r; j++) {
            putchar('*');
        }
        
        l--;
        r++;
        putchar('\n');
    }
    l = l + 2;
    r = r - 2;
    
    for(int i=0; i<(H / 2); i++){
        for(j=0; j<l-1; j++){
            putchar(' ');
        }
        for(; j<r; j++){
            putchar('*');
        }
        
        l++;
        r--;
        putchar('\n');
    }
    return 0;
}

