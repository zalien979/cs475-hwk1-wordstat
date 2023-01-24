/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	int mode=1;
	int lets[26];
	while(mode!=0){
	if (mode==1){
	printf("Enter strings (# to stop):");
	char stop= '$';
	for(int i=0; i<26; i++){
		lets[i]=0;
	}
	int wordcount=0;
	while(stop!='#'){
		char line[128];
		fgets(line, 128, stdin);
		char *token= strtok(line, " ");
		
		while (token != NULL) {
			int len=strlen(token);
		stop=line[0];
			for(int i=0; i<len &&token[i]!='\0';i++){
			
				if(token[i]>64 &&token[i]<91){
					lets[(token[i]-64)]++;
				}
				else if(token[i]>96 &&token[i]<123){
					lets[(token[i]-97)]++;
				}
			}
			wordcount++;
     		token = strtok(NULL, " ");
			
    }
	
	}
	
	mode=2;
	}
	if( mode==2){
	int max=0;
	for(int i=0; i<26; i++){
		if(lets[i]>max){
			max=lets[i];
		}
	}
	int opt=0;
	while(opt!=4){
	opt=getMenuOption();
	if(opt==1){
	int vows=0;
	int cons=0;
	int tot=0;
	float vper;
	float cper;
	for(int i=0; i<26; i++){
		if(i==0||i==4||i==8||i==14||i==20){
			vows= vows+lets[i];
			tot=tot +lets[i];
		}
		else{
			cons=cons +lets[i];
			tot=tot +lets[i];
		}

	}
	vper=(float)vows/tot * 100;
	cper=(float)cons/tot * 100;
	printf("Vowels = %d (%.2f%c), Consonants = %d (%.2f%c), Total= %d\n", vows, vper, 37, cons, cper, 37, tot);

	}
	else if(opt==2){
	printHistogram(max, lets);
	}
	else if(opt==3){
		mode=1;
		opt=4;
	}
	else if(opt==4){
		mode=0;
		
	}
	else{
		printf("Error please enter valid input\n");
	}
	}
	}
	}
	printf("Exiting...\n");

	return 0;
}
