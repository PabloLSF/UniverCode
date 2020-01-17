package SurvivalPacote;
import java.util.ArrayList;

/**
 *
 * @author Pablo Sanchez, Henrique Saenger e Pedro Monsalve
 */
public class Jogador extends Personagem  {
    
private ArrayList<Alimento> inventario;
private ArrayList<Mochila> bag;

    private int limiteDePeso;
    
    /**
     *
     * @param nome
     * @param energia
     * @param limiteDePeso
     */
    public Jogador(String nome, int energia,int limiteDePeso ) {
        super(nome, energia);
  inventario = new ArrayList<Alimento> ();
  bag= new ArrayList<Mochila>();
        this.limiteDePeso = limiteDePeso;  
    }

    /**
     *
     */
    public void imprimir()
    {
        System.out.println("###########################");
        System.out.println("# Tipo do Personagem: Heroi");
        System.out.println("# Nome: "+ pegaNome() );
        System.out.println("# Energia: "+ pegaEnergia() );
        imprimeBags();
        imprimeFood();
        System.out.println("###########################");
    }
    private void imprimeBags(){
        System.out.println("# Inventário: ");
        for(int i = 0; i<bag.size();i++){
            System.out.println(bag.get(i).pegaNome());
            
        }
        
    }
    private void imprimeFood(){
        System.out.println("# Comida no inventário: ");
        for(int i = 0; i<inventario.size();i++){
            System.out.println(inventario.get(i).pegaNome());
            
        }
        
    }
   
    /**
     *
     * @param oponente
     */
    public void lutar(Personagem oponente)
    {
        int dadoPersonagem = sorte();
        int dadoOponente = oponente.sorte();
        
 
        if (dadoPersonagem == dadoOponente) {
            decremento();
            oponente.decremento();
        } else if (dadoPersonagem > dadoOponente) {
           
            oponente.decremento();
        } else {
            decremento();
            
        }
        
    }

    /**
     *
     * @param item
     */
    public void adicionaItem(Alimento item)
    {
    		if (calcularPeso() + item.pegaPeso() <= limiteDePeso)
    			inventario.add(item);
    		else
    			System.out.println("O heroi '"+pegaNome()+"' não pode carregar mais itens!");
    }

    /**
     *
     * @param nomeItem
     */
    public void removeItem(String nomeItem)
    {
    		Alimento item = buscarAlimento(nomeItem);
    		if (item != null)
    			inventario.remove(item);
    		else
    			System.out.println("O item '"+nomeItem+"' nao existe no inventario do heroi!");
    }

    /**
     *
     * @param nomeItem
     */
    public void alimentarJOgador(String nomeItem){
        Alimento item = buscarAlimento(nomeItem);
        for(int i=0; i < item.alimentarJogador(); i++){
            Jogador.super.alimentar();
        }       
    }
    
    /**
     *
     * @return
     */
    public int calcularPeso()
    {
    		int carga = 0;
    		for (Item item : inventario)
    		{
    			carga += item.pegaPeso();
    		}
    		return carga;
    }
    
    public Alimento buscarAlimento(String nomeItem)
    {
    		for (Alimento item : inventario)
    		{
    			if (item.pegaNome().equals(nomeItem))
    				return item;
    		}
    		return null;
    }

    /**
     *
     * @param item
     */
    public void adicionaMOchila(Mochila item){
        bag.add(item);
        limiteDePeso = limiteDePeso+ item.aumentarCap();
    }
}