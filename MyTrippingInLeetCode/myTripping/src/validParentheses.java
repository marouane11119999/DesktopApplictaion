import java.util.*;

public class validParentheses {
    public static boolean isValid(String s) {
       HashMap<Character,Character> help=new HashMap<Character, Character>();
       s.replace(" ","");
       help.put('(',')');
       help.put('[',']');
       help.put('{','}');
       int b=0,N=s.length();
       for (int i=0;i<N;i++){
           if (help.containsKey(s.charAt(i))){
               for (int j=i+1;j<N;j++){
                   if(s.charAt(j)==help.get(s.charAt(i))){
                       s=s.substring(0,s.indexOf(s.charAt(j)))+s.substring(s.indexOf(s.charAt(j))+1);
                       N--;
                       b=1;
                       j--;
                   }
                   if(b==1){
                       s=s.substring(0,s.indexOf(s.charAt(i)))+s.substring(s.indexOf(s.charAt(i))+1);
                       N--;
                       b=0;

                   }
               }
           }
       }
       //System.out.println(s)
        if(s.length()!=0) {
            if (!help.containsKey(s.charAt(0))) return false;
            if (s.length() % 2 == 0 && help.containsKey(s.charAt(0))) {
                if (s.charAt(1) != help.get(s.charAt(0))) return false;
            } else if (s.length() % 2 != 0) {
                return false;
            }
        }
       return true;
    }

}
