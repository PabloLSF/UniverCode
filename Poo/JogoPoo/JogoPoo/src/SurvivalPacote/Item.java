package SurvivalPacote;

/**
 *
 * @author Usuário
 */
public class Item {
	private String nome;
	private String descricao;
	private int peso;
	
    /**
     *
     * @param nome
     * @param descricao
     * @param peso
     */
    public Item (String nome, String descricao, int peso)
	{
		this.nome = nome;
		this.descricao = descricao;
		this.peso = peso;
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
     * @return
     */
    public String pegaDescricao()
	{
		return descricao;
	}
	
    /**
     *
     * @return
     */
    public int pegaPeso()
	{
		return peso;
	}

}
