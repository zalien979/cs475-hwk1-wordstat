/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

int printHistogram(int max, int lets[]){
    int temp[26];
    for(int i=0; i<26;i++){
         temp[i]=lets[i];
    }
    for(int i=max; i>0; i--){
        for(int j=0; j<26; j++){
            if(lets[j]==i){
              printf("* ");
              lets[j]=lets[j]-1;
            }
            else{ 
                printf("  ");
            }
        }
       printf("\n");
    }
    printf("a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
    //printf(" a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z");
    for(int i=0; i<26;i++){
        printf("%d ", temp[i]);
    }
    printf("\n");
    return 0;
}
// TODO: function definitions for dealing with histogram below