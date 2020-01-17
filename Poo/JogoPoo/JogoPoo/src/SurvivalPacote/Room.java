package SurvivalPacote;
import java.util.Set;
import java.util.HashMap;
import java.util.Iterator;
import java.lang.StringBuffer;

/**
 * Class Room - a room in an adventure game.
 *
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 *
 * A "Room" represents one location in the scenery of the game.  It is 
 * connected to other rooms via exits.  For each existing exit, the room 
 * stores a reference to the neighboring room.
 * 
 * @author  Michael Kolling and David J. Barnes
 * @version 2008.03.30
 */

public class Room 
{
    private String description;
    private HashMap<String, Room> exits;        // stores exits of this room.
    private HashMap<String, Mochila> mochilas;   
    private HashMap<String, Alimento> alimentos; // stores exits of this room.
    private HashMap<String, Sobrevivente> sobreviventes;
     private HashMap<String,Animal> animais;// stores exits of this room.

    /**
     * Create a room described "description". Initially, it has
     * no exits. "description" is something like "a kitchen" or
     * "an open court yard".
     * @param description The room's description.
     */
    public Room(String description) 
    {
        this.description = description;
        exits = new HashMap<String, Room>();
        alimentos = new HashMap<String, Alimento>();
        mochilas = new HashMap<String, Mochila>();
        sobreviventes = new HashMap<String, Sobrevivente>();
        animais = new HashMap<String, Animal>();
    }

    /**
     * Define an exit from this room.
     * @param direction The direction of the exit.
     * @param neighbor  The room to which the exit leads.
     */
    public void setExit(String direction, Room neighbor) 
    {
        exits.put(direction, neighbor);
    }

    /**
     * @return The short description of the room
     * (the one that was defined in the constructor).
     */
    public String getShortDescription()
    {
        return description;
    }

    /**
     * Return a description of the room in the form:
     *     You are in the kitchen.
     *     Exits: north west
     * @return A long description of this room
     */
    public String getLongDescription()
    {
        StringBuffer description = new StringBuffer();
    		description.append("Você está no(a) " + this.description + ".\n");
    		description.append(getExitString() + "\n");
    		
    		description.append("-- Outros Sobreviventes: ");
    		for (String name : sobreviventes.keySet())
    			description.append(name+", ");
                description.append("\n-- Animais: ");
    		for (String name : animais.keySet())
    			description.append(name+", ");
        
    		description.append("\n-- Comida no recinto: ");
    		for (String name : alimentos.keySet())
    			description.append(name+", ");
                
                description.append("\n-- Bags no local: ");
    		for (String name : mochilas.keySet())
    			description.append(name+", ");
        
    		description.append("\n");
    		
    		return description.toString();
    }

    /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * @return Details of the room's exits.
     */
    private String getExitString()
    {
        String returnString = "Exits:";
        Set<String> keys = exits.keySet();
        for(String exit : keys) {
            returnString += " " + exit;
        }
        return returnString;
    }

    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     * @param direction The exit's direction.
     * @return The room in the given direction.
     */
    public Room getExit(String direction) 
    {
        return exits.get(direction);
    }
    
    /**
     *
     * @param item
     */
    public void addMochila(Mochila item)
    {
    		mochilas.put(item.pegaNome(), item);
    }
    
    /**
     *
     * @param itemName
     */
    public void removeMochila(String itemName)
    {
    		mochilas.remove(itemName);
    }

    /**
     *
     * @param item
     */
    public void addAlimento(Alimento item)
    {
    		alimentos.put(item.pegaNome(),item);
    }
   
    /**
     *
     * @param itemName
     */
    public void removeAlimento(String itemName)
    {
    		alimentos.remove(itemName);
    }
    
    /**
     *
     * @param sobrevivente
     */
    public void addCharacter(Sobrevivente sobrevivente)
    {
    		sobreviventes.put(sobrevivente.pegaNome(), sobrevivente);
                
    }
      public void addAimal(Animal sobrevivente)
    {
    		animais.put(sobrevivente.pegaNome(), sobrevivente);
                
    }
    
    /**
     *
     * @param name
     */
    public void removeCharacter(String name)
    {
    		sobreviventes.remove(name);
    }
public void removeAnimal(String name)
    {
    		animais.remove(name);
    }
    /**
     *
     * @param name
     * @return
     */
    public Sobrevivente getCharacter(String name) 
    {
        return sobreviventes.get(name);
    }
    public Animal getAnimal(String name) 
    {
        return animais.get(name);
    }
    
    public Alimento getAlimento(String name){
        return alimentos.get(name);
    }
     public Mochila getMochila (String name){
        return mochilas.get(name);
    }
}