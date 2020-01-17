/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aluno.c
 * Author: Pablo
 *
 * Created on 25 de Maio de 2018, 01:30
 */

#include "sim.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <malloc.h>



int main() {
    
 struct stats * res;
 
        
//test1 retorna nulo
res=sim(32, 16384, 4, NULL, NULL);
if(res==NULL){
    printf("nulo\n");
}

//test2 retorna nulo
res=sim(32, 84, 4, NULL, NULL);
if(res==NULL){
    printf("nulo\n");
}	

//test3 retorna nulo
res=sim(32, 16384, 7, NULL, NULL);
if(res==NULL){
    printf("nulo\n");
}	 

   // teste de texto      
res=sim(32, 16384, 8, "test.txt", NULL);
	 printf("%d\n",res->cycles);   
     
         
         
//comparativo de qual tem menos tempo         
         
         int test_ciclo[8],i,valormin=0,j;
         //test1
res=sim(32, 8192, 8, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	test_ciclo[0]=res->cycles; 
        //teste2
res=sim(32, 8192, 4, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	test_ciclo[1]=res->cycles; 
        //teste3 
res=sim(32, 16384, 8, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	 test_ciclo[2]=res->cycles; 
         //teste4
res=sim(32, 16384, 4, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	 test_ciclo[3]=res->cycles;
         //teste5
res=sim(64, 8192, 8, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	 test_ciclo[4]=res->cycles;
         //teste6
res=sim(64, 8192, 4, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	test_ciclo[5]=res->cycles;
        //teste7
res=sim(64, 16384, 8, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	test_ciclo[6]=res->cycles;
        //teste8
res=sim(64, 16384, 4, NULL, "R 000010FA\nR 000000FA\nR 00008100\nR 000013FF\nR 0000270A\nR 00000D05\nR 0000000B\n0000001B\n");
	test_ciclo[7]=res->cycles;
  
for(i=0;i<8;i++){
    if(valormin<test_ciclo[i]){
        valormin=test_ciclo[i];
        j=i;
    }
}        
        printf("O test  %d  tem o menor tempo ",j+1);
    return (EXIT_SUCCESS);
}

