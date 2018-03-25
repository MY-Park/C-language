//
//  rock_paper_scissors.c
//  Test01
//
//  Created by 박민영 on 25/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 10000

int main(){
    
    char player1[SIZE];
    char player2[SIZE];
    
    int player1_wins, player2_wins;
    
    int len;
    
    int whileIn = 1;
    while(1){
        fgets(player1, SIZE, stdin);
        fgets(player2, SIZE, stdin);
        
        len = (int)strlen(player1);
        
        player1_wins = player2_wins = 0;
        for(int i=0; i<len-1; i++){
            
            if(player1[i] == 'E' && player1[i] == 'E'){
                whileIn = 0;
                break;
            }
            if(player1[i] == 'R'){
                if(player2[i] == 'R'){
                    continue;
                }else if(player2[i] == 'S'){
                    player1_wins++;
                }else{
                    player2_wins++;
                }
            }else if(player1[i] == 'S'){
                if(player2[i] == 'R'){
                    player2_wins++;
                }else if(player2[i] == 'S'){
                    continue;
                }else{
                    player1_wins++;
                }
            }else{
                if(player2[i] == 'R'){
                    player1_wins++;
                }else if(player2[i] == 'S'){
                    player2_wins++;
                }else{
                    continue;
                }
            }
        }
        if(!whileIn) break;
        printf("P1: %d\nP2: %d\n",player1_wins, player2_wins);
    }
    
    return 0;
}
