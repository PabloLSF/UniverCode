package SurvivalPacote;
import java.util.Random;

/**
 *
 * @author Pablo 
 */
public class Personagem {
     private static final int ENERGIA_MAXIMA = 10;
    private String nome;
    private int energia;
    private Random dado;

    /**
     *
     * @param nome
     * @param energia
     */
    public Personagem(String nome, int energia)
    {
        this.nome = nome;
        this.energia = energia;
        this.dado = new Random();
    }

    /**
     *
     * @return
     */
    public int pegaEnergia()
    {
        return energia;
    }
    
    /**
     *
     * @return
     */
    public String pegaNome()
    {
        return nome;
    }
    
    /**
     *
     */
    public void incremento()
    {
        if (energia < ENERGIA_MAXIMA)
            energia++;
    }
    
    /**
     *
     */
    public void decremento()
    {
        if ( energia > 0 )
            energia--;
        if (energia == 0)
            System.out.println(nome + " esta morto!");
    }
    
    /**
     *
     */
    public void alimentar()
    {
        incremento();
    }
    
    /**
     *
     */
    public void imprimir()
    {
        System.out.println("#####################");
        System.out.println("# Nome: "+ nome);
        System.out.println("# Energia: "+ energia);
        System.out.println("#####################");
    }
    
    /**
     *
     * @return
     */
    public int sorte()
    {
        return dado.nextInt(6) + 1;
    }

    /**
     *
     * @param limite
     * @return
     */
    public int sorte(int limite)
    {
        return dado.nextInt(limite) + 1;
    }

    /**
     *
     * @param min
     * @param max
     * @return
     */
    public int sorte(int min, int max)
    {
        return dado.nextInt(max - min + 1) + min;
    }

   
   
}
 
    

