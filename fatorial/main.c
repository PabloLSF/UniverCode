/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pablo
 *
 * Created on 25 de Abril de 2018, 16:36
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */int fatorial(int x){
 int f,j,c;
 j=x;
 c=x;
 if(x>0){
 for(j=j-1;j>0;j--){
     c=c*j;
     printf("%d\n",c);
 
 }
 return c;
 }else{
	return -1;
	}
}
int main(int argc, char** argv) {
    int x;
    x=fatorial(5);
printf("%d",x);
    return (EXIT_SUCCESS);
}

