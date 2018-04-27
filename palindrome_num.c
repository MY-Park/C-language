//
//  palindrome_num.c
//  Test01
//
//  Created by 박민영 on 27/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int re_n;
    int n;
    int cp_n;
    
    int T;
    scanf("%d",&T);
    
    for(int i=0; i<T; i++){
        re_n = 0;
        scanf("%d", &n);
        
        for(cp_n = n; cp_n != 0; cp_n /= 10)
            re_n = re_n * 10 + cp_n % 10;
        
        if(re_n == n) printf("Y\n");
        else printf("N\n");
    }
    
    return 0;
}
