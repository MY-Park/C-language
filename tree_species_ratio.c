//
//  tree_species_ratio.c
//  Test01
//
//  Created by 박민영 on 28/03/2018.
//  Copyright © 2018 박민영. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 100
#define SIZE 20000

struct Tree{
    char name[NAME_SIZE];
    int num;
};

char * name_arr[SIZE];

struct Tree tree[SIZE];

int binsearch(char to_find[], n){
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while(low <= high){
        if(to_find < name_arr[mid].name) high =
    }
}
int main(){

    struct Tree temp_tree;
    
    temp_tree.num = 0;
    
    char str[NAME_SIZE];
    int tree_len = 0;
    int temp_idx = 0;
    int max_leaf_idx;
    
    int total_num = 0;

    int len;
    
    int name_idx = 0;

    while(fgets(str, NAME_SIZE, stdin) != NULL){
        name_arr[name_idx] = strdup(str);
        name_idx++;
    }
    
    while(total_num < name_idx){
        strcpy(str, name_arr[total_num]);
        total_num++;
        if(tree_len == 0){
            strcpy(tree[0].name, str);
            len = (int)strlen(str);
            tree[0].num = 1;
            tree_len++;
            continue;
        }
        if(strcmp(temp_tree.name, str) == 0){
            tree[temp_idx].num++;
            continue;
        }
        
        for(int i=0; i<tree_len; i++){

            if(strcmp(tree[i].name, str)==0){
                tree[i].num++;
                break;
            }else if(i == tree_len-1){

                strcpy(tree[tree_len].name, str);
                tree[tree_len].num = 1;
                temp_idx = tree_len;
                tree_len++;
                while(1){
                    strcpy(temp_tree.name, tree[temp_idx].name);
                    temp_tree.num = tree[temp_idx].num;
                    
                    if(temp_idx == 0){ // root node
                        break;
                    }else if(strcmp(tree[temp_idx / 2].name, tree[temp_idx].name) > 0){
                        strcpy(temp_tree.name, tree[temp_idx].name);
                        strcpy(tree[temp_idx].name, tree[temp_idx / 2].name);
                        strcpy(tree[temp_idx / 2].name, temp_tree.name);
                        
                        temp_tree.num = tree[temp_idx].num;
                        tree[temp_idx].num = tree[temp_idx / 2].num;
                        tree[temp_idx / 2].num = tree[temp_idx].num;
                        
                        temp_idx = temp_idx / 2;
                    }else break;
                }
                break;
            }
        }
    }
    
    while(tree_len > 0){
        for(int i=0; ;i++){
            if(tree[0].name[i] == '\n') break;
            else putchar(tree[0].name[i]);
        }
        printf(" %.4f\n", 100.0 * tree[0].num / total_num);

        tree_len--;
        
        if(tree_len == 0) break;
        
        strcpy(tree[0].name, tree[tree_len].name);
        tree[0].num = tree[tree_len].num;
        
        temp_idx = 0;
        
        while(1){
            if(temp_idx * 2 + 1 > tree_len-1) break;
            else if(temp_idx * 2 + 1 == tree_len-1) max_leaf_idx = temp_idx * 2 + 1;
            else{
                if(strcmp(tree[temp_idx * 2 + 1].name, tree[temp_idx * 2 + 2].name) < 0){
                    max_leaf_idx = temp_idx * 2 + 1;
                }else max_leaf_idx = temp_idx * 2 + 2;
            }
            
            if(strcmp(tree[temp_idx].name, tree[max_leaf_idx].name) > 0){
                strcpy(temp_tree.name, tree[temp_idx].name);
                strcpy(tree[temp_idx].name, tree[max_leaf_idx].name);
                strcpy(tree[max_leaf_idx].name, temp_tree.name);
                
                temp_tree.num = tree[temp_idx].num;
                tree[temp_idx].num = tree[max_leaf_idx].num;
                tree[max_leaf_idx].num = temp_tree.num;
                
                temp_idx = max_leaf_idx;
            }else break;
        }
        
    }
    
    return 0;
}
