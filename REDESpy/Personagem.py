
 class Personagem(object):

   
     hp;
     nome;
    
    def   setHp(int y):
    
       
        hp=y;
    
    def     int getHp():
    
        
        return hp;
    
    def setNome( y):
    
        
        nome=y;
    
     def getNome():
    
        
        return nome;
    
    def levarDano(int dano):
        hp=hp-dano;
        if hp<=0:
            return 0
        else:
            return 1;
        
    

