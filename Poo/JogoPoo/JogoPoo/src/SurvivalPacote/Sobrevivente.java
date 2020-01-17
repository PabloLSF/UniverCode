/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SurvivalPacote;

/**
 *
 * @author Usuário
 */
public class Sobrevivente extends Personagem{

    /**
     *
     * @param nome
     * @param energia
     */
    public Sobrevivente(String nome, int energia) {
        super(nome, energia);
    }

    /**
     *
     */
    public void imprimir()
    {
        System.out.println("###########################");
        System.out.println("# Tipo do Personagem: Sobrevivente");
        System.out.println("# Nome: "+ pegaNome() );
        System.out.println("# Energia: "+ pegaEnergia() );
        System.out.println("###########################");
    }
    
    
}
