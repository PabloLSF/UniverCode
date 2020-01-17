Relatório
Neste projeto foi tomado as seguintes decisões.
       * Para auxiliar a vilualização do andamente do trabalho foi utilizado um tratamento de dados na seguinte ordem.
               1- os dados são lidos e marcados entre leitura 'R' e escritas 'W'
               2- Os dados são convertidos de Hexdecimal para binarios, com intuito de facilitar a vizualização de  tag|indce|offset
               3- os dados são convertidos para decimal para facilitar os calculos
       * Foi utilizado quatro estruturas auxiliares para cada uma das configurções
               1-vetTraco32 que trata block de 32 bytes e Cache de dados: 8 KiB 2-associativa com tempo de acesso de 1 ns
               2-vetTraco32_16 que trata block de 32 bytes  e 16 KiB mapeamento direto com tempo de acesso de 2 ns
               3-vetTraco64 que trata block de 64 bytes  e Cache de dados: 8 KiB 2-associativa com tempo de acesso de 1 ns
               4-vetTraco64_16 que trata block de 64 bytes  e 16 KiB mapeamento direto com tempo de acesso de 2 ns
       *Há 8 casos tratados nos testes um para cada combinação das estruturas com  as TLB: 4 entradas com tempo de acesso de 1 ns ou 8 entradas com tempo de acesso de 2 ns
       *No teste Aluno.c são realizados teste para observar o andamento da função sim.c
               1-saida nula
               2-se os calculos estão sendo executados
               3- comparação de tempo gasto nos ciclos
       *Resultado
               Com base nos 8 teste realizados no Aluno.c, o simulador que seria mais adequado em meu ponto de vista seria o
               de  block de 32 bytes  e 16 KiB mapeamento direto com tempo de acesso de 2 ns com TLB de 8 entradas de 2ns.
               Por ter tempo de ciclo menor que os demais.
               Porem em testes maiores tendo a dizer que block de 64 bytes  e Cache de dados: 8 KiB 2-associativa com tempo de acesso de 1 ns
               com TLB de 8 entradas de 2ns, se sairia melhor sobre as outras por armazenar mais endereços mais acessados reduzindo o numero de misses.
        *Relatorio de Bugs
               Nesta sessão venho relatar os bugs no trabalho
                       - teste 4 não esta rodando.
                       - aquivos muito grandes fazem meus calculos se perderem.
                       - Por vezes na troca de plataforma "SO" e IDEs os valores se alteram.
                       
                       
Nome: Pablo Lameiro Sanches                       
                       