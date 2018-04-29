//
//  domino2.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int rel[20002];
    int dom[10001];
    
    int t, m, n, l, idx, res;
    
    scanf("%d",&t);
    
    for(; t > 0; t--){
        scanf("%d %d %d", &m, &n, &l);
        
        for(int i=1; i<=m; i++)
            dom[i] = 1;
        
        for(int i=0; i<n; i++)
            scanf("%d %d", &rel[2 * i], &rel[2 * i + 1]);
        
        
        for(int i=0; i<l; i++){
            scanf("%d", &idx);
            dom[idx] = 0;
        }
        
        for(int i=0; i<n; i++)
            if(!dom[rel[2 * i]]) dom[rel[2 * i + 1]] = 0;
       
        res = 0;
        for(int i=1; i<=m; i++)
            if(!dom[i]) res++;
        
        printf("%d\n",res);
    }
    return 0;
}
