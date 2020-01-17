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
public class Animal extends Personagem{

    /**
     *
     * @param nome
     * @param energia
     */
    public Animal(String nome, int energia) {
        super(nome, energia);
    }

    /**
     *
     */
    public void imprimir()
    {
        System.out.println("###########################");
        System.out.println("# Tipo do Personagem: Animal");
        System.out.println("# Nome: "+ pegaNome() );
        System.out.println("# Energia: "+ pegaEnergia() );
        System.out.println("###########################");
    }

    /**
     *
     * @return
     */
    public Alimento morteAlimentar(){
        
            int cap;
            int rest;
            rest=2;
            cap=2;
            String nome= Animal.super.pegaNome();
            String desc= "carne  de "+ Animal.super.pegaNome();
            Alimento carne = new Alimento (nome,desc,cap,rest);
            return carne;
    }
        
    
    
}