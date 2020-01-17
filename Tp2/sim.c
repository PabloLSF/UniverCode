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
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#define MAX 50000


char* hexTobin(char s);

  int binTodec(char bin, int pont);
 
 

 int binTodec(char bin, int pont) {
 int dec = 0;
   
   
        if(bin == '1'){
            dec=pow(2,pont);
            }
      
    
    return dec;

}

char* hexTobin(char s) {
    char p;
    char *b;
    p = tolower(s);


    switch (p) {
        case '0':
            b = "0000";
            
            break;
        case '1':
            b = "0001";
            
            break;
        case '2':
            b = "0010";
            
            break;
        case '3':
            b = "0011";
            
            break;
        case '4':
            b = "0100";
            
            break;
        case '5':
            b = "0101";
            
            break;
        case '6':
            b = "0110";
            
            break;
        case '7':
            b = "0111";
            
            break;
        case '8':
            b = "1000";
            
            break;
        case '9':
            b = "1001";
            
            break;
        case 'a':
            b = "1010";
            
            break;
        case 'b':
            b = "1011";
            
            break;
        case 'c':
            b = "1100";
            
            break;
        case 'd':
            b = "1101";
            return b;
            break;
        case 'e':
            b = "1110";
           
            break;
        case 'f':
            b = "1111";
            
            break;
    }
    return b;
}

struct vetTraco32 {
    //Usar para armazenar os traços em um vetor.
    // bloco 32 com 2A 8kib
    char tag[20];
    char ind[7];
    char offset[5];
    char comand;
    char binario[32];
    int tagi;
    int indi;
    int offseti;
    int dec;
    int com;
};

struct vetTraco32_16 {
    //Usar para armazenar os traços em um vetor.
    // bloco 32 com md 16kib
    char tag[18];
    char ind[9];
    char offset[5];
    char comand;
    char binario[32];
    int tagi;
    int indi;
    int offseti;
    int dec;
    int com;
};

struct vetTraco64 {
    //Usar para armazenar os traços em um vetor.
    // bloco 64 com 2A 8kib
    char tag[20];
    char ind[6];
    char offset[6];
    char comand;
    char binario[32];
    int tagi;
    int indi;
    int offseti;
    int dec;
    int com;
};

struct vetTraco64_16 {
    //Usar para armazenar os traços em um vetor.
    // bloco 64 com md 16kib
    char tag[18];
    char ind[8];
    char offset[6];
    char comand;
    char binario[32];
    int tagi;
    int indi;
    int offseti;
    int dec;
    int com;
};





struct stats * sim(int tamanho_bloco, int tamanho_cache, int entradas_tlb, char * filename, char * stream) {
    struct stats *saida= malloc(sizeof(struct  stats)); 
    FILE *arq;
    int dec=0;
    int v = 0;
    int j = 0;
    int x=0;
  int TLB[entradas_tlb];
  
   
    int MDTG;
    int MDind;
    char *valorConvertido;
    int missTLB=0;
    int hitTLB=0;
    int hit=0;
    int miss=0;
    int tamVet=1;
    int  A[2];
    char string[MAX];
    int tam;
    char c;
    int i = 0;
    int s;
    //implementar a função TLB e hits
    if(stream == NULL && filename== NULL){
        saida=NULL;
        return saida;
    }else{


  if (tamanho_bloco == 32 && tamanho_cache == 16384 && entradas_tlb == 4) {
        struct vetTraco32_16 vet[1024];
        if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   string[11]='\0';
                    s=0;
                      
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq);    
          
            //usar  a variavel converter para colocar no vetor vet.binario
           
           
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 8;
                for (i = 0; i < 9; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
            

            
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
            for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

            

            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 8;
                for (i = 0; i < 9; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            

        }
  // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
       
        int cont=0;
        int tlb;
        for(i=0;i<4;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
           
            for(i=0;i<4;i++){
                
                if(TLB[i]==tlb){
                    saida->hits_tlb++;
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
                saida->misses_tlb++;
                missTLB++;
            if(k==3){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         
       
                for(j=0;j<v;j++){
            if(vet[j].tagi==MDTG && vet[j].indi==MDind){
                if(vet[j].com==2){
                    miss++;
                    hit--;
                    hitTLB--;
                    
                }else{
                hit++;
                
                }
            }else{
                MDTG=vet[j].tagi;
                MDind=vet[j].indi;
             
                miss++;
            }
            }
        
        cont=cont+((hit*2)+(miss*52)+(hitTLB)+(missTLB*51));
        
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
    
     if (tamanho_bloco == 32 && tamanho_cache == 16384 && entradas_tlb == 8) {
        struct vetTraco32_16 vet[1024];
          if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 
          
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 8;
                for (i = 0; i < 9; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
            

           
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
            for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

            

            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 8;
                for (i = 0; i < 9; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            for (v = 0; v < tamVet; v++) {
                

            }

        }
  // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
       
        int cont=0;
        int tlb;
        for(i=0;i<8;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
           
            for(i=0;i<8;i++){
                
                if(TLB[i]==tlb){
                    saida->hits_tlb++;
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
                saida->misses_tlb++;
                missTLB++;
            if(k==7){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         
       
                for(j=0;j<v;j++){
            if(vet[j].tagi==MDTG && vet[j].indi==MDind){
                if(vet[j].com==2){
                    miss++;
                    saida->misses_l1++;
                    hit--;
                    hitTLB--;
                }else{
                hit++;
                saida->hits_l1++;
                }
            }else{
                MDTG=vet[j].tagi;
                MDind=vet[j].indi;
                saida->misses_l1++;
                miss++;
            }
            }
        
        cont=cont+((hit*2)+(miss*52)+(hitTLB)+(missTLB*51));
        
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    } 
      //alterar para 2 a.
     
      if (tamanho_bloco == 32 && tamanho_cache == 8192 && entradas_tlb == 4) {
        struct vetTraco32 vet[1024];
            if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 

            
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 8;
                for (i = 0; i < 9; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
               
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
           

            
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
              for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                    

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

           
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 19;
                for (i = 0; i < 20; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
               
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
                
                        
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 20;
                x = 6;
                for (i = 0; i < 7; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            
        }
        // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
        int cont=0;
        int tlb;
        for(i=0;i<4;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
            
            for(i=0;i<4;i++){
                
                if(TLB[i]==tlb){
                    
                    hitTLB++;
                    
                    m=1;
                }
               
            }
            if(m==0){
                missTLB++;
                              

                TLB[k]=tlb;
               
            if(k==3){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         for(i=0;i<2;i++){
         A[i]=-1;  
        }
         for(i=0;i<4;i++){
         
        }
        k=0;
                for(j=0;j<v;j++){
                     m=0;
                  for(i=0;i<2;i++){  
            if(vet[j].tagi==A[i] ){
                if(vet[j].com==2){
                    miss++;
                }else{
                hit++;
                 
                m++;
                }
                  }
            }
                       if(m==0){
               A[k]=vet[j].tagi;
               
               
                miss++;
                
            if(k==1){
                        k=0;
                    }else{
                    k++;
                    }
                }
         
                }
        cont=((hit)+(miss*51)+(hitTLB)+(missTLB*51));
         
       
      
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
      
      if (tamanho_bloco == 32 && tamanho_cache == 8192 && entradas_tlb == 8) {
        struct vetTraco32 vet[1024];
            if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 8;
                for (i = 0; i < 9; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


         


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
           

            
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
              for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

           
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 19;
                for (i = 0; i < 20; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 20;
                x = 6;
                for (i = 0; i < 7; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 27;
                dec = 0;
                x = 4;
                for (i = 0; i < 5; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
               
            }
 

           
        }
        // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
        int cont=0;
        int tlb;
        for(i=0;i<8;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
       
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
          
            for(i=0;i<8;i++){
                
                if(TLB[i]==tlb){
                 
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
               
                missTLB++;
            if(k==7){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         for(i=0;i<2;i++){
         A[i]=-1;  
        }
         for(i=0;i<8;i++){
           
        }
        k=0;
                for(j=0;j<v;j++){
                     m=0;
                  for(i=0;i<2;i++){  
            if(vet[j].tagi==A[i] ){
                if(vet[j].com==2){
                    miss++;
                }else{
                hit++;
                m++;
                }
                  }
            }
                       if(m==0){
               A[k]=vet[j].tagi;
               
               
                miss++;
            if(k==1){
                        k=0;
                    }else{
                    k++;
                    }
                }
         
                }
        
        cont=((hit)+(miss*51)+(hitTLB*2)+(missTLB*52));
      
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
 
      if (tamanho_bloco == 64 && tamanho_cache == 16384 && entradas_tlb == 4) {
        struct vetTraco64_16 vet[1024];
           if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 7;
                for (i = 0; i < 8; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
            

          
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
            for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

            

            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 7;
                for (i = 0; i < 8; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            
        }
  // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
       
        int cont=0;
        int tlb;
        for(i=0;i<4;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
           
            for(i=0;i<4;i++){
                
                if(TLB[i]==tlb){
                    saida->hits_tlb++;
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
                saida->misses_tlb++;
                missTLB++;
            if(k==3){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         
       
                for(j=0;j<v;j++){
            if(vet[j].tagi==MDTG && vet[j].indi==MDind){
                if(vet[j].com==2){
                    miss++;
                    saida->misses_l1++;
                    hit--;
                    hitTLB--;
                }else{
                hit++;
                saida->hits_l1++;
                }
            }else{
                MDTG=vet[j].tagi;
                MDind=vet[j].indi;
                saida->misses_l1++;
                miss++;
            }
            }
        
        cont=cont+((hit*2)+(miss*52)+(hitTLB)+(missTLB*51));
        
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
      
      if (tamanho_bloco == 64 && tamanho_cache == 16384 && entradas_tlb == 8) {
        struct vetTraco64_16 vet[1024];
            if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 

          
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 7;
                for (i = 0; i < 8; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
            

            
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
            for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

            

            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 17;
                for (i = 0; i < 18; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 18;
                x = 7;
                for (i = 0; i < 8; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            
        }
  // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
       
        int cont=0;
        int tlb;
        for(i=0;i<8;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
           
            for(i=0;i<8;i++){
                
                if(TLB[i]==tlb){
                    saida->hits_tlb++;
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
                saida->misses_tlb++;
                missTLB++;
            if(k==7){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         
       
                for(j=0;j<v;j++){
            if(vet[j].tagi==MDTG && vet[j].indi==MDind){
                if(vet[j].com==2){
                    miss++;
                    saida->misses_l1++;
                    hit--;
                    hitTLB--;
                }else{
                hit++;
                saida->hits_l1++;
                }
            }else{
                MDTG=vet[j].tagi;
                MDind=vet[j].indi;
                saida->misses_l1++;
                miss++;
            }
            }
        
        cont=cont+((hit*2)+(miss*52)+(hitTLB)+(missTLB*51));
        
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
      
       if (tamanho_bloco == 64 && tamanho_cache == 8192 && entradas_tlb == 4) {
        struct vetTraco64 vet[1024];
           if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                     
                    tamVet++;
                    
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 
        
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 19;
                for (i = 0; i < 20; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 20;
                x = 5;
                for (i = 0; i < 6; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
            

            
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
            for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

            

            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 19;
                for (i = 0; i < 20; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 20;
                x = 5;
                for (i = 0; i < 6; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }

            
        }
  // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
       
        int cont=0;
        int tlb;
        for(i=0;i<4;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
           
            for(i=0;i<4;i++){
                
                if(TLB[i]==tlb){
                    saida->hits_tlb++;
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
                saida->misses_tlb++;
                missTLB++;
            if(k==3){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         
       
                for(j=0;j<v;j++){
            if(vet[j].tagi==MDTG && vet[j].indi==MDind){
                if(vet[j].com==2){
                    miss++;
                    saida->misses_l1++;
                    hit--;
                    hitTLB--;
                }else{
                hit++;
                saida->hits_l1++;
                }
            }else{
                MDTG=vet[j].tagi;
                MDind=vet[j].indi;
                saida->misses_l1++;
                miss++;
            }
            }
        
        cont=cont+((hit*2)+(miss*52)+(hitTLB)+(missTLB*51));
        
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
      
       if (tamanho_bloco == 64 && tamanho_cache == 8192 && entradas_tlb == 8) {
        struct vetTraco64 vet[1024];
            if (filename != NULL) {

            arq = fopen(filename, "r");
             
            do {
               
                //faz a leitura do caracter no arquivo apontado por pont_arq
                c = getc(arq);
                switch (c) {
                    case '0':
                        string[i] = c;
                        i++;
                        break;
                    case '1':
                        string[i] = c;
                        i++;
                        break;

                    case '2':
                        string[i] = c;
                        i++;
                        break;
                    case '3':
                        string[i] = c;
                        i++;
                        break;
                    case '4':
                        string[i] = c;
                        i++;
                        break;
                    case '5':
                        string[i] = c;
                        i++;
                        break;
                    case '6':
                        string[i] = c;
                        i++;
                        break;
                    case '7':
                        string[i] = c;
                        i++;
                        break;
                    case '8':
                        string[i] = c;
                        i++;
                        break;
                    case '9':
                        string[i] = c;
                        i++;
                        break;
                    case 'A':
                        string[i] = c;
                        i++;
                        break;
                    case 'B':
                        string[i] = c;
                        i++;
                        break;
                    case 'C':
                        string[i] = c;
                        i++;
                        break;
                    case 'D':
                        string[i] = c;
                        i++;
                        break;
                    case 'E':
                        string[i] = c;
                        i++;
                        break;
                    case 'F':
                        string[i] = c;
                        i++;
                        break;
                    case 'R':
                        string[i] = c;
                        i++;
                        break;
                    case 'W':
                        
                        string[i] = c;
                        i++;
                        break;
                    case ' ':
                        string[i] = c;
                        i++;
                        break;
                    case '\n':
                        string[i] = c;
                        i++;
                        break;
                    case '\0':
                        string[i] = c;
                        i++;
                        break;
                }
               
                if(i==11){
                   
                    s=0;
                       
                        j = 0;
                if (string[s] == 'W' || string[s] == 'R') {
                    v++;
                    tamVet++;
                      
                     c = string[s];
                     
                    vet[v].comand = c;
                    if(c=='W'){
                         
                        vet[v].com=2;
                    }
                    

                    s++;
                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                    
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                     
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    s++;
                    valorConvertido = hexTobin(string[s]);
                   
                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                
                   }
                       i = 0; 
                }


                //exibe o caracter lido na tela


            } while (c != EOF);
            
        fclose(arq); 
          
            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 19;
                for (i = 0; i < 20; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 20;
                x = 5;
                for (i = 0; i < 6; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }


            


        } else {
            tam=strlen(stream);
             strcpy(string, stream);

            for (i = 0; i < tam; i++) {
                if (string[i] == '\n') {
                    j++;

                }
            }
            

            
            tamVet = j;
            //usar  a variavel converter para colocar no vetor vet.binario
            v = -1;
            for (i = 0; i < tam; i++) {
                j = 0;
                if (string[i] == 'W' || string[i] == 'R') {
                    v++;
                     c = string[i];
                    vet[v].comand = c;
                    if(c=='W'){
                        vet[v].com=2;
                    }
                   

                    i++;
                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    i++;
                    valorConvertido = hexTobin(string[i]);

                    vet[v].binario[j] = valorConvertido[0];
                    j++;
                    vet[v].binario[j] = valorConvertido[1];
                    j++;
                    vet[v].binario[j] = valorConvertido[2];
                    j++;
                    vet[v].binario[j] = valorConvertido[3];
                    j++;

                    vet[v].binario[j] = '\0';





                }
            }

            

            i = 0;
            for (v = 0; v < tamVet; v++) {
                j = 0;
                dec = 0;
                x = 19;
                for (i = 0; i < 20; i++) {
                    vet[v].tag[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].tag[i], x);
                    j++;
                    x--;

                }
                vet[v].tagi = dec;
                vet[v].tag[i] = '\0';
               
            }

            for (v = 0; v < tamVet; v++) {
                dec = 0;
                j = 20;
                x = 5;
                for (i = 0; i < 6; i++) {
                    vet[v].ind[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].ind[i], x);
                    j++;
                    x--;


                }
                vet[v].indi = dec;
                vet[v].ind[i] = '\0';
                
            }

            for (v = 0; v < tamVet; v++) {
                j = 26;
                dec = 0;
                x = 5;
                for (i = 0; i <6; i++) {
                    vet[v].offset[i] = vet[v].binario[j];
                    dec = dec + binTodec(vet[v].offset[i], x);
                    j++;
                    x--;

                }
                vet[v].offseti = dec;
                vet[v].offset[i] = '\0';
                
            }

            
        }
  // tlb = 51 + 1
	// cache = 52 + 2
	// total = 52 + 54 = 106
       
        int cont=0;
        int tlb;
        for(i=0;i<8;i++){
          TLB[i]=-1;  
        }
        int k=0;
        int m=0;
        for(j=0;j<v;j++){
            m=0;
            tlb=vet[j].tagi+vet[j].indi;
           
            for(i=0;i<4;i++){
                
                if(TLB[i]==tlb){
                    saida->hits_tlb++;
                    hitTLB++;
                    m++;
                }
               
            }
            if(m==0){
                TLB[k]=tlb;
                saida->misses_tlb++;
                missTLB++;
            if(k==3){
                        k=0;
                    }else{
                    k++;
                    }
            }
        }
         
       
                for(j=0;j<v;j++){
            if(vet[j].tagi==MDTG && vet[j].indi==MDind){
                if(vet[j].com==2){
                    miss++;
                    saida->misses_l1++;
                    hit--;
                    hitTLB--;
                }else{
                hit++;
                saida->hits_l1++;
                }
            }else{
                MDTG=vet[j].tagi;
                MDind=vet[j].indi;
                saida->misses_l1++;
                miss++;
            }
            }
        
        cont=cont+((hit*2)+(miss*52)+(hitTLB)+(missTLB*51));
        
        saida->hits_l1=hit;
        saida->hits_tlb=hitTLB;
        saida->misses_l1=miss;
        saida->misses_tlb=missTLB;
        saida->cycles=cont;
        return saida;
        
    }
      
      
      
  
    
    else{
        saida=NULL;
        return saida;
    }
    }     
}