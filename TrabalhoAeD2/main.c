/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pablo L. Sanches
 *
 * Created on 23 de Outubro de 2016, 19:44
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _MATH_H
/*
 * 
 */
struct listaHash {
    char palavra[100];
};
struct tabeltaHash {
    int tam;
    double fc;
    struct listaHash x[];
    
    
} tabl,tab2,tabquad, auxl,aux2,auxquad;
struct comandWord{
    char word[100];
    char comando[10];
}cw;
int menu(void);
void reHashComplit(struct tabeltaHash  tab , struct tabeltaHash aux);
void transfer(struct tabeltaHash  tab , struct tabeltaHash aux);
void ImprimeTest(struct tabeltaHash  tab);
int BuscaPalavra(struct tabeltaHash tab,char *nome, int f);
void ApagaPalavra(struct tabeltaHash  tab,char *p,int f);
unsigned rot_hash(void *key, int len);
int FuncHash(int cod, int n);
int FuncHashLi(int cod, int n, int i);
int FuncHash2(int cod, int n);
int FuncHashQuad(int cod, int n);
//int FuncHashEncad(int cod, int n);
void zeraTable(struct tabeltaHash  tab);
void insereNaHash(struct tabeltaHash  tab,struct tabeltaHash  aux,char *p,int f);
int reHash(int tam);
int indComand(int i,char *p);
int indword(int i,char *p);
void comand(int i,char *p);
void word(int i,char *p);
int teststring(char *p);
int main(int argc, char** argv) {
    FILE *arq;
    int i,j;
    char test[1000000];
   tabl.tam = 500;
   zeraTable(tabl);
   tab2.tam = 500;
   zeraTable(tab2);
   tabquad.tam = 500;
   zeraTable(tabquad);
    arq = fopen("Test.txt", "r");
    if (arq == NULL){
    printf("Problemas na CRIACAO do arquivo\n");
    exit(0);
} else{
        while( (fgets(test,1000000,arq))!= NULL  ){         			
	fclose(arq);
}
}
  
    
    
   
     int escolha;
    for (;;) {
        escolha = menu();
        switch (escolha) {
            case 1: 
                    printf("passo \n");
                    int t=0;
                    int f=0;
                    int v=0;
                    i=0;
                    j=0;                 
                    while(test[j]!='\0'){
                    comand( j,test);
                    t=teststring(cw.comando);
                    i=indComand(j,test);
                    j=i;
                     word(j,test);
                     i=indword(j,test);
                     j=i;
                     
                     f = rot_hash(cw.word, strlen(cw.word));
                     v = FuncHash(f, tabl.tam);
                     switch(t){
                         case 1:
                          
                                printf("get\n");
                               
                             break;
                         case 2:
                             
                             insereNaHash(tabl,auxl,cw.word,v);
                          
                                 printf("%d\n",v);
                             for (f = 0; f < 100; f++) {
                             tabl.x[v].palavra[f]= cw.word[f];

                                              }
                                 printf("SUCCESS \n");
                               
                             break;
                         case 3:
                              
                                    printf("DELETE \n");
                            
                             break;    
                     }
                    }
                    
    
                break;
                
                
                
            case 2: 
                    printf("passo \n");
                    
                    i=0;
                    j=0;                 
                    while(test[j]!='\0'){
                    comand( j,test);
                    t=teststring(cw.comando);
                    i=indComand(j,test);
                    j=i;
                     word(j,test);
                     i=indword(j,test);
                     j=i;
                     
                     f = rot_hash(cw.word, strlen(cw.word));
                     v = FuncHash2(f, tabl.tam);
                     switch(t){
                         case 1:
                          
                                printf("get\n");
                               
                             break;
                         case 2:
                             
                             insereNaHash(tabl,auxl,cw.word,v);
                          
                                 printf("%d\n",v);
                             for (f = 0; f < 100; f++) {
                             tabl.x[v].palavra[f]= cw.word[f];

                                              }
                                 printf("SUCCESS \n");
                               
                             break;
                         case 3:
                              
                                    printf("DELETE \n");
                            
                             break;    
                     }
                    }
                    
    
                break;
                
            case 3: 
                     printf("passo \n");
                   
                    i=0;
                    j=0;                 
                    while(test[j]!='\0'){
                    comand( j,test);
                    t=teststring(cw.comando);
                    i=indComand(j,test);
                    j=i;
                     word(j,test);
                     i=indword(j,test);
                     j=i;
                     
                     f = rot_hash(cw.word, strlen(cw.word));
                     v = FuncHashQuad(f, tabl.tam);
                     switch(t){
                         case 1:
                          
                                printf("get\n");
                               
                             break;
                         case 2:
                             
                             insereNaHash(tabl,auxl,cw.word,v);
                          
                                 printf("%d\n",v);
                             for (f = 0; f < 100; f++) {
                             tabl.x[v].palavra[f]= cw.word[f];

                                              }
                                 printf("SUCCESS \n");
                               
                             break;
                         case 3:
                              
                                    printf("DELETE \n");
                            
                             break;    
                     }
                    }
                    
    
                break;
                
            case 4: exit(0);
                break;
        }
    }
    return (EXIT_SUCCESS);
}

int teststring(char *p){
    int c = 0;
    char g[10]="GET";
      if (strcmp(p,g) == 0) {
          c=1;  
          return c;
        }
    char i[10]="INSERT";
    if (strcmp(p,i) == 0) {
          c=2;  
          return c;
        }
    char d[10]="DELETE";
    if (strcmp(p,d) == 0) {
          c=3;  
          return c;
        }
    
    
    
}
// retira um numero do comando da string do arquivo
int indComand(int i,char *p){
    int j=i;
   
    while(p[j]!=' '){
        j++;
    }
    if(p[j]=='\0'){
       return j; 
    }else{
    j++;
    j++;
    return j;
    }
}
int indword(int i,char *p){
    int j=i;
    int c=0;
   
    while(p[j]!='"'){
        cw.word[c]=p[j];
        j++;
        c++;
    }
    if(p[j]=='\0'){
        
        return j; 
    }else{
    
    j++;
    return j;
    }
}
//retira a string de comando da string do arquivo
void comand(int i,char *p){
    int j=i;
    int c=0;
   
    while(p[j]!=' '){
        cw.comando[c]=p[j];
        j++;
        c++;
    }
    
    
}
void word(int i,char *p){
    int j=i;
    int c=0;
   
    while(p[j]!='"'){
        cw.word[c]=p[j];
        j++;
        c++;
    }
    
}
// pega a string e gera um cod
unsigned rot_hash(void *key, int len){
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h = (h << 4) ^ (h >> 28) ^ p[i];
    }

    return h;
}
//recebe o codigo da letra e gera um codigo hash

int FuncHash(int cod, int n) {
    int val = 0;
    val = cod % n;
    return val;

}

//recebe o codigo da letra e gera um codigo hashLinear
int FuncHashLi(int cod, int n, int i){
    int val = 0;
    
    val = (i+cod) %( n- 1);
    return val;
}
//recebe o codigo da letra e gera um codigo hash2
int FuncHash2(int cod, int n) {
    
    int val = 0;
    val = 1+(cod %( n- 1));
    return val;
 
}

//recebe o codigo e aplica hash quad
int FuncHashQuad(int cod, int n){
    int val = 0;
   
    val =(cod ^ 2) %( n );
    return val;
    
}
//inicia a tablea

void zeraTable(struct tabeltaHash tab) {
    int q;

    for (q = 0; q < tab.tam; q++) {
        tab.x[q].palavra[0] = '$';
    }
}

//busca palavra para ver se é igual

int BuscaPalavra(struct tabeltaHash tab,char *nome, int f) {
    int i = 0;
    for (i = 0; i < 100; i++) {
        if (strcmp(nome, tab.x[f].palavra) == 0) {
            return 0;
        }
        i++;
    }
    return -1;


}
//dobra o valor da variavel global.

int reHash(int tam) {
    int t = 0;
    t = tam;
    tam = t * 2;

    return tam;


}

void ApagaPalavra(struct tabeltaHash  tab,char *p,int f) {
    
    
    int ind = 0;
    int test = 0;
    double fac =0;
    int val=0;
    do {
        val=f;
        test = BuscaPalavra(tabl,p, f);
        if (test == 0) {


            tab.x[f].palavra[0] = '$';
            return;
        } else {
            fac=fac+1;
            tab.fc=fac/tab.tam;
            ind++;
            f = FuncHashLi(val,tab.tam,ind);
        }



   } while (tab.fc < 0.75);
    printf("O resgistro de  '%s' nao foi encontrado!\n", p);
    return;

}

void ImprimeTest(struct tabeltaHash  tab) {
    int i;
    for (i = 0; i < tab.tam; i++) {
        if (tab.x[i].palavra[0] != '$') {
            printf("%d\n", i);
            printf("%s\n", tab.x[i].palavra);
        }
    }

}

int menu(void) {
    int c = 0;
    do {
    
    char p[20];
    char l[20]="-linear";
    char q[20]="-quadratica";
    char d[20]="-hash_duplo";
    char e[20]="-EXIT";
        printf("\t -linear: \n");
        printf("\t -quadratica: \n");
        printf("\t -hash_duplo: \n");
        printf("\t -EXIT\n");

      
    scanf("%s",&p);
    
    
    if (strcmp(p,l) == 0) {
          c=1;  
         
        }
    
    if (strcmp(p,q) == 0) {
          c=2;  
          
        }
    
    if (strcmp(p,d) == 0) {
          c=3;  
          
        }
    
    if (strcmp(p,e) == 0) {
          c=4;  
          
        }
   
        
         
    } while (c <= 0 || c > 4);
    getchar();
    return c;
}

void insereNaHash(struct tabeltaHash  tab,struct tabeltaHash  aux,char *p,int f) {
    int i = 0;
   
    int ind = 0;
    int test = 0;
    double fac =0;
    int val=0;
    do {
        val=f;
        test = BuscaPalavra(tabl,p, f);
        if (test == 0) {
           return;
       }
       if (tab.x[f].palavra[0] == '$') {
           i = 0;

            for (i = 0; i < 100; i++) {
                tab.x[f].palavra[i] = p[i];

           }
            return;
       }else {
            fac=fac+1;
            tab.fc=fac/tab.tam;
            ind=ind+1;
            f = FuncHashLi(val,tab.tam,ind);
        }



    } while (tab.fc < 0.75);
    printf("Deu treta\n");
  
    return;
}

// trasfere para uma hash auxiliar
void transfer(struct tabeltaHash  tab , struct tabeltaHash aux){
    int i;
    aux.tam=tab.tam;
    for(i=0;i<tab.tam;i++){
    aux.x[i]=tab.x[i];
}
}
void reHashComplit(struct tabeltaHash  tab , struct tabeltaHash aux) {
    
    int i = 0;
    int j = 0;
    int f = 0;
    int z=0;
    char p[100];
    int c=0;
    zeraTable(tab);
    
    for (i = 0; i < aux.tam; i++) {

        if (aux.x[i].palavra[0] != '$') {
            for (j = 0; j < 100; j++) {
                p[j] = aux.x[i].palavra[j];

            }
            
            c = rot_hash(p, strlen(p));
            f = FuncHash(c, tab.tam);

            for (z = 0; z < 100; z++) {
                tab.x[f].palavra[z] == aux.x[i].palavra[z];
            }
        }
    }

}