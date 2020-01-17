
package SurvivalPacote;

/**
 *
 * @author Usuário
 */
public class Alimento extends Item{
 private int alimentar;

    /**
     *
     * @param nome
     * @param descricao
     * @param peso
     * @param alimentar
     */
    public Alimento(String nome, String descricao, int peso, int alimentar) {
        super(nome, descricao, peso);
        this.alimentar=alimentar;
    }
    
    /**
     *
     * @return
     */
    public int alimentarJogador(){
     return alimentar;
  }
  }  
    
    

