#ifndef _SIM_H_
#define _SIM_H_


#include <stdint.h>

struct stats{
    unsigned long hits_l1; 
    unsigned long misses_l1;
    unsigned long hits_tlb; 
    unsigned long misses_tlb; 
    unsigned long cycles;
};

/** Recebe um traço de endereços de memória acessados e simula hierarquia de memória
  * @param tamanho_bloco tamanho do bloco (32 ou 64 bytes)
  * @param tamanho_cache tamanho da cache de dados (8 ou 16 KiB)
  * @param entradas_tlb número de entradas na TLB (2 ou 4)
  * @param filename nome do arquivo de traço (ou null)
  * @param stream stream com traço (se filename for null)
  * @return estatísticas de simulação
  */

struct stats * sim(int tamanho_bloco, int tamanho_cache, int entradas_tlb, char * filename, char * stream);


#endif // _SIM_H_