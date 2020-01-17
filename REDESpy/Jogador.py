

class Jogador(objetc):

    
     dado
     v=Vivi 
     b=Bob 
     j=Jorjao 
     dano
     sms
     tag
     estado
     caso
     nome
    ler = input("Selecione seu personagem\n1: Jorjão\n2: Vivi\n3: Bob\n")
    ler2 = input("digite seu nome"):
       
        caso=ler
         if caso==1:
                 nome=ler2
                 j= new Jorjao(nome)
                 tag=1
                
        if caso==2: 
                 nome=ler2
                 v= new Vivi(nome)
                 tag=2
                 
        if caso==3:
                 nome=ler2
                 b= new Bob(nome)
                 tag=3
                
       
        
    
    def int rolar(int x):
      
          
        if tag == 1:
         
          if x==1:
        dado=j.atackNomrl()
        dano= j.getDano()
        
         if x==2:
        dado= j.atackRapdo()
        dano= j.getDano()
         if x==3:
        dado= j.atackForte()
        dano= j.getDano()
        if x==4:
        dado= j.rollDef()
        dano=0
        
              
        if tag == 2:
            if x==1:
        dado=v.atackNomrl()
        dano= v.getDano()
        
            if x==2:
        dado= v.atackRapdo()
        dano= v.getDano()
        
            if x== 3:
        dado= v.atackForte()
        dano= v.getDano()
       
            if x== 4:
        dado= v.rollDef()
        dano=0
       
        
        if tag == 3:
            
           if x==  1:
        dado=b.atackNomrl()
        dano= b.getDano()
        
            if x== 2:
        dado= b.atackRapdo()
        dano= b.getDano()
        
            if x==  3:
        dado= b.atackForte()
        dano= b.getDano()
       
            if x== 4:
        dado= b.rollDef()
        dano=0
        break
        
    return dado;   
              
    
    
    def String trollAtack():
        
        s
        ler = input("\nMande sua provacação:\n")
        s = ler
          
          
          if tag ==  1:
        sms=j.provocar(s)
        dano=0
        
          if tag ==  2:
              sms=v.provocar(s)
        dano=0
             
          if tag ==  3:
              sms=b.provocar(s)
        dano=0
              
          
     return sms;
    

    def int getDano():
        return dano
    
    def String getNome(){
         
          
         if tag ==  1:
        sms=j.getNome()
       
        
        if tag ==  2:
              sms=v.getNome()
        
        if tag ==  3:
              sms=b.getNome()
       
              
         
        return sms
    
 def int lose(int dano)
       
          
          if tag ==  1:
        estado=j.levarDano(dano)
       
       
          if tag ==  2:
              estado=v.levarDano(dano)
        
              
          if tag == 3:
              estado=b.levarDano(dano)
       
          
        return estado;
    
 }
