package SurvivalPacote;


import SurvivalPacote.Command;
import SurvivalPacote.CommandWord;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import static java.lang.Integer.parseInt;
import java.util.ArrayList;


/**
 * Trabalho de Programação Orientada a Objetos, baseado no jogo "World of Zuul", cujo autores e versão constam abaixo:
 * @author  Michael Kolling and David J. Barnes
 * @version 2008.03.30
 */

public class Game 
{
    private Parser parser;
    private Room currentRoom;
    private Jogador hero;
    private ArrayList <Alimento> al = new ArrayList();
    private ArrayList<Animal> a= new ArrayList() ;
    private ArrayList <Sobrevivente> s = new ArrayList();
    private ArrayList <Room> r = new ArrayList();
    private ArrayList <Mochila> b = new ArrayList();
    /**
     * Create the game and initialise its internal map.
     */
    public Game() 
    {
        createRooms();
        parser = new Parser();
        hero = null;
    }
    

    /**
     *
     * @param name
     * @param energy
     * @param loadLimit
     */
    public void createHero(String name, int energy, int loadLimit) {
    		hero = new Jogador(name, energy, loadLimit);
    }
    
    /**
     * Create all the rooms and link their exits together.
     */
    
    private void createRooms()
    {
               File arq = new File("Animal.txt");
               File srq= new File ("Surviveal.txt");
               File rrq= new File ("Local.txt");
               File alrq= new File ("Alimento.txt");
               File brq= new File ("Bag.txt");
    
        int f;
        String nome;
        // create the rooms
        
        try{
        FileReader ler= new FileReader(rrq);
        BufferedReader lerb = new BufferedReader(ler);
        String linha =lerb.readLine();
        while(linha != null){
            
            nome=linha;
            Room l;    
            l=new Room(nome);
            linha =lerb.readLine();
            r.add(l);
                   }
        
    }catch (IOException ex){
        
          }
        // create the animals
        
        try{
        FileReader ler= new FileReader(arq);
        BufferedReader lerb = new BufferedReader(ler);
        String linha =lerb.readLine();
        while(linha != null){
            
            nome=linha;
            Animal l;
            linha =lerb.readLine();      
            f=parseInt( linha);     
            l=new Animal(nome,f);
            linha =lerb.readLine();
            a.add(l);
                   }
        
    }catch (IOException ex){
       
    }
    
        // create the Survival
        
        try{
        FileReader ler= new FileReader(srq);
        BufferedReader lerb = new BufferedReader(ler);
        String linha =lerb.readLine();
        while(linha != null){
            
            nome=linha;
            Sobrevivente l;
            linha =lerb.readLine();      
            f=parseInt( linha);     
            l=new Sobrevivente(nome,f);
            linha =lerb.readLine();
            s.add(l);
                   }
        
    }catch (IOException ex){
       
    }
          // create the bags
          try{
        FileReader ler= new FileReader(brq);
        BufferedReader lerb = new BufferedReader(ler);
        String linha =lerb.readLine();
        while(linha != null){
            String desc;
            nome=linha;
            Mochila l;
            linha =lerb.readLine(); 
            desc=linha;
            linha =lerb.readLine();
            f=parseInt( linha);     
            l=new Mochila(nome,desc,f);
            linha =lerb.readLine();
            b.add(l);
                   }
        
    }catch (IOException ex){
       
    }
        // create the food
        
        try{
        FileReader ler= new FileReader(alrq);
        BufferedReader lerb = new BufferedReader(ler);
        String linha =lerb.readLine();
        while(linha != null){
            String desc;
            int ener;
            nome=linha;
            Alimento l;
            linha =lerb.readLine();
            desc=nome;
            linha =lerb.readLine();
            f=parseInt( linha);  
            linha =lerb.readLine();
            ener=parseInt( linha);
            l=new Alimento(nome,desc,f,ener);
            linha =lerb.readLine();
            al.add(l);                
                   }
        
    }catch (IOException ex){
        
    }
        
        
       
      
        
        
        // initialise room exits
        r.get(0).setExit("south", r.get(1));
        
        r.get(1).setExit("west", r.get(2));
        r.get(1).setExit("north", r.get(0));
        r.get(1).setExit("east", r.get(3));
        r.get(1).setExit("south", r.get(4));
        
        r.get(2).setExit("east",r.get(1));
        
        r.get(3).setExit("west", r.get(1));
        r.get(3).setExit("south", r.get(5));
        
        r.get(5).setExit("north", r.get(3));
        r.get(5).setExit("south", r.get(6));
        
        r.get(6).setExit("north", r.get(5));
        r.get(6).setExit("west", r.get(7));
        
        r.get(4).setExit("north", r.get(1));
        r.get(4).setExit("south", r.get(7));
        
        r.get(7).setExit("north", r.get(4));
        r.get(7).setExit("west", r.get(8));
        r.get(7).setExit("east", r.get(6));
        
        r.get(8).setExit("east", r.get(7));
        r.get(8).setExit("west", r.get(9));
        
        r.get(9).setExit("west", r.get(8));
        
        
        //add survival
        r.get(5).addCharacter(s.get(0));
        r.get(4).addCharacter(s.get(1));
        r.get(7).addCharacter(s.get(2));
        //add animals
        r.get(2).addAimal(a.get(0));
        r.get(8).addAimal(a.get(1));
        r.get(6).addAimal(a.get(2));
        r.get(3).addAimal(a.get(3));
        
        // add Food
        r.get(1).addAlimento(al.get(1));
        r.get(5).addAlimento(al.get(0));
        r.get(4).addAlimento(al.get(2));
        // add bags
        r.get(0).addMochila(b.get(0));
        r.get(5).addMochila(b.get(1));
        
        
        

        currentRoom = r.get(0);  // start game outside
    }

    /**
     *  Main play routine.  Loops until end of play.
     */
    public void play() 
    {            
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
         if(currentRoom==r.get(9)){                
            
                System.out.println("Você esta fugindo com vida dessa cidade em ruinas");
                System.exit(0);
            }
         if(hero.pegaEnergia()==0){
                
               System.out.println("Você Morreu e virou uma carne podre");
               System.exit(0);
            }
        
        boolean finished = false;
        while (! finished) {
           if(currentRoom==r.get(9)){                
            
                System.out.println("Você esta fugindo com vida dessa cidade em ruinas");
                System.exit(0);
            }
         if(hero.pegaEnergia()==0){
                
               System.out.println("Você Morreu e virou uma carne podre");
               System.exit(0);
            }
               
          
            Command command = parser.getCommand();
            finished = processCommand(command);
            
             
        }
        System.out.println("Obrigado por jogar. Até a próxima pessoal!");
    }

    /**
     * Print out the opening message for the player.
     */
    private void printWelcome()
    {
        System.out.println();
        System.out.println("Bem vindo a Water in desert");
        System.out.println("\"Water in Desert\" é um jogo desenvolvido para o trabalho de Programação orientada a objetos");
        System.out.println("Digite '" + CommandWord.HELP + "' se precisar de ajuda com os comandos.");
        System.out.println();
        System.out.println(currentRoom.getLongDescription());
    }

    /**
     * Given a command, process (that is: execute) the command.
     * @param command The command to be processed.
     * @return true If the command ends the game, false otherwise.
     */
    private boolean processCommand(Command command) 
    {
        boolean wantToQuit = false;

        CommandWord commandWord = command.getCommandWord();

        if(commandWord == CommandWord.UNKNOWN) {
            System.out.println("Não entendi oquê você quis dizer...");
            return false;
        }

        if (commandWord == CommandWord.HELP) {
            printHelp();
        }
        else if (commandWord == CommandWord.GO) {
            goRoom(command);
        }
        else if (commandWord == CommandWord.QUIT) {
            wantToQuit = quit(command);
        }
        else if (commandWord == CommandWord.LOOK) {
            System.out.println();
            System.out.println(currentRoom.getLongDescription());
            hero.imprimir();
        }
        else if (commandWord == CommandWord.ATTACK) {
            attackVillain(command);
        }
         else if (commandWord == CommandWord.PICK) {
            pickItem(command);
        }
        else if (commandWord == CommandWord.USE) {
            comer(command);
        }
        else if (commandWord == CommandWord.DROP) {
            dropItem(command);
        }
        // else command not recognised.
        return wantToQuit;
    }

    // implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
    private void printHelp() 
    {
        System.out.println("Você está perdido. Você está sozinho. Você está vagando pela Cidade em Ruinas!");
        System.out.println();
        System.out.println("Seus comandos estão a seguir:");
        parser.showCommands();
    }

    /** 
     * Try to go to one direction. If there is an exit, enter the new
     * room, otherwise print an error message.
     */
    private void goRoom(Command command) 
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Ir para onde?");
            return;
        }

        String direction = command.getSecondWord();

        // Try to leave current room.
        Room nextRoom = currentRoom.getExit(direction);

        if (nextRoom == null) {
            System.out.println("Não há nenhuma porta!");
        }
        else {
            currentRoom = nextRoom;
            System.out.println(currentRoom.getLongDescription());
        }
    }
    private void pickItem(Command command){
         if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Que item Voce quer pegar?");
            return;
        }
   String name = command.getSecondWord();
        
        Alimento item = currentRoom.getAlimento(name);
        Mochila itens= currentRoom.getMochila(name);
        
        if (item == null && itens == null) {
            System.out.println("Você está certo de que este é o nome?");
            return;
        } else {
            if(item != null){
            hero.adicionaItem(item);
            currentRoom.removeAlimento(name);
        }
         if (itens != null) {
         
             hero.adicionaMOchila(itens);
            currentRoom.removeMochila(name);
        }
    }
    }
    private void dropItem(Command command){
         if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Que item Voce quer pegar?");
            return;
        }
   String alimento = command.getSecondWord();
   
   if (alimento == null   || hero.buscarAlimento(alimento)==null) {
            System.out.println("Está certo de que este é o nome?");
            return;
        } else {
            
            
            Alimento drops=hero.buscarAlimento(alimento);
            currentRoom.addAlimento(drops);
            hero.removeItem(alimento);
        }
   
    }
        private void comer(Command command) 
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("oque você quer comer?");
            return;
        }

        String name = command.getSecondWord();
         if (name == null   || hero.buscarAlimento(name)==null){
            System.out.println("está certo de que este é o nome?");
            return;
        } else {
            hero.alimentarJOgador(name);
            hero.removeItem(name);
          
        }
    }

        private void attackVillain(Command command) 
    {
      
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Atacar quem?");
            return;
        }

        String name = command.getSecondWord();
        
        Sobrevivente villain = currentRoom.getCharacter(name);
        Animal animal = currentRoom.getAnimal(name);
        if (villain == null && animal == null ) {
            System.out.println("Está certo de que este é o nome?");
            return;
        } else {
            if(villain != null){
            if(villain.pegaEnergia()>0){
                 
        		hero.lutar(villain);
        		hero.imprimir();
        		villain.imprimir();
                  }
            else{
                System.out.println("Sobrevivente morreu");
                currentRoom.removeCharacter(name);
            }
        }
            if(animal != null)
              if(animal.pegaEnergia()>0){
            
        		hero.lutar(animal);
        		hero.imprimir();
        		animal.imprimir();
                    }
            else {
                System.out.println("Animal viro carne ");
                        Alimento food= animal.morteAlimentar();
                      currentRoom.addAlimento(food);
                     
                     currentRoom.removeAnimal(name);
                   
            }
        }
        
    }
    
    /** 
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game.
     * @return true, if this command quits the game, false otherwise.
     */
    private boolean quit(Command command) 
    {
        if(command.hasSecondWord()) {
            System.out.println("Sair do quê?");
            return false;
        }
        else {
            return true;  // signal that we want to quit
        }
    }

    //-----------------------------------------------------------------------------------------------------
    // Metodo main para execucao do programa

    /**
     *
     * @param args
     */
        public static void main(String[] args)
    {
    		Game game = new Game();
    		game.createHero("Carlos", 7, 20);
    		game.play();
    }
    
}
