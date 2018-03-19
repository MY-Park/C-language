//
//  tail.c
//  Test01
//
//  Created by 박민영 on 19/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 10000

char str[SIZE][SIZE];

int main(){
    int idx = 0;
    int N;
    scanf("%d", &N);
    getchar();
    char str_in[SIZE];
    char ch;
    int in_idx;
    
    int inFile = 1;
    
    while(inFile){
        in_idx = 0;
        while((ch=getchar())!=EOF && ch!='\n'){
            str_in[in_idx] = ch;
            in_idx++;
        }
        if(ch == EOF) inFile = 0;
        str_in[in_idx] = '\0';
        
        strcpy(str[idx], str_in);
        idx++;
    }
    //idx is num of strings.
    
    if(idx <= N){
        for(int i=0; i<idx; i++) {
            if(i == idx-1) printf("%s", str[i]);
            else printf("%s\n", str[i]);
        }
    }else{
        for(int i=idx-N-1; i<idx; i++) {
            if(i == idx-1) printf("%s", str[i]);
            else printf("%s\n", str[i]);
        }
    }
    
    return 0;
}


