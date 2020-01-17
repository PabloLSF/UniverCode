
import java.util.*;



/**
 *
 * @author Usuario
 */
public class Aula1 {

   
    public static void main(String[] args) {
       
      class Number{
        int numb;
        public boolean trick(){
            int x=1;
            int  trickNum=1;
            while(trickNum < numb){
                x++;
                trickNum=trickNum+x;
            }
            if(trickNum==numb){
                return true;
            }else{
                return false;
            }
        }
        public boolean quad(){
          double squad=  Math.sqrt(numb);
          
          if(squad == Math.floor(squad)){
              
          return true;
          
          }else{
             return false; 
          }
        }
    }
    Number n =new Number();
    n.numb=49;
    System.out.println(n.quad());
}
}