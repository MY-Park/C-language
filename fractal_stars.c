//
//  fractal_stars.c
//  Test01
//
//  Created by 박민영 on 29/04/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void draw(int, int, int);
void trim(char str[]);

char output[3100][6200];

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n*2-1; j++)
            output[i][j] = ' ';
    draw(n, n-1, n-1);
    
    for(int i=0; i<n; i++){
        trim(output[i]);
        printf("%s\n",output[i]);
    }
    return 0;
}

void draw(int h, int x, int y){
    if(h==3){
        output[x-2][y] = output[x-1][y-1] = output[x-1][y+1] = '*';
        output[x][y-2] = output[x][y-1] = output[x][y] = output[x][y+1] = output[x][y+2] = '*';
        return;
    }
    draw(h/2, x-(h/2), y);
    draw(h/2, x, y-(h/2));
    draw(h/2, x, y+(h/2));
}

void trim(char str[]){
    int i = (int)strlen(str);
    for(; i>0; i--){
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != EOF && str[i] != '\0') break;
    }
    str[i+1] = '\0';
}
