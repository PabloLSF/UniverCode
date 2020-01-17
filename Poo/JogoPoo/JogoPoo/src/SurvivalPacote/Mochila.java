
package SurvivalPacote;

/**
 *
 * @author Pablo
 */
public class Mochila  extends Item{
 private  int AumentaCap;

    /**
     *
     * @param nome
     * @param descricao
     * @param peso
     * @param AumentaCap
     */
    public Mochila(String nome, String descricao,int AumentaCap) {
        super(nome, descricao, 0);
        this.AumentaCap = AumentaCap;
    }
    
    /**
     *
     * @return
     */
    public int aumentarCap(){
     return AumentaCap;
 }
    
}
